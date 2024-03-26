// enemy_troops.h
#include <raylib.h>
#include <memory>
#include <list>

using std::unique_ptr, std::list;

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
