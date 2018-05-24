cmake_minimum_required(VERSION 3.9)

project(algorithms)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(definitions

)

set(include_dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${common_INCLUDE_DIRS}
)

file(GLOB glob_headers *.h)

set(public_headers
    ${glob_headers}
)

set(headers
    ${public_headers}
)

set(library_dirs

)

set(libraries

)

include_directories(${include_dirs})
add_library(${PROJECT_NAME} INTERFACE )
add_custom_target(${PROJECT_NAME}_ SOURCES ${headers})

set(${PROJECT_NAME}_DEFINITIONS
    ${definitions}
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)

set(${PROJECT_NAME}_INCLUDE_DIRS
    ${include_dirs}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

set(${PROJECT_NAME}_LIBRARIES
    ${libraries}
    CACHE INTERNAL "${PROJECT_NAME}: Libraries" FORCE)

set(${PROJECT_NAME}_LIBRARY_DIRS
    ${library_dirs}
    CACHE INTERNAL "${PROJECT_NAME}: Library directories" FORCE)
