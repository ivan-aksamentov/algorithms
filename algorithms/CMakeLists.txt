cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(algorithms)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

add_library(${PROJECT_NAME} STATIC
    include/algorithms/heap.h
    include/algorithms/sort_insertion.h
    include/algorithms/sort_insertion_improved.h
    include/algorithms/sort_merge_topdown_cutoff.h
    include/algorithms/sort_merge_topdown.h
    include/algorithms/sort_merge_topdown_if_not_sorted.h
    include/algorithms/sort_merge_topdown_nc.h
    include/algorithms/sort_quick.h
    include/algorithms/sort_selection.h
    include/algorithms/sort_shell.h
    src/dummy.cpp
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC ""
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} INTERFACE
    common
)
