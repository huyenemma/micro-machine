cmake_minimum_required(VERSION 3.10)
project(MicroMachine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/libs/include)

# Add the source files
file(GLOB SOURCES ./src/*.cpp)

# Create the executable
add_executable(MicroMachine ${SOURCES})

# Find SFML libraries
# Set the path to your SFML installation
set(SFML_ROOT /opt/homebrew/Cellar/sfml/2.6.1)

# Find the SFML components
find_package(SFML 2.6 REQUIRED COMPONENTS system window graphics)
target_link_libraries(MicroMachine sfml-system sfml-window sfml-graphics)

# Link Box2D library
target_link_libraries(MicroMachine ${PROJECT_SOURCE_DIR}/libs/libbox2d.a)

# Add compile options for warnings, etc.
target_compile_options(MicroMachine PRIVATE -Wall -Wextra)
