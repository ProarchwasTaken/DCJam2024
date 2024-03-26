// party_members.h
#pragma once
#include <raylib.h>
#include <string>
#include <memory>
#include <list>
#include "battler.h"

using std::string, std::list, std::shared_ptr;

class PartyMember : public Battler{
public:
  PartyMember(
    string name, int max_hp, int max_sp, int atk, int def, int agi
  );
  ~PartyMember();

  Texture command_portrait;
};


typedef list<shared_ptr<PartyMember>> party_list;
