# Добавить в сборку статическую библиотеку "CurrentLines":
add_library(CurrentLines STATIC src/CurrentLineGenerator.cpp)

# Применяется лишь для цели "CurrentLines":
target_include_directories(CurrentLines PUBLIC ./include ${CMAKE_CURRENT_SOURCE_DIR})


add_subdirectory(tests)