// field_scene.cpp
#include <raylib.h>
#include "game.h"


void Game::fieldUpdate() {

}

void Game::fieldDraw() {
  BeginMode3D(field_player->camera);
  {
    level->draw();
  }
  EndMode3D();
}
