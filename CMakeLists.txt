project(libsystemd-qt)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt4 REQUIRED)
find_package(PkgConfig)

set(LIB_SUFFIX "" CACHE STRING "Define suffix of library directory name (32/64)" )

pkg_check_modules(SYSTEMD "systemd" REQUIRED)

if (NOT SYSTEMD_FOUND)
    message(FATAL_ERROR "ERROR: Systemd not found")
endif (NOT SYSTEMD_FOUND)

include_directories(${QT_INCLUDES}
                    ${CMAKE_CURRENT_SOURCE_DIR}/dbus
                    ${CMAKE_CURRENT_BUILD_DIR})

add_subdirectory(dbus)

set(QtSystemd_HEADERS
)

set(QtSystemd_PART_SRCS
)

set(DBUS_INTERFACE_SRCS
)

add_library(QtSystemd SHARED ${QtSystemd_PART_SRCS} ${DBUS_INTERFACE_SRCS})

target_link_libraries(QtSystemd ${QT_QTCORE_LIBRARY} ${QT_QTDBUS_LIBRARY})
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
