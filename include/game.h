// game.h
#pragma once
#include <cstdint>
#include <memory>
#include <raylib.h>
#include "level.h"
#include "field_player.h"

using std::unique_ptr;

/* The structure of the game as a whole. Some member functions are defined
 * in different files.*/
struct Game {
public:
  Game();
  ~Game();

  void setupGameObjects();
  void cleanupGameObjects();

  /* Called one every frame. Different functions will be called depending
   * on the current game_state.*/
  void update();
  /* Functions the same as the update function.*/
  void draw();
  
  void titleUpdate();
  void titleDraw();

  void fieldUpdate();
  void fieldDraw();

  void battleUpdate();
  void battleDraw();

private:
  uint8_t game_state;
  double delta_time;

  unique_ptr<Level> level;
  unique_ptr<FieldPlayer> field_player;
};
