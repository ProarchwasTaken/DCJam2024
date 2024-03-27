// battle_manager.cpp
#include <iostream>
#include <memory>
#include <raylib.h>
#include "constants.h"
#include "battle_system/constants.h"
#include "game.h"
#include "battle_manager.h"
#include "battle_system/party_members.h"
#include "battle_system/enemy_troops.h"
#include "battle_system/enemies/skeleton.h"

using std::make_shared, std::shared_ptr, std::cout;


void Game::startBattle() {
  cout << "Battle Time!\n";
  battle_manager->createEnemyList(TroopTwoSkeleton());
  battle_manager->beginCommandPhase();
  game_state = BATTLE;
}


BattleManager::BattleManager(shared_ptr<Hud> &hud) {
  hud->awaiting_command = &awaiting_command;
  hud->selected_command = &selected_command;

  commands = {
    COMMAND_ATTACK,
    COMMAND_SKILL,
    COMMAND_DEFEND,
    COMMAND_FLEE
  };
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
  cout << "Beginning command phase.\n";
  phase = PHASE_COMMAND;
  awaiting_command = player_team->begin();

  selected_command = commands.begin();
}

void BattleManager::commandBarInputCheck() {
  if (IsKeyPressed(KEY_RIGHT)) {
    selected_command++;
    if (selected_command == commands.end()) {
      selected_command = commands.begin();
    }
  }
  else if (IsKeyPressed(KEY_LEFT)) {
    if (selected_command == commands.begin()) {
      selected_command = commands.end();
    }
    selected_command--;
  }
}

void BattleManager::commandPhase() {
  commandBarInputCheck();
}

void BattleManager::drawEnemies() {
  for (auto enemy : enemy_team) {
    enemy->draw();
  }
}

