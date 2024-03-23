// field_player.cpp
#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>
#include "field_player.h"


FieldPlayer::FieldPlayer() {
  position = (Vector2){1, 1};

  is_idle = true;
  rotating = false;

  moving = false;
  move_percentage = 0.0;

  direction = SOUTH;
  current_angle = direction;

  setUpCamera();
}

void FieldPlayer::setUpCamera() {
  camera.position = (Vector3){0.5f, 0.5f, -0.5f};
  camera.up = (Vector3){0, 1, 0};
  camera.fovy = 60;
  camera.target = (Vector3){0.6f, 0.5f, -0.5f};
  camera.projection = CAMERA_PERSPECTIVE;

}

void FieldPlayer::update(double &delta_time) {
  is_idle = !moving && !rotating;

  if (moving) movement(delta_time);
  if (rotating) rotation();
}

void FieldPlayer::movement(double &delta_time) {
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

void FieldPlayer::rotation() {
  if (direction > current_angle) {
    CameraYaw(&camera, ROTO_SPEED * DEG2RAD, false);
    current_angle += ROTO_SPEED;
  }
  else if (direction < current_angle) {
    CameraYaw(&camera, -ROTO_SPEED * DEG2RAD, false);
    current_angle -= ROTO_SPEED;
  }

  bool rotation_complete = current_angle == direction;
  if (rotation_complete) {
    rotating = false;
    direction = direction % 360;
    current_angle = direction;
  }
}

void FieldPlayer::inputCheck() {
  bool turningRight = IsKeyDown(KEY_D) && is_idle;
  if (turningRight) {
    direction -= 90;
    rotating = true;
  }

  bool turningLeft = IsKeyDown(KEY_A) && is_idle;
  if (turningLeft) {
    direction += 90;
    rotating = true;
  }

  bool movingForward = IsKeyDown(KEY_W) && is_idle;
  if (movingForward) {
    moving = true;
  }
}

