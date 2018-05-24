cmake_minimum_required(VERSION 3.9)

include(FindPackageHandleStandardArgs)
unset(GoogleTest_FOUND)

find_library(Threads REQUIRED)

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
    # GoogleTest_gtest_LIBRARY_DEBUG
    # GoogleTest_gmock_LIBRARY_DEBUG
    # GoogleTest_gmock_main_LIBRARY_DEBUG
)

if(GOOGLETEST_FOUND)
    set(GoogleTest_FOUND ${GOOGLETEST_FOUND})
    if (WIN32)
        set(GoogleTest_LIBRARIES
                "$<$<NOT:$<CONFIG:DEBUG>>:${GoogleTest_gtest_LIBRARY_RELEASE}>"
                "$<$<NOT:$<CONFIG:DEBUG>>:${GoogleTest_gmock_LIBRARY_RELEASE}>"
                "$<$<NOT:$<CONFIG:DEBUG>>:${GoogleTest_gmock_main_LIBRARY_RELEASE}>"
                "$<$<CONFIG:DEBUG>:${GoogleTest_gtest_LIBRARY_DEBUG}>"
                "$<$<CONFIG:DEBUG>:${GoogleTest_gmock_LIBRARY_DEBUG}>"
                "$<$<CONFIG:DEBUG>:${GoogleTest_gmock_main_LIBRARY_DEBUG}>"
            ${CMAKE_THREAD_LIBS_INIT}
        )
    else()
        set(GoogleTest_LIBRARIES
                ${GoogleTest_gtest_LIBRARY_RELEASE}
                ${GoogleTest_gmock_LIBRARY_RELEASE}
                ${GoogleTest_gmock_main_LIBRARY_RELEASE}
            ${CMAKE_THREAD_LIBS_INIT}
        )
    endif()
    set(GoogleTest_INCLUDE_DIRS
    ${GoogleTest_INCLUDE_DIR}
    )
endif()
