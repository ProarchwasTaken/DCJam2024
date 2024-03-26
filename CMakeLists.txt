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
src/level.cpp
src/hud.cpp
src/scenes/title_scene.cpp
src/scenes/field_scene.cpp
src/scenes/battle_scene.cpp
src/field/field_player.cpp
src/battle_system/battler.cpp
src/battle_system/enemy.cpp
src/battle_system/party.cpp
src/battle_system/party_members/steve.cpp
src/battle_system/enemies/skeleton.cpp
include/constants.h
include/game.h
include/level.h
include/hud.h
include/field/field_player.h
include/battle_system/constants.h
include/battle_system/battler.h
include/battle_system/enemy.h
include/battle_system/party.h
include/battle_system/party_members/steve.h
include/battle_system/enemies/skeleton.h
)

target_compile_options("game" PRIVATE --debug -O0)
target_link_libraries("game" PRIVATE
-lraylib 
-lopengl32 
-lgdi32
-lwinmm
)
