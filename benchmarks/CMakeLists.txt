cmake_minimum_required(VERSION 3.9)

project(benchmarks)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(benchmark REQUIRED)

# Create an executable target for every sorting algorithm
function(benchmark_sort name)
    add_executable(${PROJECT_NAME}_${name}
        bench_${name}.cpp
    )

    add_dependencies(${PROJECT_NAME}_${name} algorithms)

    target_link_libraries(${PROJECT_NAME}_${name}
        PRIVATE algorithms
        PRIVATE benchmark::benchmark
    )
endfunction()

benchmark_sort("sort_insertion")
benchmark_sort("sort_insertion_improved")
benchmark_sort("sort_merge_topdown_cutoff")
benchmark_sort("sort_merge_topdown")
benchmark_sort("sort_merge_topdown_if_not_sorted")
benchmark_sort("sort_merge_topdown_nc")
benchmark_sort("sort_quick")
benchmark_sort("sort_selection")
benchmark_sort("sort_shell")
