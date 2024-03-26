// enemy_troops.cpp
#include <raylib.h>
#include "battle_system/constants.h"
#include "battle_system/enemy_troops.h"


SkeletonInfo::SkeletonInfo(Vector2 position) {
  enemy = SKELETON;
  this->position = position;
}

TroopOneSkeleton::TroopOneSkeleton() {
  troop_info.push_front(SkeletonInfo((Vector2){150, 80}));
}
