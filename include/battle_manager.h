// battle_manager.h
#pragma once
#include "battle_system/enemy.h"
#include "battle_system/party_members.h"
#include "battle_system/enemy_troops.h"

class BattleManager {
public:
  ~BattleManager();
  void assignPartyList(party_list &party_members);
  void createEnemyList(EnemyTroop enemy_troop);

  void drawEnemies();

private:
  party_list *player_team;
  enemy_list enemy_team;
};
