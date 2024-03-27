// attack.h
#pragma once
#include "../battler.h"
#include "../skill.h"


class AttackSkill : public Skill {
public:
  AttackSkill(Battler &user, Battler &target);

  void calulation();
  void applySkill();

private:
  int damage_magitude;
};
