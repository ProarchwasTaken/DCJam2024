// level.h
#pragma once
#include <raylib.h>
#include <array>

using std::array;

#define MAP_WIDTH 7
#define MAP_HEIGHT 7
#define TOTAL_TILES (MAP_WIDTH * MAP_HEIGHT)

#define NOTHING 0
#define SOLID_WALL 2
#define PLAYER 3

typedef array<array<int, MAP_WIDTH>, MAP_HEIGHT> lv_array;

class Level {
public:
  Level();
  ~Level();

  lv_array level_grid;

  void loadLevelGrid();
  void printLevelGrid();
  array<int, TOTAL_TILES> getRawGrid();

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
