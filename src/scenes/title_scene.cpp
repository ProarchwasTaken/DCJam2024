// title_scene.cpp
#include <raylib.h>
#include "constants.h"
#include "game.h"


void Game::titleUpdate() {
  if (IsKeyPressed(KEY_ENTER)) {
    setupGameObjects();
    game_state = FIELD;
  }
}

void Game::titleDraw() {
  DrawText("Press Enter to Start.", 48, 280, 64, WHITE);
}

