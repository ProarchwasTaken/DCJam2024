// sakura.cpp
#include <raylib.h>
#include "battle_system/constants.h"
#include "battle_system/party_members.h"
#include "battle_system/party_members/sakura.h"


Sakura::Sakura() : PartyMember("Sakura", 45, 15, 10, 8, 3) {
  special_skill = SKILL_HEAL;
  sp_cost = 5;

  command_portrait = LoadTexture("graphics/sprites/portrait3.png");
}
