find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
        ${GTEST_INCLUDE_DIRS}
)

add_executable(MeshWorkerTests
        test.cpp
        ./src/MeshLoaderTest.cpp
        )

target_link_libraries(
        MeshWorkerTests ${GTEST_LIBRARIES} Threads::Threads MeshWorker)

add_test(MeshWorkerTests "./test")