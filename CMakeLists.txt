cmake_minimum_required(VERSION 3.14)
project(Timber)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# Fetch SFML
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.1
)
FetchContent_MakeAvailable(SFML)

# Add executable
add_executable(Timber src/main.cpp)

# Link SFML modules
target_link_libraries(Timber
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds are not allowed. Please create a separate build directory.")
endif()
