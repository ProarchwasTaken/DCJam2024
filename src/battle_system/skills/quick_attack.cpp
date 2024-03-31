// quick_attack.cpp
#include <raylib.h>
#include "battle_system/skill.h"
#include "battle_system/battler.h"
#include "battle_system/skills/quick_attack.h"

#define DMG_FORMULA(uAtk, tDef, tmulti) uAtk - ((tDef * tmulti) * 0.5) + 6


QuickAttackSkill::QuickAttackSkill(Battler &user, Battler &target):
  Skill(user, target, 90, 4) {
  calulation();
}

void QuickAttackSkill::calulation() {
  message.push_back(TextFormat("%s uses quick attack!\n\n",
                               user->name.c_str()));

  int random_number = GetRandomValue(1, 100);

  if (random_number <= hit_chance) {
    successful_hit = true;

    damage_magnitude = DMG_FORMULA(user->attack, target->defense, 
                                  target->def_multiplier);

    message.push_back(
      TextFormat("%s took %i damage.\n\n", target->name.c_str(), 
                 damage_magnitude)
    );

    bool lethalDamage = target->hp - damage_magnitude <= 0;
    if (lethalDamage) {
      message.push_back(
        TextFormat("%s was slain!", target->name.c_str())
      );
    }
  }
  else {
    message.push_back(
      TextFormat("%s evaded the attack!\n\n", target->name.c_str())
    );
    successful_hit = false;
  }
}

void QuickAttackSkill::applySkill() {
  if (successful_hit == false) {
    return;
  }

  target->hp -= damage_magnitude;
  target->deathCheck();
}

