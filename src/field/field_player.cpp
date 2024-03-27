// field_player.cpp
#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>
#include "level.h"
#include "field/field_player.h"


FieldPlayer::FieldPlayer(lv_array &level_grid) {
  this->level_grid = &level_grid;
  setSpawnPosition();

  is_idle = true;
  rotating = false;

  moving = false;
  move_percentage = 0.0;

  direction = SOUTH;
  current_angle = direction;

  setUpCamera();
}

/* Called on initialization. Searches the level_grid for it's spawning
 * position and sets it's position to that.*/
void FieldPlayer::setSpawnPosition() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      int value = level_grid->at(y).at(x);
      int found_player_spawn = value == PLAYER;

      if (found_player_spawn) {
        position.x = x;
        position.y = y;
      }
    }
  }
}

/* For setting up the game's camera in order for 3D mode to work.
 * The camera's position and target depends on the player's position.
 * Albeit with some modifications.*/
void FieldPlayer::setUpCamera() {
  camera.position = (Vector3){position.x + 0.5f, 0.5f, position.y};
  camera.up = (Vector3){0, 1, 0};
  camera.fovy = 60;
  camera.target = (Vector3){position.x + 0.5f, 0.5f, position.y + 0.5f};
  camera.projection = CAMERA_PERSPECTIVE;

}

void FieldPlayer::update() {
  is_idle = !moving && !rotating;

  if (moving) movement();
  if (rotating) rotation();
}

/* Called each frame of which the player should be moving forward. 
 * Basically, the camera will move forward based on a percentage 
 * difference. The player stops moving when the percentage reaches 100*/
void FieldPlayer::movement() {
  float new_percentage = move_percentage + GetFrameTime() / MOVE_SECONDS;
  new_percentage = Clamp(new_percentage, 0.0, 1.0);

  float difference = new_percentage - move_percentage;
  CameraMoveForward(&camera, difference, true);

  if (new_percentage == 1.0) {
    moving = false;
    move_percentage = 0.0;
  }
  else {
    move_percentage = new_percentage;
  }
}

/* Called each frame of which the camera should be rotating. The camera
 * will turn left or right depending on if current_angle is lower or
 * higher than direction. The camera should stop rotating when both values
 * are equal.*/
void FieldPlayer::rotation() {
  if (direction > current_angle) {
    CameraYaw(&camera, ROTO_SPEED * DEG2RAD, true);
    current_angle += ROTO_SPEED;
  }
  else if (direction < current_angle) {
    CameraYaw(&camera, -ROTO_SPEED * DEG2RAD, true);
    current_angle -= ROTO_SPEED;
  }

  bool rotation_complete = current_angle == direction;
  if (rotation_complete) {
    rotating = false;
    direction = direction % 360;
    if (direction < 0) {
      direction = 360 - (direction * -1);
    }
    current_angle = direction;
  }
}

void FieldPlayer::inputCheck() {
  bool turning_right = IsKeyDown(KEY_RIGHT) && is_idle;
  bool turning_left = IsKeyDown(KEY_LEFT) && is_idle;
  bool looking_behind = IsKeyDown(KEY_DOWN) && is_idle;
  bool moving_forward = IsKeyDown(KEY_UP) && is_idle;

  if (turning_right) {
    direction -= 90;
    rotating = true;
  }
  else if (turning_left) {
    direction += 90;
    rotating = true;
  }
  else if (looking_behind) {
    direction += 180;
    rotating = true;
  }
  else if (moving_forward && canMove()) {
    moving = true;
  }
}

/* Used for checking if the player could move forward or not. Should be
 * called whenever the player attempts to move forward.*/
bool FieldPlayer::canMove() {
  Vector2 offset;

  switch (direction) {
    case EAST: {
      offset = ADJACENT::RIGHT;
      break;
    }
    case SOUTH: {
      offset = ADJACENT::DOWN;
      break;
    }
    case WEST: {
      offset = ADJACENT::LEFT;
      break;
    }
    case NORTH: {
      offset = ADJACENT::UP;
      break;
    }
  }

  Vector2 new_pos = Vector2Add(position, offset);
  int tile_value = level_grid->at(new_pos.y).at(new_pos.x);

  if (tile_value != SOLID_WALL) {
    position = new_pos;
    return true;
  }
  else {
    return false;
  }
}
