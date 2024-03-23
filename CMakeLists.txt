cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++)

project("game")

set(EXECUTABLE_OUTPUT_PATH "../")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("include")

add_executable("game"
src/main.cpp
src/game.cpp
src/field_player.cpp
src/level.cpp
include/constants.h
include/game.h
include/field_player.h
include/level.h
)

target_compile_options("game" PRIVATE --debug -O0)
target_link_libraries("game" PRIVATE
-static
-static-libgcc 
-static-libstdc++
-lraylib 
-lopengl32 
-lgdi32
-lwinmm
)
