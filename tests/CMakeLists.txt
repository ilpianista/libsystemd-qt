set(QtSystemdTest_SRCS
    sdmanager-test.cpp
    )

add_executable(sdmanager-test ${QtSystemdTest_SRCS})

target_link_libraries(sdmanager-test QtSystemd)