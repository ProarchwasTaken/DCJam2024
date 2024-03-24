// field_scene.cpp
#include <raylib.h>
#include "game.h"


void Game::fieldUpdate() {
  field_player->inputCheck();
  field_player->update();
}

void Game::fieldDraw() {
  BeginMode3D(field_player->camera);
  {
    level->draw();
  }
  EndMode3D();

  DrawText(TextFormat("Direction: %03i", field_player->direction), 10, 10,
           32, GREEN);
  DrawText(TextFormat("X: %02.00f", field_player->position.x), 10, 40, 32, 
           GREEN);
  DrawText(TextFormat("Y: %02.00f", field_player->position.y), 10, 70, 32, 
           GREEN);
}
