// defend.h
#pragma once
#include "../skill.h"
#include "../battler.h"


class DefendSkill : public Skill {
public:
  DefendSkill(Battler &user);

  void calulation();
  void applySkill() {};
private:
  float multiplier_increment;
};
