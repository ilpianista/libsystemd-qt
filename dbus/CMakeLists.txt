# Steps to generate the dbus interface files
# 1) Place the Systemd introspection dbus xml in introspection/
# 2) Update the list of xml files below that we want to generate interfaces for
# 3) Enable dbus subdirectory in ../CMakeLists.txt
#    Make, in order to generate the interface sources
# 3.1) Add annotations to the xml so qdbusxml2cpp knows what type or typedef to use
#      Add typedefs as needed to generic-types.h
# 4)   Add the list of generated files needed for the plugin to FILES_TO_BUILD
# 6) Copy the working generated interface sources into the source dir
# 5) Edit the sources as required to get them to build
# 5.1) Fix the inclusion guards as the compiler ignores anything after a '-' so the compiler thinks
#      headers have already been included
# Run do-hand-edits to update the diff of the interfaces vs what is generated; this speeds up regenerating them since you just have to apply the diff to make them compile

# Just the hardware related files to begin with, as these are already present in Solid

set( INTERFACE_INTROSPECTION_XML_FILES
     introspection/org.freedesktop.hostname1.xml
     introspection/org.freedesktop.locale1.xml
     introspection/org.freedesktop.login1.xml
     introspection/org.freedesktop.systemd1.Automount.xml
     introspection/org.freedesktop.systemd1.Device.xml
     introspection/org.freedesktop.systemd1.Job.xml
     introspection/org.freedesktop.systemd1.Manager.xml
     introspection/org.freedesktop.systemd1.Mount.xml
     introspection/org.freedesktop.systemd1.Path.xml
#     introspection/org.freedesktop.systemd1.Service.xml
     introspection/org.freedesktop.systemd1.Snapshot.xml
#     introspection/org.freedesktop.systemd1.Socket.xml
#     introspection/org.freedesktop.systemd1.Swap.xml
     introspection/org.freedesktop.systemd1.Target.xml
#     introspection/org.freedesktop.systemd1.Timer.xml
#     introspection/org.freedesktop.systemd1.Unit.xml
     introspection/org.freedesktop.timedate1.xml
   )

set_property( SOURCE ${INTERFACE_INTROSPECTION_XML_FILES} PROPERTY INCLUDE generic-types.h)

set( ADAPTER_INTROSPECTION_XML_FILES
   )

set_source_files_properties( ${INTERFACE_INTROSPECTION_XML_FILES} ${ADAPTER_INTROSPECTION_XML_FILES} PROPERTIES NO_NAMESPACE TRUE )

set( UNUSED_XML
)


set( FILES_TO_BUILD
   )
set ( UNUSED_FILES
)

set( UNUSED_GENERATED_FILES
)

QT4_ADD_DBUS_INTERFACES( FILES_TO_BUILD ${INTERFACE_INTROSPECTION_XML_FILES} )
foreach(adaptor ${ADAPTER_INTROSPECTION_XML_FILES})
    qt4_add_dbus_adaptor( FILES_TO_BUILD ${adaptor} "generic-types.h")
endforeach(adaptor ${ADAPTER_INTROSPECTION_XML_FILES})

#message(status "before patch in ${CMAKE_CURRENT_BUILD_DIR}")
#EXECUTE_PROCESS(COMMAND patch -p1 INPUT_FILE hand_edits.diff WORKING_DIRECTORY .})
#message(status "after patch")

add_library(systemddbus ${FILES_TO_BUILD})

TARGET_LINK_LIBRARIES(systemddbus ${QT_QTCORE_LIBRARY} ${QT_QTDBUS_LIBRARY})
