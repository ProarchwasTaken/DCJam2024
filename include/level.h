// level.h
#pragma once
#include <raylib.h>


class Level {
public:
  Level();
  ~Level();

  void setupModel();
  void draw();

private:
  Model model;
  Vector3 position;
  Vector3 roto_axis;
  float angle;
  Vector3 scale;

  Texture floor_texture;
  Texture wall_texture;
  Texture ceiling_texture;
};
