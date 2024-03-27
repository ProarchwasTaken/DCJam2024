// field_scene.cpp
#include <raylib.h>
#include "constants.h"
#include "game.h"


void Game::fieldUpdate() {
  if (IsKeyPressed(KEY_B)) {
    startBattle();
  }

  field_player->inputCheck();
  field_player->update();
}

void Game::fieldDraw() {
  BeginTextureMode(canvas3D);
  {
    ClearBackground(WHITE);
    BeginMode3D(field_player->camera);
    {
      Color tint;
      if (game_state == BATTLE) {
        tint = DARKGRAY;
      }
      else {
        tint = WHITE;
      }
      level->draw(tint);
    }
    EndMode3D();
  }
  EndTextureMode();

  hud->drawMainFrame();
  hud->drawPartyText();
  DrawTexturePro(canvas3D.texture, source, dest, origin, 0, WHITE);
}
