// lose_scene.cpp
#include <raylib.h>
#include "constants.h"
#include "game.h"


void Game::loseUpdate() {
  if (IsKeyPressed(KEY_ENTER)) {
    game_state = TITLE;
  }
}

void Game::loseDraw(Font &main_font) {
  DrawTextEx(main_font, "GAME OVER", {185, 250}, 64, 5, WHITE);
}
