// game.h
#pragma once
#include <cstdint>
#include <memory>
#include <raylib.h>
#include "level.h"
#include "battle_system/party.h"
#include "hud.h"
#include "battle_manager.h"
#include "field/field_player.h"

using std::unique_ptr, std::shared_ptr;

#define CANVAS_X 56
#define CANVAS_Y 53
#define CANVAS_WIDTH 689
#define CANVAS_HEIGHT 291

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

  void startBattle();
  void endBattle();
  
  void titleUpdate();
  void titleDraw();

  void fieldUpdate();
  void fieldDraw();

  void battleUpdate();
  void battleDraw();

  void loseUpdate();
  void loseDraw();

private:
  uint8_t game_state;
  double delta_time;
  Font main_font;

  RenderTexture canvas3D;
  Rectangle source;
  Rectangle dest;
  Vector2 origin;

  unique_ptr<BattleManager> battle_manager;

  unique_ptr<Level> level;
  unique_ptr<Party> player_party;
  shared_ptr<Hud> hud;
  unique_ptr<FieldPlayer> field_player;
};
