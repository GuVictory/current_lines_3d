# Добавить в сборку статическую библиотеку "MeshEntity":
add_library(MeshEntity STATIC
                    src/Point.cpp
                    src/Node.cpp
                    src/Field.cpp
                    src/Line.cpp
                    src/Plane.cpp
                    src/Cell.cpp
                    src/Mesh.cpp)

# Применяется лишь для цели "MeshEntity":
target_include_directories(MeshEntity PUBLIC ./include ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)