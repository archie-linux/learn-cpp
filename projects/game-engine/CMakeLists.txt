cmake_minimum_required(VERSION 3.10)
project(SimpleGameEngine)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

# Add modules as libraries for modularity
add_library(core STATIC src/core/GameEngine.cpp src/core/GameObject.cpp)
add_library(graphics STATIC src/graphics/Renderer.cpp)
add_library(physics STATIC src/physics/Physics.cpp)
add_library(entities STATIC src/entities/Player.cpp src/entities/Enemy.cpp)

# Executable
add_executable(game src/main.cpp)
target_link_libraries(game core graphics physics entities SFML::Graphics SFML::Window SFML::System)


# Include directories
target_include_directories(game PRIVATE include)
target_include_directories(core PRIVATE include)
target_include_directories(graphics PRIVATE include)
target_include_directories(physics PRIVATE include)
target_include_directories(entities PRIVATE include)
