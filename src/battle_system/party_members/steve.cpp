// steve.cpp
#include <raylib.h>
#include "battle_system/party_members.h"
#include "battle_system/party_members/steve.h"

Steve::Steve() : PartyMember("Steve", 30, 20, 8, 5, 6) {
  command_portrait = LoadTexture("graphics/sprites/portrait1.png");
}
