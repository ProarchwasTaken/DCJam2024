// laser_beam.h
#pragma once
#include "../skill.h"
#include "../battler.h"


class LaserBeamSkill : public Skill {
public:
  LaserBeamSkill(Battler &user, Battler &target);

  void calulation();
  void applySkill();

private:
  int damage_magnitude;
};
