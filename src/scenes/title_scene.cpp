// title_scene.cpp
#include <raylib.h>
#include "game.h"


void Game::titleUpdate() {
  if (IsKeyPressed(KEY_ENTER)) {
    startGame();
  }
}

void Game::titleDraw() {
  DrawText("Press Enter to Start.", 48, 280, 64, WHITE);
}

