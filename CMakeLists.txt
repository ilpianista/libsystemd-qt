project(libsystemd-qt)

cmake_minimum_required(VERSION 2.8.8)

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

pkg_check_modules(SYSTEMD "libsystemd-daemon libsystemd-login" REQUIRED)

IF(NOT SYSTEMD_FOUND)
    message(FATAL_ERROR "ERROR: Systemd not found")
ENDIF(NOT SYSTEMD_FOUND)

cmake_dependent_option(BUILD_QTSYSTEMD_TESTS "Build Tests" ON "Qt5Core_DIR" OFF)

add_subdirectory(src)
if (BUILD_QTSYSTEMD_TESTS)
    add_subdirectory(tests)
endif (BUILD_QTSYSTEMD_TESTS)

# create a Config.cmake and a ConfigVersion.cmake file and install them
set(CMAKECONFIG_INSTALL_DIR "${INSTALL_LIB_DIR}/cmake/QtSystemd")

include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/QtSystemdConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/QtSystemdConfig.cmake"
  INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
  PATH_VARS CMAKE_INSTALL_PREFIX
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/QtSystemdConfig.cmake"
  DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
  COMPONENT Devel
)

install(EXPORT QtSystemdTargets DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE QtSystemdTargets.cmake)
