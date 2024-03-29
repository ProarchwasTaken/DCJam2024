// battle_scene.cpp
#include <raylib.h>
#include "game.h"
#include "battle_system/constants.h"


void Game::battleUpdate() {
  if (battle_manager->end_battle) {
    endBattle();
    return;
  }

  switch (battle_manager->phase) {
    case PHASE_COMMAND: {
      battle_manager->commandPhase();
      break;
    }
    case PHASE_ACTION: {
      battle_manager->actionPhase();
      break;
    }
    case PHASE_END: {
      battle_manager->endPhase();
    }
  }
}

void Game::battleDraw() {
  battle_manager->drawEnemies();

  switch (battle_manager->phase) {
    case PHASE_COMMAND: {
      if (battle_manager->selecting_target == false) {
        hud->drawCommandBar();
      }
      else {
        hud->drawTargetingReticle();
      }
      break;
    }
    case PHASE_ACTION: {
      hud->drawTextBox();
      break;
    }
    case PHASE_END: {
      hud->drawTextBox();
      break;
    }
  }
}
