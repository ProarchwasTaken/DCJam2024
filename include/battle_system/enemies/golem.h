//golem.h
#pragma once
#include <raylib.h>
#include "../party_members.h"
#include "../enemy.h"

class Golem : public Enemy {
public:
  Golem(Vector2 position);
  void selectSkill(party_list &player_team);
};
