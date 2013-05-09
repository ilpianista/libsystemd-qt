project(libsystemd-qt)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(PkgConfig)

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib${LIB_SUFFIX} CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/QtSystemd)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()


set(LIB_SUFFIX "" CACHE STRING "Define suffix of library directory name (32/64)")

set(QT5_IMPORTS_DIR "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/qt/imports" CACHE STRING "Define the Qt5 imports dir path")

pkg_check_modules(SYSTEMD "libsystemd-daemon libsystemd-login" REQUIRED)

IF(NOT SYSTEMD_FOUND)
    message(FATAL_ERROR "ERROR: Systemd not found")
ENDIF(NOT SYSTEMD_FOUND)

option(BUILD_QTSYSTEMD_QMLPLUGIN "Build Qml plugin" ON)
option(BUILD_QTSYSTEMD_TESTS "Build Tests" ON)

add_subdirectory(src)
if (BUILD_QTSYSTEMD_QMLPLUGIN)
    add_subdirectory(qmlplugin)
endif (BUILD_QTSYSTEMD_QMLPLUGIN)
if (BUILD_QTSYSTEMD_TESTS)
    add_subdirectory(tests)
endif (BUILD_QTSYSTEMD_TESTS)

# CMake Config Logic
# Add all targets to the build-tree export set
export(TARGETS QtSystemd
  FILE "${PROJECT_BINARY_DIR}/QtSystemdTargets.cmake")

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
