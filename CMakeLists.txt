###################################################################################################
##
##      Информация о проекте
##
###################################################################################################

cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
project(CurrentLines3D VERSION 1.0 LANGUAGES CXX)

add_executable(CurrentLines3D main.cpp)

###################################################################################################
##
##      Подключим статические библиотеки
##
###################################################################################################
add_subdirectory(libs)


# Скомпоновать исполняемый файл "CurrentLines3D" со
# скомпилированной статической библиотекой "CurrentLines":

enable_testing()

target_link_libraries(CurrentLines3D CurrentLines)
target_link_libraries(CurrentLines3D MeshWorker)
target_link_libraries(CurrentLines3D MeshEntity)