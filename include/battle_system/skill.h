// skill.h
#pragma once
#include <string>
#include <vector>
#include "battler.h"

using std::vector, std::string;


struct Skill {
  Skill(Battler &user, Battler &target, int hit_chance);
  ~Skill();
  virtual void calulation() {};
  virtual void applySkill() {};

  Battler *user;
  Battler *target;

  int hit_chance;
  bool successful_hit;

  vector<string> message;
};
