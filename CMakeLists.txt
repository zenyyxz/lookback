cmake_minimum_required(VERSION 3.20)

project(lookback
  VERSION 1.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # crucial for clangd lsp.

set(SOURCES
  src/main.cpp
  src/cli/cli.cpp
  # src/trading/paperTrading.cpp don't need yet.
  src/core/utils.cpp
)

add_executable(lookback ${SOURCES})

target_include_directories(lookback
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
