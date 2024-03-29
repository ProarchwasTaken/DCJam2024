// skeleton.h
#pragma once
#include <raylib.h>
#include "../party_members.h"
#include "../enemy.h"

class Skeleton : public Enemy {
public:
  Skeleton(Vector2 position);
  void selectSkill(party_list &player_team);
};
