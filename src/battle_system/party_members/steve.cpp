// steve.cpp
#include <raylib.h>
#include "battle_system/constants.h"
#include "battle_system/party_members.h"
#include "battle_system/party_members/steve.h"

Steve::Steve() : PartyMember("Steve", 30, 20, 8, 5, 6) {
  special_skill = SKILL_QUICKATTACK;
  sp_cost = 3;

  command_portrait = LoadTexture("graphics/sprites/portrait1.png");
}
