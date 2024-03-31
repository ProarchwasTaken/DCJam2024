// enemy_troops.cpp
#include <raylib.h>
#include "battle_system/constants.h"
#include "battle_system/enemy_troops.h"


SkeletonInfo::SkeletonInfo(Vector2 position) {
  enemy = SKELETON;
  this->position = position;
}

GolemInfo::GolemInfo(Vector2 position) {
  enemy = GOLEM;
  this->position = position;
}

TroopOneSkeleton::TroopOneSkeleton() {
  troop_info.push_front(SkeletonInfo((Vector2){400, 225}));
}

TroopTwoSkeleton::TroopTwoSkeleton() {
  troop_info.push_front(SkeletonInfo((Vector2){285, 225}));
  troop_info.push_front(SkeletonInfo((Vector2){490, 225}));
}

TroopOneGolem::TroopOneGolem() {
  troop_info.push_front(GolemInfo((Vector2){400, 255}));
}

TroopTwoGolem::TroopTwoGolem() {
  troop_info.push_front(GolemInfo((Vector2){285, 225}));
  troop_info.push_front(GolemInfo((Vector2){490, 225}));
}

TroopVarietyOne::TroopVarietyOne() {
  troop_info.push_front(SkeletonInfo((Vector2){285, 225}));
  troop_info.push_front(GolemInfo((Vector2){490, 225}));
}

TroopVarietyTwo::TroopVarietyTwo() {
  troop_info.push_front(SkeletonInfo((Vector2){250, 225}));
  troop_info.push_front(GolemInfo((Vector2){400, 225}));
  troop_info.push_front(SkeletonInfo((Vector2){550, 225}));
}
