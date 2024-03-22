// field_player.cpp
#include <raylib.h>
#include "field_player.h"

FieldPlayer::FieldPlayer() {
  setUpCamera();
}

void FieldPlayer::setUpCamera() {
  camera.position = (Vector3){0.5f, 0.5f, -0.5f};
  camera.up = (Vector3){0, 1, 0};
  camera.fovy = 60;
  camera.target = (Vector3){0.6f, 0.5f, -0.5f};
  camera.projection = CAMERA_PERSPECTIVE;
}
