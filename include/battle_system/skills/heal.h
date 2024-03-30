// heal.h
#pragma once
#include "../skill.h"
#include "../battler.h"


class HealSkill : public Skill {
public:
  HealSkill(Battler &user, battler_list &user_team);

  void calulation();
  void applySkill();
private:
  float heal_magnitude;
};
