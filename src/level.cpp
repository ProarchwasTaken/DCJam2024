// level.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <nlohmann/json.hpp>
#include <raylib.h>
#include "level.h"

using std::cout, nlohmann::json, std::array, std::ifstream, std::string;


Level::Level() {
  position = (Vector3){0, 0, 0};
  roto_axis = (Vector3){0, 1, 0};
  angle = 180;
  scale = (Vector3){1, 1, 1};

  setupModel();
  setupLevelGrid();
}

/* Destructor should only be called when the program terminates.
 * Otherwise, something has clearly gone wrong.*/
Level::~Level() {
  UnloadModel(model);
  UnloadTexture(floor_texture);
  UnloadTexture(wall_texture);
  UnloadTexture(ceiling_texture);
  UnloadTexture(exit_texture);
}

/* For getting the collision array from map_data.json and return it.
 * The returned array is only one dimensional, so it have have to be
 * converted into a 2D array so it could be usable.*/
array<int, TOTAL_TILES> Level::getRawGrid() {
  string data_path = "./data/map_data.json";

  std::cout << "Attempting to open: " << data_path << "\n";
  ifstream map_data(data_path);

  json parsed_data = json::parse(map_data);
  map_data.close();

  array<int, TOTAL_TILES> raw_data = parsed_data["layers"][0]["data"];
  return raw_data;
}

/* The level grid is important for detecting collisions and making sure
 * the player doesn't get out of the map. Setting it up is what this
 * function is for.*/
void Level::setupLevelGrid() {
  cout << "==========================\n";
  cout << "Loading Level Data...\n";
  cout << "Map Width: " << MAP_WIDTH << "\n";
  cout << "Map Height: " << MAP_HEIGHT << "\n";
  cout << "Total Tiles: " << TOTAL_TILES << "\n";

  cout << "Getting raw collision data...\n";
  auto raw_data = getRawGrid();
  int x = 0;
  int y = 0;

  cout << "Reshaping raw array into a 2D array.\n";
  for (int value : raw_data) {
    level_grid[y][x] = value;
    x++;

    bool reached_end_of_row = x % MAP_WIDTH == 0;
    if (reached_end_of_row) {
      x = 0;
      y++;
    }
  }
  cout << "Reshaping complete.\n";
  printLevelGrid();
}

/* This function is purly for debugging purposes, and it should not be 
 * used for anything else.*/
void Level::printLevelGrid() {
  cout << "Level Grid\n";
  cout << "==========================\n";
  for (int y = 0; y < MAP_HEIGHT; y++) {
    cout << "[ ";
    for (int x = 0; x < MAP_WIDTH; x++) {
      cout << level_grid[y][x] << ", ";
    }
    cout << "]\n";
  }
  cout << "==========================\n";
}

/* For loading the game's model and mapping all of it's textures to it.
 * There's a reason why the Level class is only initialized once during
 * the program's lifetime. I figured constantly reloading the same model
 * is a waste of time.*/
void Level::setupModel() {
  floor_texture = LoadTexture("graphics/textures/floor1.png");
  ceiling_texture = LoadTexture("graphics/textures/ceiling1.png");

  wall_texture = LoadTexture("graphics/textures/wall1.png");
  exit_texture = LoadTexture("graphics/textures/exit_doorway.png");

  model = LoadModel("graphics/models/level.glb");
  model.materials[1].maps[MATERIAL_MAP_DIFFUSE].texture = floor_texture;
  model.materials[2].maps[MATERIAL_MAP_DIFFUSE].texture = wall_texture;
  model.materials[3].maps[MATERIAL_MAP_DIFFUSE].texture = ceiling_texture;
  model.materials[4].maps[MATERIAL_MAP_DIFFUSE].texture = exit_texture;
}

void Level::draw(Color tint) {
  DrawModelEx(model, position, roto_axis, angle, scale, tint);
}
