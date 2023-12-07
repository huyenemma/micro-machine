cmake_minimum_required(VERSION 3.10)
project(MicroMachine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable testing 
enable_testing()

# Add googletest
add_subdirectory(googletest)

# Detect OS and include directories accordingly
if(APPLE)
  include_directories(${PROJECT_SOURCE_DIR}/libs/arm64/include)
else()
  include_directories(${PROJECT_SOURCE_DIR}/libs/unix/include)
endif()

# Add the path to the json.hpp file
include_directories(${PROJECT_SOURCE_DIR}/libs/nlohmann)

# Where to find binary files
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML)

# Add the source files
file(GLOB SOURCES ./src/*.cpp)
file(GLOB HEADERS ./src/include/*.cpp)

# Create the executable
add_executable(MicroMachine ${SOURCES})

add_library(Testing STATIC ${SOURCES} ${HEADERS})
target_include_directories(Testing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

add_subdirectory(tests)

# Link SFML library
target_link_libraries(MicroMachine sfml-system sfml-graphics sfml-window sfml-audio sfml-network)

# Link Box2D library according to OS
if(APPLE)
  target_link_libraries(MicroMachine ${PROJECT_SOURCE_DIR}/libs/arm64/libbox2d.a)
elseif(UNIX AND NOT APPLE)
  target_link_libraries(MicroMachine ${PROJECT_SOURCE_DIR}/libs/unix/libbox2d.a)
endif()

# Where to find the headers
target_include_directories(MicroMachine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Add compile options for warnings, etc.
target_compile_options(MicroMachine PRIVATE -Wall -Wextra)
