#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "level.h"
#include "field_player.h"

using std::cout;


int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DCJam 2024");
  SetTargetFPS(FPS_CAP);

  Level level;
  FieldPlayer field_player;

  cout << "Everything is good to go! Starting main loop.\n";
  while (WindowShouldClose() == false) {
    BeginDrawing();
    {
      ClearBackground(WHITE);

      BeginMode3D(field_player.camera);
      {
        DrawGrid(10, 1);
        level.draw();
      }
      EndMode3D();
    }
    EndDrawing();
  }

  return 0;
}
