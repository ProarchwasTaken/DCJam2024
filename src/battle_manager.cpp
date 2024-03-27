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
  hud->targeted_enemy = &targeted_enemy;

  commands = {
    COMMAND_ATTACK,
    COMMAND_SKILL,
    COMMAND_DEFEND,
    COMMAND_FLEE
  };

  selecting_target = false;
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
  targeted_enemy = enemy_team.begin();
  selected_command = commands.begin();
}

void BattleManager::commandBarInput() {
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

  if (IsKeyPressed(KEY_Z)) {
    switch (*selected_command) {
      case COMMAND_ATTACK: {
        awaiting_command->get()->status = ATTACK;
        selecting_target = true;
      }
    }
  }
}

void BattleManager::targetSelectionInput() {
  if (IsKeyPressed(KEY_X)) {
    awaiting_command->get()->status = STANDBY;
    selecting_target = false;
  }

  if (IsKeyPressed(KEY_RIGHT)) {
    targeted_enemy++;
    if (targeted_enemy == enemy_team.end()) {
      targeted_enemy = enemy_team.begin();
    }
  }
  else if (IsKeyPressed(KEY_LEFT)) {
    if (targeted_enemy == enemy_team.begin()) {
      targeted_enemy = enemy_team.end();
    }
    targeted_enemy--;
  }
}

void BattleManager::commandPhase() {
  if (selecting_target == false) {
    commandBarInput();
  }
  else {
    targetSelectionInput();
  }
}

void BattleManager::drawEnemies() {
  for (auto enemy : enemy_team) {
    enemy->draw();
  }
}

