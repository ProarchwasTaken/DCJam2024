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
  
  void titleUpdate();
  void titleDraw();

  void fieldUpdate();
  void fieldDraw();

  void battleUpdate();
  void battleDraw();

  uint8_t game_state;

  unique_ptr<Level> level;
  unique_ptr<FieldPlayer> field_player;
};
