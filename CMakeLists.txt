###################################################################################################
##
##      Информация о проекте
##
###################################################################################################

cmake_minimum_required(VERSION 3.14)
project(CurrentLines3D VERSION 1.0 LANGUAGES CXX)

add_executable(CurrentLines3D main.cpp libs/MeshWorker/src/MeshLoader.cpp libs/MeshWorker/include/MeshLoader.hpp)

###################################################################################################
##
##      Подключим статические библиотеки
##
###################################################################################################
add_subdirectory(libs)


# Скомпоновать исполняемый файл "CurrentLines3D" со
# скомпилированной статической библиотекой "CurrentLines":
target_link_libraries(CurrentLines3D CurrentLines)
target_link_libraries(CurrentLines3D MeshWorker)