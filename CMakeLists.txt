cmake_minimum_required(VERSION 3.9)

project(algorithms)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/cool-cmake-config ${CMAKE_MODULE_PATH})

include(CheckIPOSupported)
check_ipo_supported(RESULT result)
if(result)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE 1)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS 0)
set(CMAKE_C_EXTENSIONS 0)

include(CoolCFlags)
include(CoolCXXFlags)
include(CoolSanitizers)
include(CoolNativeArch)
include(CoolVectorize)
include(CoolFastMath)

add_subdirectory(common)

add_subdirectory(algorithms)
add_dependencies(algorithms common)

set(algorithms_BUILD_BENCHMARKS ON CACHE BOOL "Build benchmarks")
if(${algorithms_BUILD_BENCHMARKS})
    add_subdirectory(benchmarks)
endif()

set(algorithms_BUILD_INSTRUMENTATION ON CACHE BOOL "Build instrumentation tests")
if(${algorithms_BUILD_INSTRUMENTATION})
    add_subdirectory(instrumentation)
endif()

set(algorithms_BUILD_TESTS ON CACHE BOOL "Build unit tests")
if(${algorithms_BUILD_TESTS})
    add_subdirectory(tests)
    add_dependencies(tests common algorithms)
endif()
