project(libsystemd-qt)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(PkgConfig)

set(LIB_SUFFIX "" CACHE STRING "Define suffix of library directory name (32/64)" )

pkg_check_modules(SYSTEMD "systemd" REQUIRED)

if (NOT SYSTEMD_FOUND)
    message(FATAL_ERROR "ERROR: Systemd not found")
endif (NOT SYSTEMD_FOUND)

include_directories(${Qt5Core_INCLUDE_DIRS}
                    ${Qt5DBus_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}/dbus
                    ${CMAKE_CURRENT_BUILD_DIR})

#add_subdirectory(dbus)

set(QtSystemd_HEADERS
    job.h
    ldmanager.h
    sdmanager.h
    unit.h
    dbus/generic-types.h
    QtSystemd-export.h
)

set(QtSystemd_PRIVATE_HEADERS
    ldmanager_p.h
    sdmanager_p.h
)

set(QtSystemd_PART_SRCS
    job.cpp
    ldmanager.cpp
    sdmanager.cpp
    unit.cpp
    dbus/generic-types.cpp
)

set(DBUS_INTERFACE_SRCS
    dbus/automountinterface.cpp
    dbus/deviceinterface.cpp
    dbus/hostname1interface.cpp
    dbus/jobinterface.cpp
    dbus/locale1interface.cpp
    dbus/login1interface.cpp
    dbus/managerinterface.cpp
    dbus/mountinterface.cpp
    dbus/pathinterface.cpp
    dbus/serviceinterface.cpp
    dbus/snapshotinterface.cpp
    dbus/socketinterface.cpp
    dbus/swapinterface.cpp
    dbus/targetinterface.cpp
    dbus/timedate1interface.cpp
    dbus/timerinterface.cpp
    dbus/unitinterface.cpp
)

add_library(QtSystemd SHARED ${QtSystemd_PART_SRCS} ${DBUS_INTERFACE_SRCS})

target_link_libraries(QtSystemd ${Qt5Core_LIBRARIES} ${Qt5DBus_LIBRARIES})
install(TARGETS QtSystemd DESTINATION lib${LIB_SUFFIX})

install( FILES
   ${QtSystemd_HEADERS}
   DESTINATION
   include/QtSystemd COMPONENT Devel)

set_property(TARGET QtSystemd PROPERTY COMPILE_DEFINITIONS MAKE_SDQT_LIB)
set_property(TARGET QtSystemd PROPERTY VERSION ${VERSION})
set_property(TARGET QtSystemd PROPERTY SOVERSION 0)

message(STATUS "Writing pkg-config file...")
configure_file(${CMAKE_SOURCE_DIR}/QtSystemd.pc.cmake ${CMAKE_BINARY_DIR}/QtSystemd.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/QtSystemd.pc DESTINATION "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig/")

add_subdirectory(tests)