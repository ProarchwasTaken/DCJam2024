// skeleton.cpp
#include <raylib.h>
#include <memory>
#include "battle_system/constants.h"
#include "battle_system/enemy.h"
#include "battle_system/enemies/skeleton.h"
#include "battle_system/party_members.h"
#include "battle_system/skills/attack.h"

using std::make_unique;


Skeleton::Skeleton(Vector2 position):
  Enemy("Skeleton", position, 10, 20, 5, 2, 5)
{
  idle_sprite = LoadTexture("graphics/sprites/undead_skeleton.png");
  attack_sprite = LoadTexture("graphics/sprites/skeleton_attack.png");
  has_attack_sprite = true;
}

void Skeleton::selectSkill(party_list &player_team) {
  chosen_skill = make_unique<AttackSkill>(*this, *player_team.front());
  status = ATTACK;
}
