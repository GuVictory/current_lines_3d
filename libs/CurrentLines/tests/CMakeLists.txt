find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
        ${GTEST_INCLUDE_DIRS}
)

add_executable(CurrentLinesTests
        test.cpp
        src/CurrentLineGeneratorTest.cpp)

target_link_libraries(
        CurrentLinesTests ${GTEST_LIBRARIES} Threads::Threads CurrentLines)

add_test(CurrentLinesTests "./test")