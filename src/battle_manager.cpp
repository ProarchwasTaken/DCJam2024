// battle_manager.cpp
#include <memory>
#include "constants.h"
#include "battle_system/constants.h"
#include "game.h"
#include "battle_manager.h"
#include "battle_system/party_members.h"
#include "battle_system/enemy_troops.h"
#include "battle_system/enemies/skeleton.h"

using std::make_shared;


void Game::startBattle() {
  battle_manager->createEnemyList(TroopTwoSkeleton());
  battle_manager->beginCommandPhase();
  game_state = BATTLE;
}


BattleManager::~BattleManager() {
  enemy_team.clear();
}

void BattleManager::assignPartyList(party_list &party_members) {
  player_team = &party_members;
}

void BattleManager::createEnemyList(EnemyTroop enemy_troop) {
  for (auto enemy_info : enemy_troop.troop_info) {
    switch (enemy_info.enemy) {
      case SKELETON: {
        enemy_team.push_front(make_shared<Skeleton>(enemy_info.position));
      }
    }
  }
}

void BattleManager::beginCommandPhase() {
  phase = PHASE_COMMAND;
  awaiting_command = player_team->begin();
  hud->awaiting_command = &awaiting_command;
}

void BattleManager::drawEnemies() {
  for (auto enemy : enemy_team) {
    enemy->draw();
  }
}

