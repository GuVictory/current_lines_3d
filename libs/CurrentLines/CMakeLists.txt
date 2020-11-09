# Добавить в сборку статическую библиотеку "CurrentLines":
add_library(CurrentLines STATIC
            src/CurrentLineGenerator.cpp
            src/Interpolation.cpp
            src/CurrentLine.cpp)

# Применяется лишь для цели "CurrentLines":
target_include_directories(CurrentLines PUBLIC ./include ${CMAKE_CURRENT_SOURCE_DIR} MeshEntity)

target_link_libraries(CurrentLines MeshEntity)

add_subdirectory(tests)