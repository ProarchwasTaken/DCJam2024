#include <iostream>
#include <raylib.h>
#include "constants.h"

using std::cout;


int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DCJam 2024");
  SetTargetFPS(FPS_CAP);

  cout << "Everything is good to go! Starting main loop.\n";

  while (WindowShouldClose() == false) {
    BeginDrawing();
    {
      ClearBackground(WHITE);
    }
    EndDrawing();
  }

  return 0;
}
