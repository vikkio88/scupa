cmake_minimum_required(VERSION 3.0)

project(scupa)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# the -I flag in gcc
include_directories(
  ${PROJECT_SOURCE_DIR}/include/
) 

set(APP_SOURCES src/main.cpp)
set(MAZZU_LIB_SOURCES 
  include/mazzu/Card.cpp
  include/mazzu/Deck.cpp
)

set(LACU_LIB_SOURCES 
  include/lacu/helpers.cpp
)

# creates ./build/bin/APP
add_executable(${PROJECT_NAME} ${APP_SOURCES})

# shared library
set(MAZZU_LIBRARY_NAME Mazzu)
set(LACU_LIBRARY_NAME Lacu)

add_library(${MAZZU_LIBRARY_NAME} SHARED ${MAZZU_LIB_SOURCES})
add_library(${LACU_LIBRARY_NAME} SHARED ${LACU_LIB_SOURCES})

target_link_libraries(${PROJECT_NAME} ${MAZZU_LIBRARY_NAME} ${LACU_LIBRARY_NAME})

# Tests
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(tests EXCLUDE_FROM_ALL tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2 ${LIBRARY_NAME})
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)

