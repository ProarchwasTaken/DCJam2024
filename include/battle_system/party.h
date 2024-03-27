// party.h
#pragma once
#include "party_members.h"


/* Not to be confused with PartyMember. This struct is where the current
 * data for the game's party_members are located. This class is usually
 * initialized when the game starts, and deleted when the game resets.*/
struct Party {
  Party();
  ~Party();

  /* Returns true if the "party leader" is dead. The party leader is
   * determined by who is the first party member in the list. In such
   * a scenario of which the party leader is dead, the game must enter
   * it's fail state.*/
  bool leaderDead();
  void overview();

  party_list party_members;
};
