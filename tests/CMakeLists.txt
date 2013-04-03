set(QtSDManager_SRCS
    sdmanager-test.cpp
    )

add_executable(sdmanager-test ${QtSDManager_SRCS})

target_link_libraries(sdmanager-test QtSystemd)

set(QtLDManager_SRCS
    ldmanager-test.cpp
    )

add_executable(ldmanager-test ${QtLDManager_SRCS})

target_link_libraries(ldmanager-test QtSystemd)