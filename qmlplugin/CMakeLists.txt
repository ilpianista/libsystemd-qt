set(qtsystemdplugin_SRCS
    qtsystemdplugin.cpp
    system.cpp
)

add_library(qtsystemdplugin SHARED ${qtsystemdplugin_SRCS})

qt5_use_modules(qtsystemdplugin Qml)

target_link_libraries(qtsystemdplugin QtSystemd)

install(TARGETS qtsystemdplugin DESTINATION ${QT5_IMPORTS_DIR}/org/qtsystemd)

install(FILES qmldir DESTINATION ${QT5_IMPORTS_DIR}/org/qtsystemd)
