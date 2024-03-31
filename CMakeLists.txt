cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)

project("game")

set(EXECUTABLE_OUTPUT_PATH "../")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories("include")

add_executable("game"
src/main.cpp
src/game.cpp
src/level.cpp
src/hud.cpp
src/battle_manager.cpp
src/scenes/title_scene.cpp
src/scenes/field_scene.cpp
src/scenes/battle_scene.cpp
src/scenes/lose_scene.cpp
src/field/field_player.cpp
src/battle_system/battler.cpp
src/battle_system/enemy.cpp
src/battle_system/party_members.cpp
src/battle_system/enemy_troops.cpp
src/battle_system/party.cpp
src/battle_system/skill.cpp
src/battle_system/party_members/steve.cpp
src/battle_system/party_members/ren.cpp
src/battle_system/party_members/sakura.cpp
src/battle_system/enemies/skeleton.cpp
src/battle_system/enemies/golem.cpp
src/battle_system/skills/attack.cpp
src/battle_system/skills/defend.cpp
src/battle_system/skills/quick_attack.cpp
src/battle_system/skills/laser_beam.cpp
src/battle_system/skills/heal.cpp
include/constants.h
include/game.h
include/level.h
include/hud.h
include/battle_manager.h
include/field/field_player.h
include/battle_system/constants.h
include/battle_system/common.h
include/battle_system/battler.h
include/battle_system/enemy.h
include/battle_system/party_members.h
include/battle_system/enemy_troops.h
include/battle_system/party.h
include/battle_system/skill.h
include/battle_system/party_members/steve.h
include/battle_system/party_members/ren.h
include/battle_system/party_members/sakura.h
include/battle_system/enemies/skeleton.h
include/battle_system/enemies/golem.h
include/battle_system/skills/attack.h
include/battle_system/skills/defend.h
include/battle_system/skills/quick_attack.h
include/battle_system/skills/laser_beam.h
include/battle_system/skills/heal.h
)

target_compile_options("game" PRIVATE -mwindows -O3)
target_link_libraries("game" PRIVATE
-lraylib 
-lopengl32 
-lgdi32
-lwinmm
)
