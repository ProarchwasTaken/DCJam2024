// attack.h
#pragma once
#include "../skill.h"
#include "../battler.h"


class AttackSkill : public Skill {
public:
  AttackSkill(Battler &user, Battler &target);

  void calulation();
  void applySkill();

private:
  int damage_magitude;
};
