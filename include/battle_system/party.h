// party.h
#pragma once
#include <vector>
#include <memory>
#include "battler.h"

using std::unique_ptr, std::vector;


struct Party {
  Party();
  ~Party();

  bool leaderDead();

  battler_list party_members;
};
