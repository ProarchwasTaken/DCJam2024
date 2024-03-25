// battler.cpp
#include "battle_system/battler.h"

Battler::Battler(
  string name, int type, int max_hp, int max_sp, int atk, int def, 
  int agi
) 
{  
  this->name = name;
  this->type = type;
  dead = false;

  this->max_hp = max_hp;
  hp = max_hp;

  this->max_sp = max_sp;
  sp = max_sp;

  attack = atk;
  defense = def;
  agility = agi;
}
