find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
        ${GTEST_INCLUDE_DIRS}
)

add_executable(MeshEntityTests
        test.cpp
        src/PointTest.cpp
        src/NodeTest.cpp
        src/FieldTest.cpp
        src/LineTest.cpp
        src/PlaneTest.cpp
        )

target_link_libraries(
        MeshEntityTests ${GTEST_LIBRARIES} Threads::Threads MeshEntity)

add_test(MeshEntityTests "./test")