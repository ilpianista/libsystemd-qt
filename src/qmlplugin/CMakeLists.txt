set(qtsystemdplugin_SRCS
    qtsystemdplugin.cpp
)

add_library(qtsystemdplugin SHARED ${qtsystemdplugin_SRCS})

qt5_use_modules(qtsystemdplugin Qml)

install(TARGETS qtsystemdplugin DESTINATION ${QT5_IMPORTS_DIR}/org/qtsystemd)

install(FILES qmldir DESTINATION ${QT5_IMPORTS_DIR}/org/qtsystemd)
