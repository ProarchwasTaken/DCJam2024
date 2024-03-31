#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "game.h"

using std::cout;


int main() {
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Extricate");
  SetTargetFPS(FPS_CAP);

  Game game;

  cout << "Everything is good to go! Starting main loop.\n";
  while (WindowShouldClose() == false) {
    if (IsKeyPressed(KEY_F11)) {
      ToggleFullscreen();
    }
    game.update();
    game.draw();
  }

  return 0;
}
