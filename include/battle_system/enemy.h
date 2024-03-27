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

/* Derived from the Battler struct. I don't know, if you're already aware
 * of this, but class is for the game's enemies. Featuring variables for
 * the enemy's sprite, and where it should be positioned on screen. Could
 * also have an attack_sprite that will be automatically used if it's
 * defined.
 *
 * This is still a base class. All derived classes have the responsibility
 * of at least defining the idle_sprite variable. Defining the 
 * attack_sprite variable is optional though.*/
class Enemy : public Battler {
public:
  Enemy(
    string name, Vector2 position, int max_hp, int max_sp, int atk, 
    int def, int agi);
  ~Enemy();

  /* Gee Golly! I wonder what this function that's named "draw" does?
   * Does it have something to do with drawing swords maybe? There is 
   * absolutely no way it could possibly have something to do with 
   * DRAWING THE ENEMY BASED ON THEIR CURRENT SPRITE would it? 
   * Nah, these's no way.*/
  void draw();

  Texture idle_sprite;

  Texture attack_sprite;
  bool has_attack_sprite = false;

private:
  Vector2 position;
  Vector2 origin;
  int current_sprite;
};

typedef list<shared_ptr<Enemy>> enemy_list; 