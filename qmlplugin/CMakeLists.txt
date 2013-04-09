set(qtsystemdplugin_SRCS
    qtsystemdplugin.cpp
)

add_library(qtsystemdplugin SHARED ${qtsystemdplugin_SRCS})

target_link_libraries(qtsystemdplugin ${Qt5Core_LIBRARIES}
                                      ${Qt5Declarative_LIBRARIES}
                                      QtSystemd)

install(TARGETS qtsystemdplugin DESTINATION ${IMPORTS_INSTALL_DIR}/org/qtsystemd)
install(FILES qmldir DESTINATION ${IMPORTS_INSTALL_DIR}/org/qtsystemd)
