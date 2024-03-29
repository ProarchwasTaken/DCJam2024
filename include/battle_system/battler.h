// battler.h
#pragma once
#include <string>
#include <memory>
#include <list>
#include "common.h"
#include "skill.h"

using std::string, std::list, std::shared_ptr, std::unique_ptr;


/* A "Battler" could be considered a generalized term for a participant
 * in the game's battle system, whether party member or enemy. The struct
 * standard rpg data like hp, sp, attack, defense, etc.
 *
 * The Battler struct can't do much on it's own, but it's data is used the
 * other important parts of the game. This struct's functionality is
 * usually inherited by other classes.*/
struct Battler {
  Battler(
    string name, int type, int max_hp, int max_sp, int atk, int def, 
    int agi 
  );

  /* The status variable type is that of an integer. Depending on the
   * number, the function will return a string corrolating to the value
   * of status.*/
  const char *getStatusString();
  void deathCheck();

  string name;
  int type;
  int status;
  bool dead;

  unique_ptr<Skill> chosen_skill;

  int hp;
  int max_hp;

  int sp;
  int max_sp;

  int attack;
  int defense;

  int agility;
  int agi_modifier;
};

typedef list<shared_ptr<Battler>> battler_list;
