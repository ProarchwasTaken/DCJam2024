// battle_manager.h
#pragma once
#include <memory>
#include <array>
#include <string>
#include "hud.h"
#include "battle_system/battler.h"
#include "battle_system/enemy.h"
#include "battle_system/party_members.h"
#include "battle_system/enemy_troops.h"

using std::shared_ptr, std::array, std::string;


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
  BattleManager(shared_ptr<Hud> &hud);
  ~BattleManager();
  void assignPartyList(party_list &party_members);
  void createEnemyList(EnemyTroop enemy_troop);

  void beginCommandPhase();
  void commandBarInput();
  void targetSelectionInput();
  void commandPhase();
  void nextAwaitingCommand();
  void assignSkill();

  void beginActionPhase();
  void nextTurn();

  void displayLine1(Battler *battler);
  void displayLine2(Battler *battler);
  void displayLine3(Battler *battler);

  void endTurn(Battler *battler);
  void turnSequence(Battler *battler);

  void actionPhase();

  void endPhaseConditons();
  void enterEndPhase(bool game_over);
  void endPhase();

  void drawEnemies();
  
  int phase;
  bool end_battle;
  bool lost_battle;
  bool selecting_target;

private:
  party_list *player_team;
  party_list::iterator awaiting_command;

  enemy_list enemy_team;
  enemy_list::iterator targeted_enemy;

  battler_list turn_order;
  battler_list::iterator current_turn;

  array<int, 4> commands;
  array<int, 4>::iterator selected_command;

  string *text_buffer;

  float turn_timestamp;
  bool checked_if_dead;

  bool displayed_line1;
  float line1_seconds;

  bool displayed_line2;
  float line2_seconds;

  bool displayed_line3;

  float turn_seconds;
  bool finished_turn; 

  float end_seconds;
  float end_timestamp;
};
