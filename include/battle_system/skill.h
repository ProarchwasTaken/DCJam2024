// skill.h
#pragma once
#include <string>
#include <vector>
#include "common.h"
#include "battler.h"

using std::vector, std::string;


struct Skill {
  Skill(Battler &user, Battler &target, int hit_chance, int agi_modifier);
  ~Skill();
  virtual void calulation() {};
  virtual void applySkill() {};

  Battler *user;
  Battler *target;

  int hit_chance;
  bool successful_hit;

  int agi_modifier;

  vector<string> message;
};
