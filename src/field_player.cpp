// field_player.cpp
#include <raylib.h>
#include "field_player.h"

FieldPlayer::FieldPlayer() {
  setUpCamera();
}

void FieldPlayer::setUpCamera() {
  camera.position = (Vector3){5.0f, 5.0f, 5.0f};
  camera.up = (Vector3){0, 1, 0};
  camera.fovy = 60;
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.projection = CAMERA_PERSPECTIVE;
}
