# Добавить в сборку статическую библиотеку "MeshWorker":
add_library(MeshWorker STATIC src/MeshLoader.cpp)

# Применяется лишь для цели "MeshWorker":
target_include_directories(MeshWorker PUBLIC ./include ${CMAKE_CURRENT_SOURCE_DIR} MeshEntity)

target_link_libraries(MeshWorker MeshEntity)

add_subdirectory(tests)