set(QtSDManager_SRCS
    sdmanager-test.cpp
)

add_executable(sdmanager-test ${QtSDManager_SRCS})

qt5_use_modules(sdmanager-test Core)

target_link_libraries(sdmanager-test QtSystemd)

set(QtLDManager_SRCS
    ldmanager-test.cpp
)

add_executable(ldmanager-test ${QtLDManager_SRCS})

qt5_use_modules(ldmanager-test Core)

target_link_libraries(ldmanager-test QtSystemd)

set(qsystemd_SRCS
    qsystemd.cpp
)

add_executable(qsystemd ${qsystemd_SRCS})

find_package(Qt5Gui)
find_package(Qt5Quick)

qt5_use_modules(qsystemd Gui Quick)

configure_file(main.qml main.qml COPYONLY)
