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
#include "battle_system/skills/attack.h"

using std::make_shared, std::shared_ptr, std::cout, std::make_unique;


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

void BattleManager::assignSkill() {
  PartyMember *user = awaiting_command->get();
  Enemy *target = targeted_enemy->get();

  switch (user->status) {
    case ATTACK: {
      cout << "Assigning AttackSkill to: " << user->name << "\n";
      user->chosen_skill.reset();
      user->chosen_skill = make_unique<AttackSkill>(*user, *target);
    }
  }

  nextAwaitingCommand();
}

void BattleManager::nextAwaitingCommand() {
  cout << "Moving on to the next party member that needs a command.\n";
  awaiting_command++;

  if (awaiting_command == player_team->end()) {
    cout << "Commands have been assigned to all party members.\n";
    beginActionPhase();
  }
}

void BattleManager::beginCommandPhase() {
  cout << "Beginning command phase.\n";
  phase = PHASE_COMMAND;

  awaiting_command = player_team->begin();
  targeted_enemy = enemy_team.begin();
  selected_command = commands.begin();
}

void BattleManager::beginActionPhase() {
  cout << "Beginning action phase.\n";
  phase = PHASE_ACTION;
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
  else if (IsKeyPressed(KEY_Z)) {
    assignSkill();
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

void BattleManager::actionPhase() {

}

void BattleManager::drawEnemies() {
  for (auto enemy : enemy_team) {
    enemy->draw();
  }
}

