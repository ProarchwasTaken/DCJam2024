// enemy_troops.h
#pragma once
#include <raylib.h>
#include <list>

using std::list;

struct EnemyInfo {
  int enemy;
  Vector2 position;
};

struct SkeletonInfo : public EnemyInfo {
  SkeletonInfo(Vector2 position);
};


struct EnemyTroop {
  ~EnemyTroop() {
    troop_info.clear();
  }
  list<EnemyInfo> troop_info;
};

struct TroopOneSkeleton : public EnemyTroop {
  TroopOneSkeleton();
};

struct TroopTwoSkeleton : public EnemyTroop {
  TroopTwoSkeleton();
};
