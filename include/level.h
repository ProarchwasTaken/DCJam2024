// level.h
#pragma once
#include <raylib.h>
#include <array>

using std::array;

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define TOTAL_TILES (MAP_WIDTH * MAP_HEIGHT)

#define NOTHING 0
#define SOLID_WALL 2
#define PLAYER 3
#define END_TRIGGER 4

typedef array<array<int, MAP_WIDTH>, MAP_HEIGHT> lv_array;


/* The game's map consists of the model itself, and the level array which
 * is used for collision for the FieldPlayer. Both of which are loaded 
 * from external files.*/
class Level {
public:
  Level();
  ~Level();

  lv_array level_grid;

  void setupLevelGrid();
  void printLevelGrid();
  array<int, TOTAL_TILES> getRawGrid();

  void setupModel();
  void draw(Color tint);

private:
  Model model;
  Vector3 position;
  Vector3 roto_axis;
  float angle;
  Vector3 scale;

  Texture floor_texture;
  Texture wall_texture;
  Texture ceiling_texture;
  Texture exit_texture;
};
