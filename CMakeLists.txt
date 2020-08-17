###################################################################################################
##
##      Информация о проекте
##
###################################################################################################

cmake_minimum_required(VERSION 3.14)
project(CurrentLines VERSION 1.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

###################################################################################################
##
##      Опции проекта
##
###################################################################################################

option(CURRENTLINES_TESTS "Включить модульное тестирование" ON)
option(CURRENTLINES_COVERAGE "Включить измерение покрытия кода тестами" OFF)

###################################################################################################
##
##      Опции компиляции
##
###################################################################################################

if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
            -Werror

            -Wall
            -Wextra
            -Wpedantic

            -Wcast-align
            -Wcast-qual
            -Wconversion
            -Wctor-dtor-privacy
            -Wenum-compare
            -Wfloat-equal
            -Wnon-virtual-dtor
            -Wold-style-cast
            -Woverloaded-virtual
            -Wredundant-decls
            -Wsign-conversion
            -Wsign-promo
    )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/W4 /WX)
endif()

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

###################################################################################################
##
##      Заголовочная библиотека
##
###################################################################################################

add_library(currentlines INTERFACE)
target_include_directories(currentlines INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_compile_features(currentlines INTERFACE cxx_std_17)

add_library(CurrentLines::currentlines ALIAS currentlines)

###################################################################################################
##
##      Компилируемая библиотека
##
###################################################################################################

add_library(currentlinessrc src/CurrentLines/CurrentLineGenerator.cpp)
target_link_libraries(currentlinessrc PUBLIC currentlines)

add_library(CurrentLines::currentlinessrc ALIAS currentlinessrc)

###################################################################################################
##
##      Установка
##
###################################################################################################

install(DIRECTORY include DESTINATION include)

install(TARGETS currentlines currentlinessrc EXPORT CurrentLinesConfig)
install(EXPORT CurrentLinesConfig NAMESPACE CurrentLines:: DESTINATION share/CurrentLines/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/CurrentLinesConfigVersion.cmake"
        VERSION
        ${PROJECT_VERSION}
        COMPATIBILITY
        AnyNewerVersion
        )
install(FILES "${PROJECT_BINARY_DIR}/CurrentLinesConfigVersion.cmake" DESTINATION share/CurrentLines/cmake)

###################################################################################################
##
##      Тесты
##
###################################################################################################

if(NOT CURRENTLINES_TESTING)
    message(STATUS "Тестирование проекта CurrentLines выключено")
elseif(IS_SUBPROJECT)
    message(STATUS "CurrentLines не тестируется в режиме подмодуля")
else()
    add_subdirectory(tests)
endif()

###################################################################################################
##
##      Документация
##
###################################################################################################

if(NOT IS_SUBPROJECT)
    add_subdirectory(doc)
endif()
