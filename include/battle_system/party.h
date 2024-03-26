// party.h
#pragma once
#include "party_members.h"


struct Party {
  Party();
  ~Party();

  bool leaderDead();
  void overview();

  party_list party_members;
};
