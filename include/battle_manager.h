// battle_manager.h
#pragma once
#include "battle_system/enemy.h"
#include "battle_system/party_members.h"
#include "battle_system/enemy_troops.h"


/* Handles the battle system. Basically the culmination of all that code
 * I was writing. I feel that 70% of the battle system's functionality
 * will take place in this class.
 *
 * During a battle, there are 3 main phases. 
 *
 * First, the Command phase. Where the player selects what action each 
 * party member will perform during the next phase.
 *
 * Second, the Action phase. Where every battler performs their selected 
 * action. Those actions can be along the lines of: Attacking, using a 
 * skill, defending, or fleeing from the fight altogether. The order of 
 * which every battler performs their selected action depends on 
 * everyone's agility stat.
 *
 * And finally, the End phase. By then, certain checks are made like: If 
 * the party leader is dead, or if all enemies have been defeated.*/
class BattleManager {
public:
  ~BattleManager();
  void assignPartyList(party_list &party_members);
  void createEnemyList(EnemyTroop enemy_troop);

  void drawEnemies();
  
  int phase;
  

private:
  party_list *player_team;
  enemy_list enemy_team;
};
