project(libsystemd-qt)

cmake_minimum_required(VERSION 2.8.8)

set(QTSYSTEMD_MAJOR_VERSION 0)
set(QTSYSTEMD_MINOR_VERSION 1)
set(QTSYSTEMD_PATCH_VERSION 0)
set(QTSYSTEMD_VERSION
  ${QTSYSTEMD_MAJOR_VERSION}.${QTSYSTEMD_MINOR_VERSION}.${QTSYSTEMD_PATCH_VERSION})

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(CMakeDependentOption)

option(BUILD_WITH_QT4 "Build with Qt4 no matter if Qt5 is found" OFF)

if( NOT BUILD_WITH_QT4 )
    find_package(Qt5Core QUIET)
    if( Qt5Core_DIR )
        message(STATUS "Found Qt5!")

        macro(qt_wrap_cpp)
            qt5_wrap_cpp(${ARGN})
        endmacro()

        find_package(Qt5DBus REQUIRED)
        macro(qt_add_dbus_interfaces)
            qt5_add_dbus_interfaces(${ARGN})
        endmacro()
    endif()
endif()

if( NOT Qt5Core_DIR )
    message(STATUS "Could not find Qt5, searching for Qt4 instead...")
    message(STATUS "Be aware that Qt4 support is not officially supported!")
    find_package( Qt4 COMPONENTS QtCore QtDBus REQUIRED )
    include( ${QT_USE_FILE} )

    macro(qt5_use_modules)
    endmacro()

    macro(qt_wrap_cpp)
        qt4_wrap_cpp(${ARGN})
    endmacro()

    macro(qt_add_dbus_interfaces)
        qt4_add_dbus_interfaces(${ARGN})
    endmacro()
endif()

find_package(PkgConfig)

pkg_check_modules(SYSTEMD "libsystemd-daemon libsystemd-login" REQUIRED)
IF(NOT SYSTEMD_FOUND)
    message(FATAL_ERROR "ERROR: Systemd not found")
ENDIF(NOT SYSTEMD_FOUND)

set(LIB_SUFFIX "" CACHE STRING
    "Define suffix of library directory name (32/64)")

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib${LIB_SUFFIX} CACHE PATH
    "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR include/QtSystemd CACHE PATH
    "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/cmake/QtSystemd)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
    "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

add_subdirectory(src)

cmake_dependent_option(BUILD_QTSYSTEMD_TESTS "Build Tests" ON "Qt5Core_DIR" OFF)
if (BUILD_QTSYSTEMD_TESTS)
    add_subdirectory(tests)
endif (BUILD_QTSYSTEMD_TESTS)

# Add all targets to the build-tree export set
export(TARGETS QtSystemd FILE "${PROJECT_BINARY_DIR}/QtSystemdTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE QtSystemd)

# Create the QtSystemdConfig.cmake and QtSystemdConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(QtSystemdConfig.cmake.in
  "${PROJECT_BINARY_DIR}/QtSystemdConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${QTSYSTEMD_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(QtSystemdConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/QtSystemdConfig.cmake" @ONLY)
# ... for both
configure_file(QtSystemdConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/QtSystemdConfigVersion.cmake" @ONLY)

# Install the QtSystemdConfig.cmake and QtSystemdConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/QtSystemdConfig.cmake"
  "${PROJECT_BINARY_DIR}/QtSystemdConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT QtSystemdTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)

message(STATUS "Writing pkg-config file...")
configure_file(${CMAKE_SOURCE_DIR}/QtSystemd.pc.cmake ${CMAKE_BINARY_DIR}/QtSystemd.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/QtSystemd.pc DESTINATION "${INSTALL_LIB_DIR}/pkgconfig/")
