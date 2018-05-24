cmake_minimum_required(VERSION 3.9)

project(tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(Threads REQUIRED)
find_package(GoogleTest REQUIRED)

enable_testing()

set(definitions
    ${GoogleTest_DEFINITIONS}
)

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)

set(include_dirs
    ${PROJECT_SOURCE_DIR}/..
    ${GoogleTest_INCLUDE_DIRS}
)

set(libraries
    ${GoogleTest_LIBRARIES}
)

include_directories(${include_dirs})
add_executable(${PROJECT_NAME} ${headers} ${sources})
target_link_libraries(${PROJECT_NAME} ${libraries})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${definitions})
add_test(${PROJECT_NAME} ${PROJECT_NAME})
