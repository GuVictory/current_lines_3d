add_executable(currentlines-unit-tests test_main.cpp)

target_include_directories(currentlines-unit-tests PRIVATE docktests)
target_sources(currentlines-unit-tests PRIVATE CurrentLines/CurrentLineGenerator.cpp)
target_link_libraries(currentlines-unit-tests
        PRIVATE
        CurrentLines::currentlinessrc
        )

find_program(GCOVR_EXECUTABLE gcovr)
if(MYLIB_COVERAGE AND GCOVR_EXECUTABLE)
    message(STATUS "Измерение покрытия кода тестами включено")

    target_compile_options(currentlines-unit-tests PRIVATE --coverage)
    target_link_libraries(currentlines-unit-tests PRIVATE gcov)

    target_compile_options(currentlinessrc PRIVATE --coverage)
    target_link_libraries(currentlinessrc PRIVATE gcov)

    add_custom_target(coverage
            COMMAND
            ${GCOVR_EXECUTABLE}
            --root=${PROJECT_SOURCE_DIR}/
            --filter=${PROJECT_SOURCE_DIR}/include
            --filter=${PROJECT_SOURCE_DIR}/src
            --object-directory=${PROJECT_BINARY_DIR}
            DEPENDS
            check
            )
elseif(CURRENTLINES_COVERAGE AND NOT GCOVR_EXECUTABLE)
    set(CURRENTLINES_COVERAGE OFF)
    message(WARNING "Для замеров покрытия кода тестами требуется программа gcovr")
endif()

add_custom_target(check ALL COMMAND currentlines-unit-tests)