// game.cpp
#include <iostream>
#include <memory>
#include <raylib.h>
#include "constants.h"
#include "game.h"
#include "level.h"
#include "field/field_player.h"

using std::cout, std::make_unique;


Game::Game() {
  game_state = TITLE;

  canvas3D = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);
  source = {0, 0, WINDOW_WIDTH, -WINDOW_HEIGHT};
  dest = {CANVAS_X, CANVAS_Y, CANVAS_WIDTH, CANVAS_HEIGHT};
  origin = {0, 0};

  level = make_unique<Level>();
  hud = make_unique<Hud>();
}

/* The destructor should only be called when the program is about to
 * close.*/
Game::~Game() {
  cout << "Program termination detected.\n";
  cleanupGameObjects();

  UnloadRenderTexture(canvas3D);

  if (level != nullptr) {
    level.reset();
    cout << "Deleted the level from memory.\n";
  }
  if (hud != nullptr) {
    hud.reset();
    cout << "Deleted the hud from memory.\n";
  }

  cout << "Thanks for playing!\n";
}

/* Called when the player presses the enter key on the title screen.
 * Important to make sure all the game's elements are initialized.*/
void Game::setupGameObjects() {
  cout << "Setting up game objects.\n";
  player_party = make_unique<Party>();
  field_player = make_unique<FieldPlayer>(level->level_grid);
}

/* Called when the player returns to the title screen through any reason
 * like winning or losing the game.*/
void Game::cleanupGameObjects() {
  cout << "Cleaning up game objects.\n";
  if (player_party != nullptr) {
    player_party.reset();
    cout << "Deleted player_party from memory.\n";
  }
  if (field_player != nullptr) {
    field_player.reset();
    cout << "Deleted field_player from memory.\n";
  }
}

void Game::update() {
  delta_time = GetFrameTime() * TARGET_FPS;
  switch (game_state) {
    case TITLE: {
      titleUpdate();
      break;
    }
    case FIELD: {
      fieldUpdate();
      break;
    }
    case BATTLE: {
      battleUpdate();
      break;
    }
  }
}

void Game::draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  switch (game_state) {
    case TITLE: {
      titleDraw();
      break;
    }
    case FIELD: {
      fieldDraw();
      break;
    }
    case BATTLE: {
      fieldDraw();
      battleDraw();
    }
  }
  EndDrawing();
}
