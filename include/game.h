// game.h
#pragma once
#include <cstdint>
#include <memory>
#include <raylib.h>
#include "level.h"
#include "field_player.h"

using std::unique_ptr;

struct Game {
  Game();
  ~Game();

  void setupGameObjects();
  void cleanupGameObjects();

  void update();
  void draw();

  uint8_t game_state;

  unique_ptr<Level> level;
  unique_ptr<FieldPlayer> field_player;
};
