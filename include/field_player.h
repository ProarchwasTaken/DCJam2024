// field_player.h
#pragma once
#include <raylib.h>
#include <array>
#include "level.h"
using std::array;

#define NORTH 0
#define EAST 90
#define SOUTH 180
#define WEST 270

#define ROTO_SPEED 5
#define MOVE_SECONDS 0.5


class FieldPlayer {
public:
  FieldPlayer(lv_array &level_grid);
  void setSpawnPosition();
  void setUpCamera();

  void update(double &delta_time);
  void inputCheck();

  void rotation();
  void movement(double &delta_time);

  Camera camera;
  int direction;

  bool rotating;
  int moving;
  bool is_idle;
private:
  lv_array *level_grid;

  float current_angle;
  Vector2 position;

  float move_percentage;
};
