# Задать минимальную версию CMake:
cmake_minimum_required(VERSION 3.14)

# Добавить в сборку статическую библиотеку "MeshEntity":
add_library(MeshEntity STATIC src/Point.cpp)

# Применяется лишь для цели "MeshEntity":
target_include_directories(MeshEntity PUBLIC ./include ${CMAKE_CURRENT_SOURCE_DIR})