project(libsystemd-qt)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(PkgConfig)

set(LIB_SUFFIX "" CACHE STRING "Define suffix of library directory name (32/64)")

pkg_check_modules(SYSTEMD "systemd" REQUIRED)

IF(NOT SYSTEMD_FOUND)
    message(FATAL_ERROR "ERROR: Systemd not found")
ENDIF(NOT SYSTEMD_FOUND)

add_subdirectory(src)
add_subdirectory(tests)
