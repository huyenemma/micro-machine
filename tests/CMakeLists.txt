cmake_minimum_required(VERSION 3.8)

set(This Tests)

set(Sources timerTest.cpp vehicleTest.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC gtest_main Testing sfml-system sfml-graphics sfml-window sfml-audio sfml-network)


add_test(
    NAME ${This}
    COMMAND ${This}
)