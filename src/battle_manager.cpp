// battle_manager.cpp
#include <iostream>
#include <memory>
#include <raylib.h>
#include "battle_system/enemy.h"
#include "constants.h"
#include "battle_system/constants.h"
#include "game.h"
#include "battle_manager.h"
#include "battle_system/battler.h"
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

  text_buffer = &hud->text_buffer;

  commands = {
    COMMAND_ATTACK,
    COMMAND_SKILL,
    COMMAND_DEFEND,
    COMMAND_FLEE
  };

  selecting_target = false;
  
  checked_if_dead = false;

  displayed_line1 = false;
  line1_seconds = 1.0f;

  displayed_line2 = false;
  line2_seconds = 1.5f;

  displayed_line3 = false;

  finished_turn = false;
  turn_seconds = 2.0f;
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

bool compareAgility(shared_ptr<Battler> &b1, shared_ptr<Battler> &b2) {
  return b1->agility + b1->agi_modifier > b2->agility + b2->agi_modifier;
}

void BattleManager::beginActionPhase() {
  cout << "Beginning action phase.\n";
  phase = PHASE_ACTION;

  for (auto enemy : enemy_team) {
    enemy->selectSkill(*player_team);
  }

  turn_order.clear();
  for (auto party_member : *player_team) {
    turn_order.push_back(party_member);
  }
  for (auto enemy : enemy_team) {
    turn_order.push_back(enemy);
  }

  turn_order.sort(compareAgility);
  cout << "Turn order: ";
  for (auto battler : turn_order) {
    cout << battler->name << ", ";
  }
  cout << "\n";

  current_turn = turn_order.begin();
  turn_timestamp = GetTime();
}

void BattleManager::nextTurn() {
  cout << "Proceeding to next battler in turn order.\n";
  checked_if_dead = false;

  displayed_line1 = false;
  displayed_line2 = false;
  displayed_line3 = false;

  finished_turn = false;

  current_turn++;
  if (current_turn == turn_order.end()) {
    cout << "The end of the turn order has been reached.\n";
    phase = PHASE_END;
    return;
  }

  turn_timestamp = GetTime();
}

void BattleManager::displayLine1(Battler *battler) {
  cout << battler->chosen_skill->message[0];
  text_buffer->append(battler->chosen_skill->message[0]);

  if (battler->type == ENEMY) {
    Enemy *enemy = static_cast<Enemy*>(battler);

    if (enemy->has_attack_sprite) {
      enemy->current_sprite = ATTACK_SPRITE;
    }
  }

  displayed_line1 = true;
}

void BattleManager::displayLine2(Battler *battler) {
  cout << battler->chosen_skill->message[1];
  text_buffer->append(battler->chosen_skill->message[1]);

  battler->chosen_skill->applySkill();
  displayed_line2 = true;
}

void BattleManager::displayLine3(Battler *battler) {
  cout << battler->chosen_skill->message[2] << "\n";
  text_buffer->append(battler->chosen_skill->message[2]);
  displayed_line3 = true;
}

void BattleManager::endTurn(Battler *battler) {
  if (battler->type == ENEMY) {
    Enemy *enemy = static_cast<Enemy*>(battler);

    if (enemy->current_sprite == ATTACK_SPRITE) {
      enemy->current_sprite = IDLE_SPRITE;
    }
  }

  battler->chosen_skill.reset();
  if (battler->dead == false) {
    battler->status = STANDBY;
  }

  text_buffer->clear();
  finished_turn = true;
}

void BattleManager::turnSequence(Battler *battler) {
  float time_elasped = GetTime() - turn_timestamp;

  bool line2_not_displayed = displayed_line1 && displayed_line2 == false;

  bool should_display_line2 = (line2_not_displayed && 
    time_elasped >= line1_seconds);

  bool line3_exists = battler->chosen_skill->message.size() == 3;

  bool line3_not_displayed = displayed_line2 && displayed_line3 == false;

  bool should_display_line3 = (line3_not_displayed && line3_exists && 
    time_elasped >= line2_seconds);

  bool turn_is_over = time_elasped >= turn_seconds;

  if (displayed_line1 == false) {
    displayLine1(battler);
  }
  else if (should_display_line2) {
    displayLine2(battler);
  }
  else if (should_display_line3) {
    displayLine3(battler);
  }
  else if (turn_is_over) {
    endTurn(battler);
  }
}

void BattleManager::actionPhase() {
  Battler *battler = current_turn->get();

  bool battler_dead = checked_if_dead == false && battler->dead;
  if (battler_dead) {
    cout << "The current battler in the turn order is dead.\n";
    nextTurn();
    return;
  }
  else {
    checked_if_dead = true;
  }

  if (finished_turn) {
    cout << "Turn is finished.\n";
    nextTurn();
    return;
  }

  turnSequence(battler);
}

void BattleManager::drawEnemies() {
  for (auto enemy : enemy_team) {
    enemy->draw();
  }
}

