// skeleton.cpp
#include <raylib.h>
#include "battle_system/enemy.h"
#include "battle_system/enemies/skeleton.h"


Skeleton::Skeleton(Vector2 position):
  Enemy("Skeleton", position, 10, 20, 5, 2, 5)
{
  idle_sprite = LoadTexture("graphics/sprites/undead_skeleton.png");
  attack_sprite = LoadTexture("graphics/sprites/skeleton_attack.png");
  has_attack_sprite = true;
}
