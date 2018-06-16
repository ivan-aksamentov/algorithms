cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(GoogleTest REQUIRED)

enable_testing()

add_executable(${PROJECT_NAME}
    test_binary_gap.cpp
    test_sort.h
    test_sort_insertion.cpp
    test_sort_insertion_improved.cpp
    test_sort_merge_topdown.cpp
    test_sort_merge_topdown_cutoff.cpp
    test_sort_merge_topdown_if_not_sorted.cpp
    test_sort_merge_topdown_nc.cpp
    test_sort_quick.cpp
    test_sort_selection.cpp
    test_sort_shell.cpp
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE ""
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE GoogleTest
    PRIVATE algorithms
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
