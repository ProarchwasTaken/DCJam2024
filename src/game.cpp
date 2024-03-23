//game.cpp
#include <iostream>
#include <memory>
#include <raylib.h>
#include "constants.h"
#include "game.h"
#include "level.h"
#include "field_player.h"

using std::cout, std::make_unique;


Game::Game() {
  game_state = TITLE;

  level = make_unique<Level>();
  setupGameObjects();
}

Game::~Game() {
  cout << "Program termination detected.\n";
  cleanupGameObjects();

  if (level != nullptr) {
    cout << "Deleted the level from memory.\n";
    level.reset();
  }
}

void Game::setupGameObjects() {
  cout << "Setting up game objects.\n";
  field_player = make_unique<FieldPlayer>();
}

void Game::cleanupGameObjects() {
  cout << "Cleaning up game objects.\n";
  if (field_player != nullptr) {
    field_player.reset();
    cout << "Deleted field_player from memory.\n";
  }
}
