cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0069 NEW)

project(instrumentation)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Create an executable target for every sorting algorithm
function(instrument_sort name)
    add_executable(${PROJECT_NAME}_${name}
        instrument_sort.h instrument_${name}.cpp
    )

    add_dependencies(${PROJECT_NAME}_${name} algorithms)

    target_compile_definitions(${PROJECT_NAME}_${name}
        PRIVATE -DAPP_NAME="${PROJECT_NAME}_${name}"
    )

    target_include_directories(${PROJECT_NAME}_${name}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    )

    target_link_libraries(${PROJECT_NAME}_${name}
        PRIVATE algorithms
    )
endfunction()

instrument_sort("sort_insertion")
instrument_sort("sort_insertion_improved")
instrument_sort("sort_merge_topdown_cutoff")
instrument_sort("sort_merge_topdown")
instrument_sort("sort_merge_topdown_if_not_sorted")
instrument_sort("sort_merge_topdown_nc")
instrument_sort("sort_quick")
instrument_sort("sort_selection")
instrument_sort("sort_shell")
