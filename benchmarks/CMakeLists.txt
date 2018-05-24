cmake_minimum_required(VERSION 3.9)

project(benchmarks)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Threads REQUIRED)
find_package(benchmark REQUIRED)

set(definitions

)

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)

set(include_dirs
    ${PROJECT_SOURCE_DIR}/..
)

set(libraries
    benchmark::benchmark
)

include_directories(${include_dirs})

function(add_benchmark name)
    include_directories(${include_dirs})
    add_executable(${PROJECT_NAME}_${name} ${headers} bench_${name}.cpp)
    target_compile_definitions(${PROJECT_NAME}_${name} PRIVATE ${definitions})
    target_link_libraries(${PROJECT_NAME}_${name} ${libraries})
    add_dependencies(${PROJECT_NAME}_${name} algorithms)
endfunction()

add_benchmark("sort_insertion")
add_benchmark("sort_insertion_improved")
add_benchmark("sort_merge_topdown_cutoff")
add_benchmark("sort_merge_topdown")
add_benchmark("sort_merge_topdown_if_not_sorted")
add_benchmark("sort_merge_topdown_nc")
add_benchmark("sort_quick")
add_benchmark("sort_selection")
add_benchmark("sort_shell")
