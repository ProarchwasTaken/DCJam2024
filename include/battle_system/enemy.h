// enemy.h
#pragma once
#include <raylib.h>
#include <list>
#include <memory>
#include <string>
#include "battler.h"

using std::string, std::shared_ptr, std::list;

#define IDLE_SPRITE 0
#define ATTACK_SPRITE 1

class Enemy : public Battler {
public:
  Enemy(
    string name, Vector2 position, int max_hp, int max_sp, int atk, 
    int def, int agi);
  ~Enemy();
  void draw();

  Texture idle_sprite;

  Texture attack_sprite;
  bool has_attack_sprite = false;

private:
  Vector2 position;
  int current_sprite;
};

typedef list<shared_ptr<Enemy>> enemy_list; 
