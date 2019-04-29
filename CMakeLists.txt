cmake_minimum_required(VERSION 3.0)

project(optional)

option(OPTIONAL_ENABLE_TESTS "Enable tests." ON)

add_library(optional INTERFACE)
target_sources(optional INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tl/optional.hpp)
target_include_directories(optional INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tl)

if(OPTIONAL_ENABLE_TESTS)
  # Prepare "Catch" library for other executables
  set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
  add_library(Catch INTERFACE)
  target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

  # Make test executable
  set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/noexcept.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/make_optional.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/in_place.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/relops.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/observers.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/extensions.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/emplace.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/constexpr.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/constructors.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/assignment.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/issues.cpp  
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/bases.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/tests/nullopt.cpp)

  add_executable(tests ${TEST_SOURCES})

  target_link_libraries(tests Catch optional)

  set(CXXSTD 14 CACHE STRING "C++ standard to use, default C++14")
  set_property(TARGET tests PROPERTY CXX_STANDARD ${CXXSTD})
endif()

