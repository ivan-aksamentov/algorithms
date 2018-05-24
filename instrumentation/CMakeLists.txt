cmake_minimum_required(VERSION 3.9)

project(instrumentation)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(headers
    instrument_sort.h
)

set(include_dirs
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/..
)

function(add_instrumentation name)
    include_directories(${include_dirs})
    add_executable(${PROJECT_NAME}_${name} ${headers} instrument_${name}.cpp)
    add_dependencies(${PROJECT_NAME}_${name} algorithms)
endfunction()

add_instrumentation("sort_insertion")
add_instrumentation("sort_insertion_improved")
add_instrumentation("sort_merge_topdown_cutoff")
add_instrumentation("sort_merge_topdown")
add_instrumentation("sort_merge_topdown_if_not_sorted")
add_instrumentation("sort_merge_topdown_nc")
add_instrumentation("sort_quick")
add_instrumentation("sort_selection")
add_instrumentation("sort_shell")
