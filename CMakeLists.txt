cmake_minimum_required(VERSION 3.10)
project(MicroMachine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Detect OS
if(APPLE)
  set(SFML_VERSION "2.6") # for macOS
  include_directories(${PROJECT_SOURCE_DIR}/libs/arm64/include)
elseif(UNIX AND NOT APPLE)
  set(SFML_VERSION "2.5") # for Linux
  include_directories(${PROJECT_SOURCE_DIR}/libs/unix/include)
endif()

# Include directories for header files


# Add the source files
file(GLOB SOURCES ./src/*.cpp)

# Create the executable
add_executable(MicroMachine ${SOURCES})



# Find SFML libraries
# set(CMAKE_PREFIX_PATH "")
find_package(SFML ${SFML_VERSION} COMPONENTS graphics window system audio network REQUIRED)

target_link_libraries(MicroMachine sfml-system sfml-graphics sfml-window sfml-audio sfml-network)

# Link Box2D library
# Detect OS
if(APPLE)
  target_link_libraries(MicroMachine ${PROJECT_SOURCE_DIR}/libs/arm64/libbox2d.a)
elseif(UNIX AND NOT APPLE)
  target_link_libraries(MicroMachine ${PROJECT_SOURCE_DIR}/libs/unix/libbox2d.a)
endif()


# Add compile options for warnings, etc.
target_compile_options(MicroMachine PRIVATE -Wall -Wextra)
