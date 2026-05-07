cmake_minimum_required(VERSION 3.10)
project(TwoSum)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create library for twosum
add_library(twosum_lib src/twosum.cpp)

# Create test executable
add_executable(test_twosum tests/test_twosum.cpp)
target_link_libraries(test_twosum twosum_lib)

# Set output directory for executables
set_target_properties(test_twosum PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Optional: Create main executable if main.cpp exists
file(GLOB MAIN_SRC "src/main.cpp")
if(MAIN_SRC)
    add_executable(twosum_app ${MAIN_SRC})
    target_link_libraries(twosum_app twosum_lib)
    set_target_properties(twosum_app PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()
