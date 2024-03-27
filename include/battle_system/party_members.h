// party_members.h
#pragma once
#include <raylib.h>
#include <string>
#include <memory>
#include <list>
#include "battler.h"

using std::string, std::list, std::shared_ptr;

/* Man, working with inheritance in C++ can be a pain sometimes. Lines can
 * get absurdly long. Back on topic, this class is derived from the
 * Battler struct. Who would've thought?
 *
 * A special one of the kind feature this class has is a portrait texture
 * that is drawn on the command bar when it's time to chose that
 * specific party member's action.
 *
 * Although, this is still a "base" class. Any derived class has the
 * resposibility of defining command_portrait. I hope I don't forget to
 * do that.*/
class PartyMember : public Battler{
public:
  PartyMember(
    string name, int max_hp, int max_sp, int atk, int def, int agi
  );
  ~PartyMember();

  Texture command_portrait;
};


typedef list<shared_ptr<PartyMember>> party_list;
