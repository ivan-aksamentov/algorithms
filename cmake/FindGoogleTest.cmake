cmake_minimum_required(VERSION 3.8)

include(FindPackageHandleStandardArgs)
unset(GoogleTest_FOUND)

find_package(Threads REQUIRED)

find_path(GoogleTest_INCLUDE_DIR
        NAMES
        gtest/gtest.h
        gmock/gmock.h
        HINTS
        $ENV{GoogleTest_DIR}/include
        $ENV{GoogleTest_PREFIX}/include
        ${GOOGLETEST_DIR}/include
        ${GOOGLETEST_PREFIX}/include
        ${GoogleTest_DIR}/include
        ${GoogleTest_PREFIX}/include
        $ENV{GTest_DIR}/include
        $ENV{GTest_PREFIX}/include
        ${GTest_DIR}/include
        ${GTest_PREFIX}/include)

find_library(GoogleTest_gtest_LIBRARY_RELEASE
        NAMES
        gtest
        HINTS
        $ENV{GoogleTest_DIR}/lib
        $ENV{GoogleTest_PREFIX}/lib
        ${GoogleTest_DIR}/lib
        ${GoogleTest_PREFIX}/lib
        $ENV{GTest_DIR}/lib
        $ENV{GTest_PREFIX}/lib
        ${GTest_DIR}/lib
        ${GTest_PREFIX}/lib)

find_library(GoogleTest_gmock_LIBRARY_RELEASE
        NAMES
        gmock
        HINTS
        $ENV{GoogleTest_DIR}/lib
        $ENV{GoogleTest_PREFIX}/lib
        ${GoogleTest_DIR}/lib
        ${GoogleTest_PREFIX}/lib
        $ENV{GTest_DIR}/lib
        $ENV{GTest_PREFIX}/lib
        ${GTest_DIR}/lib
        ${GTest_PREFIX}/lib)

find_library(GoogleTest_gmock_main_LIBRARY_RELEASE
        NAMES
        gmock_main
        HINTS
        $ENV{GoogleTest_DIR}/lib
        $ENV{GoogleTest_PREFIX}/lib
        ${GoogleTest_DIR}/lib
        ${GoogleTest_PREFIX}/lib
        $ENV{GTest_DIR}/lib
        $ENV{GTest_PREFIX}/lib
        ${GTest_DIR}/lib
        ${GTest_PREFIX}/lib)

# Debug
find_library(GoogleTest_gtest_LIBRARY_DEBUG
        NAMES
        gtest_d
        HINTS
        $ENV{GoogleTest_DIR}/lib
        $ENV{GoogleTest_PREFIX}/lib
        ${GoogleTest_DIR}/lib
        ${GoogleTest_PREFIX}/lib
        $ENV{GTest_DIR}/lib
        $ENV{GTest_PREFIX}/lib
        ${GTest_DIR}/lib
        ${GTest_PREFIX}/lib)

find_library(GoogleTest_gmock_LIBRARY_DEBUG
        NAMES
        gmock_d
        HINTS
        $ENV{GoogleTest_DIR}/lib
        $ENV{GoogleTest_PREFIX}/lib
        ${GoogleTest_DIR}/lib
        ${GoogleTest_PREFIX}/lib
        $ENV{GTest_DIR}/lib
        $ENV{GTest_PREFIX}/lib
        ${GTest_DIR}/lib
        ${GTest_PREFIX}/lib)

find_library(GoogleTest_gmock_main_LIBRARY_DEBUG
        NAMES
        gmock_main_d
        HINTS
        $ENV{GoogleTest_DIR}/lib
        $ENV{GoogleTest_PREFIX}/lib
        ${GoogleTest_DIR}/lib
        ${GoogleTest_PREFIX}/lib
        $ENV{GTest_DIR}/lib
        $ENV{GTest_PREFIX}/lib
        ${GTest_DIR}/lib
        ${GTest_PREFIX}/lib)

find_package_handle_standard_args(
    GoogleTest
    DEFAULT_MSG
    GoogleTest_INCLUDE_DIR
    GoogleTest_gtest_LIBRARY_RELEASE
    GoogleTest_gmock_LIBRARY_RELEASE
    GoogleTest_gmock_main_LIBRARY_RELEASE
)

if(GOOGLETEST_FOUND)
    set(GoogleTest_FOUND ${GOOGLETEST_FOUND})

    add_library(GoogleTest INTERFACE IMPORTED)

    target_include_directories(GoogleTest INTERFACE
        ${GoogleTest_INCLUDE_DIR}
    )

    target_link_libraries(GoogleTest INTERFACE

        # For windows in debug mode
        $<$<BOOL:${WIN32}>:$<$<CONFIG:DEBUG>:${GoogleTest_gtest_LIBRARY_DEBUG}>>
        $<$<BOOL:${WIN32}>:$<$<CONFIG:DEBUG>:${GoogleTest_gmock_LIBRARY_DEBUG}>>
        $<$<BOOL:${WIN32}>:$<$<CONFIG:DEBUG>:${GoogleTest_gmock_main_LIBRARY_DEBUG}>>

        # For windows in release mode
        $<$<BOOL:${WIN32}>:$<$<CONFIG:RELEASR>:${GoogleTest_gtest_LIBRARY_RELEASE}>>
        $<$<BOOL:${WIN32}>:$<$<CONFIG:RELEASR>:${GoogleTest_gmock_LIBRARY_RELEASE}>>
        $<$<BOOL:${WIN32}>:$<$<CONFIG:RELEASR>:${GoogleTest_gmock_main_LIBRARY_RELEASE}>>

        # For non-windows, export release libs
        $<$<NOT:$<BOOL:${WIN32}>>:${GoogleTest_gtest_LIBRARY_RELEASE}>
        $<$<NOT:$<BOOL:${WIN32}>>:${GoogleTest_gmock_LIBRARY_RELEASE}>
        $<$<NOT:$<BOOL:${WIN32}>>:${GoogleTest_gmock_main_LIBRARY_RELEASE}>

        Threads::Threads
    )
endif()
