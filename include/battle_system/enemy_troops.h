// enemy_troops.h
#pragma once
#include <raylib.h>
#include <list>

using std::list;

/* Contains the information needed for the BattleManager to create a
 * specific enemy. Used as a base struct for other structs to derive
 * from. Any structs that derive that this has the resposibility to 
 * define these two variables.*/
struct EnemyInfo {
  int enemy;
  Vector2 position;
};

struct SkeletonInfo : public EnemyInfo {
  SkeletonInfo(Vector2 position);
};

struct GolemInfo : public EnemyInfo {
  GolemInfo(Vector2 position);
};


/* Contains information for an entire group of enemies. Data is used by
 * the BattleManager to create a whole team on enemies. Structs that
 * derive from this class have the responsibility defining: what enemies
 * are in a specific troop, and how many there are.*/
struct EnemyTroop {
  ~EnemyTroop() {
    troop_info.clear();
  }
  list<EnemyInfo> troop_info;
};

/* Just one skeleton. Fatherless, maidenless, and most importantly alone.
 * Centered in the middle of the screen. Prime target for the jumping.*/
struct TroopOneSkeleton : public EnemyTroop {
  TroopOneSkeleton();
};

/* Two skeletons. Slightly more dangerous when one. Maybe they'll get one
 * lick in before both dying horribly.*/
struct TroopTwoSkeleton : public EnemyTroop {
  TroopTwoSkeleton();
};
