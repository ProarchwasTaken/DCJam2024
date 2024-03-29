// field_player.h
#pragma once
#include <raylib.h>
#include <array>
#include "../level.h"

using std::array;

#define NORTH 0
#define WEST 90
#define SOUTH 180
#define EAST 270

#define ROTO_SPEED 5
#define MOVE_SECONDS 0.5


namespace ADJACENT {
  const Vector2 RIGHT = {1, 0};
  const Vector2 DOWN = {0, 1};
  const Vector2 LEFT = {-1, 0};
  const Vector2 UP = {0, -1};
}


/* The FieldPlayer is a game object that's controlled by the user for
 * field gameplay. It's able of turning left and right and moving in only 
 * one direction. Uses the level_grid for collisions.*/
class FieldPlayer {
public:
  FieldPlayer(lv_array &level_grid);
  void setSpawnPosition();
  void setUpCamera();

  void update();

  void inputCheck();

  void rotation();
  void movement();
  bool canMove();

  Camera camera;
  Vector2 position;
  int direction;

  bool rotating;
  int moving;
  bool is_idle;
private:
  lv_array *level_grid;

  float current_angle;

  float move_percentage;
};
