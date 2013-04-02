set(QtSystemdTest_SRCS
    manager-test.cpp
    )

add_executable(manager-test ${QtSystemdTest_SRCS})

target_link_libraries(manager-test QtSystemd)