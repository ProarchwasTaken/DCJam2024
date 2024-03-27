// battle_scene.cpp
#include <raylib.h>
#include "game.h"
#include "battle_system/constants.h"


void Game::battleUpdate() {

}

void Game::battleDraw() {
  battle_manager->drawEnemies();

  switch (battle_manager->phase) {
    case PHASE_COMMAND: {
      hud->drawCommandBar();
      break;
    }
    case PHASE_ACTION: {
      break;
    }
    case PHASE_END: {
      break;
    }
  }
}
