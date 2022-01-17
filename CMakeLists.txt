cmake_minimum_required(VERSION 3.21)

project(Game VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# GLFW
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.5.1)
FetchContent_MakeAvailable(sfml)
set(SFML_DIR "d:/projekty/github/game/build/_deps/sfml-build")

add_subdirectory(src/app)
add_subdirectory(src/lib)