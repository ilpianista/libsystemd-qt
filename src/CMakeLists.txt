set(QtSystemd_HEADERS
    generic-types.h
    job.h
    ldmanager.h
    sdmanager.h
    seat.h
    unit.h
    QtSystemd-export.h
)

set(QtSystemd_PART_SRCS
    generic-types.cpp
    job.cpp
    ldmanager.cpp
    sdmanager.cpp
    seat.cpp
    unit.cpp
)

set(INTERFACE_INTROSPECTION_XML_FILES
    dbus/org.freedesktop.hostname1.xml
    dbus/org.freedesktop.locale1.xml
    dbus/org.freedesktop.login1.LDManager.xml
    dbus/org.freedesktop.login1.Seat.xml
    dbus/org.freedesktop.login1.Session.xml
    dbus/org.freedesktop.login1.User.xml
    dbus/org.freedesktop.systemd1.Automount.xml
    dbus/org.freedesktop.systemd1.Device.xml
    dbus/org.freedesktop.systemd1.Job.xml
    dbus/org.freedesktop.systemd1.Manager.xml
    dbus/org.freedesktop.systemd1.Mount.xml
    dbus/org.freedesktop.systemd1.Path.xml
    dbus/org.freedesktop.systemd1.Service.xml
    dbus/org.freedesktop.systemd1.Snapshot.xml
    dbus/org.freedesktop.systemd1.Socket.xml
    dbus/org.freedesktop.systemd1.Swap.xml
    dbus/org.freedesktop.systemd1.Target.xml
    dbus/org.freedesktop.systemd1.Timer.xml
    dbus/org.freedesktop.systemd1.Unit.xml
    dbus/org.freedesktop.timedate1.xml
    )

set_property(SOURCE ${INTERFACE_INTROSPECTION_XML_FILES}
             PROPERTY INCLUDE generic-types.h)

set_source_files_properties(${INTERFACE_INTROSPECTION_XML_FILES}
                            PROPERTIES NO_NAMESPACE TRUE)

find_package(Qt4 COMPONENTS QTDBUS)
qt4_add_dbus_interfaces(QtSystemd_PART_SRCS ${INTERFACE_INTROSPECTION_XML_FILES})

add_library(QtSystemd SHARED ${QtSystemd_PART_SRCS})

qt5_use_modules(QtSystemd Core DBus)

install(TARGETS QtSystemd
        DESTINATION lib${LIB_SUFFIX})

install(FILES ${QtSystemd_HEADERS}
        DESTINATION include/QtSystemd
        COMPONENT Devel)

set_property(TARGET QtSystemd PROPERTY COMPILE_DEFINITIONS MAKE_SDQT_LIB)
set_property(TARGET QtSystemd PROPERTY VERSION ${VERSION})
set_property(TARGET QtSystemd PROPERTY SOVERSION 0)

message(STATUS "Writing pkg-config file...")
configure_file(${CMAKE_SOURCE_DIR}/QtSystemd.pc.cmake ${CMAKE_BINARY_DIR}/QtSystemd.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/QtSystemd.pc DESTINATION "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig/")

add_subdirectory(qmlplugin)
