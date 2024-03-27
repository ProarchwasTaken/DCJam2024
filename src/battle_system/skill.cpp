// skill.cpp
#include <battle_system/battler.h>
#include "battle_system/skill.h"


Skill::Skill(Battler &user, Battler &target, int hit_chance) {
  this->user = &user;
  this->target = &target;

  this->hit_chance = hit_chance;
  calulation();
}

Skill::~Skill() {
  message.clear();
}
