// enemy.cpp
#include "battle_system/battler.h"
#include "battle_system/constants.h"
#include "battle_system/enemy.h" 
#include <raylib.h>
#include <raymath.h>
#include <string>

using std::string;


Enemy::Enemy(
  string name, Vector2 position, int max_hp, int max_sp, int atk, int def, 
  int agi
): Battler(name, ENEMY, max_hp, max_sp, atk, def, agi) 
{
  origin = (Vector2){128, 128};
  this->position = Vector2Subtract(position, origin);
  current_sprite = IDLE_SPRITE;
}

Enemy::~Enemy() {
  UnloadTexture(idle_sprite);

  if (has_attack_sprite) {
    UnloadTexture(attack_sprite);
  }
  
  if (chosen_skill != nullptr) {
    chosen_skill.reset();
  }
}

void Enemy::draw() {
  if (dead) {
    return;
  }

  Texture *selected_texture;

  switch (current_sprite) {
    case IDLE_SPRITE: {
      selected_texture = &idle_sprite;
      break;
    }
    case ATTACK_SPRITE: {
      selected_texture = &attack_sprite;
      break;
    }
  }

  DrawTextureV(*selected_texture, position, WHITE);
}
