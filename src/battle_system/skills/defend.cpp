// defend.cpp
#include <raylib.h>
#include "battle_system/battler.h"
#include "battle_system/skill.h"
#include "battle_system/skills/defend.h"


DefendSkill::DefendSkill(Battler &user): Skill(user, 10) {
  multiplier_increment = 1.5f;
  calulation();
}

void DefendSkill::calulation() {
  message.push_back(TextFormat("%s defends...\n\n", user->name.c_str()));
  message.push_back("Defense temporarily up!\n");
  user->def_multiplier += multiplier_increment;
}

