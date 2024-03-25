// battler.h
#pragma once
#include <string>
#include <memory>
#include <list>

using std::string, std::list, std::shared_ptr;


struct Battler {
  Battler(
    string name, int type, int max_hp, int max_sp, int atk, int def, 
    int agi 
  );

  const char *getStatusString();

  string name;
  int status;
  int type;
  bool dead;

  int hp;
  int max_hp;

  int sp;
  int max_sp;

  int attack;
  int defense;
  int agility;
};

typedef list<shared_ptr<Battler>> battler_list;
