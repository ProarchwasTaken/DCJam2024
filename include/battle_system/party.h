// party.h
#pragma once
#include "battler.h"


struct Party {
  Party();
  ~Party();

  bool leaderDead();
  void overview();

  battler_list party_members;
};
