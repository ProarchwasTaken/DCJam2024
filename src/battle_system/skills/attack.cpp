// attack.cpp
#include <raylib.h>
#include "battle_system/constants.h"
#include "battle_system/battler.h"
#include "battle_system/skill.h"
#include "battle_system/skills/attack.h"

#define DMG_FORMULA(uAtk, tDef) uAtk - (tDef * 0.5) + 4


AttackSkill::AttackSkill(Battler &user, Battler &target):
Skill(user, target, 75)
{

}

void AttackSkill::calulation() {
  message.push_back(TextFormat("%s attacks!\n", user->name.c_str()));

  int random_number = GetRandomValue(1, 100);

  if (random_number <= hit_chance) {
    successful_hit = true;

    damage_magitude = DMG_FORMULA(user->attack, target->defense);

    message.push_back(
      TextFormat("%s took %i damage.\n", target->name.c_str(), 
                 damage_magitude)
    );

    bool lethalDamage = target->hp - damage_magitude <= 0;
    if (lethalDamage) {
      message.push_back(
        TextFormat("%s was slain!", target->name.c_str())
      );
    }
  }
  else {
    message.push_back(
      TextFormat("%s evaded the attack!", target->name.c_str())
    );
    successful_hit = false;
  }
}

void AttackSkill::applySkill() {
  if (successful_hit == false) {
    return;
  }

  target->hp -= damage_magitude;
  target->deathCheck();
}

#undef DMG_FORMULA
