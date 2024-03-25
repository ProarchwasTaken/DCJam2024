// hud.h
#pragma once
#include <raylib.h>


class Hud {
public:
  Hud();
  ~Hud();

  void draw();
private:
  Texture frame;
};
