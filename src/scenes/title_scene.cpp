// title_scene.cpp
#include <raylib.h>
#include "game.h"


void Game::titleUpdate() {
  if (IsKeyPressed(KEY_ENTER)) {
    startGame();
  }
}

void Game::titleDraw(Font &main_font) {
  DrawTextEx(main_font, "EXTRICATE", {200, 75}, 64, 5, WHITE);
  DrawTextEx(main_font, "Press ENTER to play.", {200, 350}, 32, 0, WHITE);
  DrawTextEx(main_font, "Programmer: Tyler Dillard", {0, 550}, 24, 0, 
             WHITE);
  DrawTextEx(main_font, "Artist: the_saver1", {0, 575}, 24, 0, WHITE);
}

