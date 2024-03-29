// skill.cpp
#include "battle_system/battler.h"
#include "battle_system/skill.h"


Skill::Skill(Battler &user, Battler &target, int hit_chance, 
             int agi_modifier) {
  this->user = &user;
  this->target = &target;

  this->hit_chance = hit_chance;

  this->agi_modifier = agi_modifier;
  user.agi_modifier += agi_modifier;
}

Skill::Skill(Battler &user, int agi_modifier) {
  this->user = &user;

  this->agi_modifier = agi_modifier;
  user.agi_modifier += agi_modifier;
}

Skill::~Skill() {
  message.clear();
  user->agi_modifier = 0;
}
