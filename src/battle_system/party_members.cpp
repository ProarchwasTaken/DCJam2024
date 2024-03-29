// party_members.cpp
#include <raylib.h>
#include <string>
#include "battle_system/constants.h"
#include "battle_system/battler.h"
#include "battle_system/party_members.h"

using std::string;

PartyMember::PartyMember(
  string name, int max_hp, int max_sp, int atk, int def, int agi
): Battler(name, PARTY_MEMBER, max_hp, max_sp, atk, def, agi)
{

}

PartyMember::~PartyMember() {
  UnloadTexture(command_portrait);

  if (chosen_skill != nullptr) {
    chosen_skill.reset();
  }
}
