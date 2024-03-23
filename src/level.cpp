// level.cpp
#include <raylib.h>
#include "level.h"


Level::Level() {
  position = (Vector3){0, 0, 0};
  roto_axis = (Vector3){0, 1, 0};
  angle = -90;
  scale = (Vector3){1, 1, 1};
  setupModel();
}

Level::~Level() {
  UnloadModel(model);
  UnloadTexture(floor_texture);
  UnloadTexture(wall_texture);
  UnloadTexture(ceiling_texture);
}

void Level::setupModel() {
  floor_texture = LoadTexture("graphics/textures/floor1.png");
  ceiling_texture = LoadTexture("graphics/textures/ceiling1.png");

  wall_texture = LoadTexture("graphics/textures/wall1.png");

  model = LoadModel("graphics/models/level.glb");
  model.materials[1].maps[MATERIAL_MAP_DIFFUSE].texture = floor_texture;
  model.materials[2].maps[MATERIAL_MAP_DIFFUSE].texture = ceiling_texture;
  model.materials[3].maps[MATERIAL_MAP_DIFFUSE].texture = wall_texture;
}

void Level::draw() {
  DrawModelEx(model, position, roto_axis, angle, scale, WHITE);
}
