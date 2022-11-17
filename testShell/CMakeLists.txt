include_directories(${PROJECT_SOURCE_DIR})

add_executable(TestShell main.cpp Test.h Test.cpp)

file(GLOB TEST_FILES ${TESTS_DIR}/*)
foreach(TEST_FILE ${TEST_FILES})
    #команда, которая инклудит к таргету файлы (не могу её вспомнить)
endforeach()