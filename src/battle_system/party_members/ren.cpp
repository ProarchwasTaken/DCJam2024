// ren.cpp
#include <raylib.h>
#include "battle_system/party_members.h"
#include "battle_system/party_members/ren.h"


Ren::Ren() : PartyMember("Ren", 25, 25, 6, 3, 8) {
  command_portrait = LoadTexture("graphics/sprites/portrait2.png");
}
