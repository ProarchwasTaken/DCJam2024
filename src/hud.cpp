// hud.cpp
#include <raylib.h>
#include "hud.h"


Hud::Hud() {
  frame = LoadTexture("graphics/sprites/frame.png");
}

Hud::~Hud() {
  UnloadTexture(frame);
}

void Hud::draw() {
  DrawTexture(frame, 0, 0, WHITE);
}
