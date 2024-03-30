// heal.cpp
#include <raylib.h>
#include "battle_system/constants.h"
#include "battle_system/skill.h"
#include "battle_system/battler.h"
#include "battle_system/skills/heal.h"


HealSkill::HealSkill(Battler &user, battler_list &user_team):
Skill(user, user_team, -1) {
  heal_magnitude = 25;
  calulation();
}

void HealSkill::calulation() {
  message.push_back(TextFormat("%s casts Heal!\n\n", user->name.c_str()));
  message.push_back(TextFormat("Party healed for %i HP!",
                               heal_magnitude));
}

void HealSkill::applySkill() {
  for (auto member : *user_team) {
    member->hp = heal_magnitude;

    if (member->dead) {
      member->dead = false;
      member->status = STANDBY;
    }

    if (member->hp > member->max_hp) {
      member->hp = member->max_hp;
    }
  }
}
