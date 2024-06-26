// quick_attack.h
#pragma once
#include "../skill.h"
#include "../battler.h"


class QuickAttackSkill : public Skill {
public:
  QuickAttackSkill(Battler &user, Battler &target);

  void calulation();
  void applySkill();

private:
  int damage_magnitude;
};
