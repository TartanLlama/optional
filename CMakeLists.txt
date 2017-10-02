cmake_minimum_required(VERSION 3.0)

project(cmake_test)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Make test executable
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/noexcept.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/make_optional.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/in_place.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/relops.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/observers.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/monadic.cpp                  
                 ${CMAKE_CURRENT_SOURCE_DIR}/tests/nullopt.cpp)
                 
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch)
set_property(TARGET tests PROPERTY CXX_STANDARD 14)
