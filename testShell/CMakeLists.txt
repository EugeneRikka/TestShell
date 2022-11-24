include_directories(${PROJECT_SOURCE_DIR})

file(GLOB TEST_FILES ${TESTS_DIR}/*)
add_executable(TestShell main.cpp)

foreach(TEST_FILE ${TEST_FILES})
    target_compile_options(TestShell PUBLIC "SHELL:-include ${TEST_FILE}")
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WLE)
    add_test(NAME ${TEST_NAME} COMMAND TestShell ${TEST_NAME})
endforeach()