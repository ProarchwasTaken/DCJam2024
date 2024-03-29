// sakura.cpp
#include <raylib.h>
#include "battle_system/party_members.h"
#include "battle_system/party_members/sakura.h"


Sakura::Sakura() : PartyMember("Sakura", 45, 15, 10, 8, 3) {
  command_portrait = LoadTexture("graphics/sprites/portrait3.png");
}
