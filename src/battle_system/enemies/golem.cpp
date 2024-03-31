// golem.cpp
#include <raylib.h>
#include <vector>
#include <memory>
#include "battle_system/constants.h"
#include "battle_system/enemy.h"
#include "battle_system/enemies/golem.h"
#include "battle_system/party_members.h"
#include "battle_system/skills/attack.h"
#include "battle_system/skills/laser_beam.h"

using std::make_unique, std::vector, std::shared_ptr;


Golem::Golem(Vector2 position):Enemy("Golem", position, 30, 10, 8, 8, 3) {
  idle_sprite = LoadTexture("graphics/sprites/golem.png");
  attack_sprite = LoadTexture("graphics/sprites/golem_attack.png");
  has_attack_sprite = true;
}

void Golem::selectSkill(party_list &player_team) {
  vector<shared_ptr<PartyMember>> alive_members;

  for (auto member : player_team) {
    if (member->dead == false) {
      alive_members.push_back(member);
    }
  }

  int alive_count = alive_members.size();
  int random_member = GetRandomValue(0, alive_count - 1);
  int random_skill = GetRandomValue(1, 2);

  if (random_skill == 1) {
    chosen_skill = make_unique<AttackSkill>(
      *this, *alive_members[random_member]
    );
  }
  else if (random_skill == 2) {
    chosen_skill = make_unique<LaserBeamSkill>(
      *this, *alive_members[random_member]
    );
  }
  status = ATTACK;
}
