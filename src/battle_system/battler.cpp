// battler.cpp
#include "battle_system/constants.h"
#include "battle_system/battler.h"

Battler::Battler(
  string name, int type, int max_hp, int max_sp, int atk, int def, 
  int agi
) 
{  
  this->name = name;
  this->type = type;

  status = STANDBY;
  dead = false;

  this->max_hp = max_hp;
  hp = max_hp;

  this->max_sp = max_sp;
  sp = max_sp;

  attack = atk;

  defense = def;
  def_multiplier = 1.0f;

  agility = agi;
  agi_modifier = 0;
}

const char *Battler::getStatusString() {
  const char *status_string;

  switch (status) {
    case STANDBY: {
      status_string = "......";
      break;
    }
    case ATTACK: {
      status_string = "Attack";
      break;
    }
    case SKILL: {
      status_string = "Skill";
      break;
    }
    case DEFEND: {
      status_string = "Defend";
      break;
    }
    case FLEE: {
      status_string = "FLEE";
      break;
    }
    case DYING: {
      status_string = "Dying";
      break;
    }
  }

  return status_string;
}

void Battler::deathCheck() {
  if (hp <= 0) {
    hp = 0;

    status = DYING;
    dead = true;
  }
}
