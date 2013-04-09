set_source_files_properties(${INTERFACE_INTROSPECTION_XML_FILES}
                            PROPERTIES NO_NAMESPACE TRUE)

set(INTERFACE_INTROSPECTION_XML_FILES
    introspection/org.freedesktop.hostname1.xml
    introspection/org.freedesktop.locale1.xml
    introspection/org.freedesktop.login1.Seat.xml
    introspection/org.freedesktop.login1.Session.xml
    introspection/org.freedesktop.login1.User.xml
    introspection/org.freedesktop.systemd1.Automount.xml
    introspection/org.freedesktop.systemd1.Device.xml
    introspection/org.freedesktop.systemd1.Job.xml
    introspection/org.freedesktop.systemd1.Manager.xml
    introspection/org.freedesktop.systemd1.Mount.xml
    introspection/org.freedesktop.systemd1.Path.xml
    introspection/org.freedesktop.systemd1.Service.xml
    introspection/org.freedesktop.systemd1.Snapshot.xml
    introspection/org.freedesktop.systemd1.Socket.xml
    introspection/org.freedesktop.systemd1.Swap.xml
    introspection/org.freedesktop.systemd1.Target.xml
    introspection/org.freedesktop.systemd1.Timer.xml
    introspection/org.freedesktop.systemd1.Unit.xml
    introspection/org.freedesktop.timedate1.xml
    )

find_package(Qt4 COMPONENTS QTDBUS)
# this one conflicts with systemd1.Manager, so set the name manually
qt4_add_dbus_interface(QtSystemd_PART_SRCS introspection/org.freedesktop.login1.Manager.xml
                       ldmanagerinterface)
qt4_add_dbus_interfaces(QtSystemd_PART_SRCS ${INTERFACE_INTROSPECTION_XML_FILES})
