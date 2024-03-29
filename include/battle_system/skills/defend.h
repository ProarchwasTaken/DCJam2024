// defend.h
#pragma once
#include "../battler.h"
#include "../skill.h"


class DefendSkill : public Skill {
public:
  DefendSkill(Battler &user);

  void calulation();
  void applySkill() {};
private:
  float multiplier_increment;
};
