// battler.h
#pragma once
#include <string>
#include <memory>
#include <list>

using std::string, std::list, std::unique_ptr;

#define PARTY_MEMBER 0
#define ENEMY 1


struct Battler {
  Battler(
    string name, int type, int max_hp, int max_sp, int atk, int def, 
    int agi 
  );
  string name;
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

typedef list<unique_ptr<Battler>> battler_list;
