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

  Texture floor_texture;
  Texture wall_texture;
  Texture ceiling_texture;
};
