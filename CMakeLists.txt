cmake_minimum_required(VERSION 3.5.0)

project(lookback LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
  src/main.cpp
)

add_executable(lookback ${SOURCES})
