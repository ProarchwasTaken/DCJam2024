// party.cpp
#include <iostream>
#include <memory>
#include "battle_system/party.h"
#include "battle_system/party_members/steve.h"
#include "battle_system/party_members/ren.h"
#include "battle_system/party_members/sakura.h"

using std::make_shared, std::cout;


Party::Party() {
  party_members.push_back(make_shared<Steve>());
  party_members.push_back(make_shared<Ren>());
  party_members.push_back(make_shared<Sakura>());
  overview();
}

Party::~Party() {
  party_members.clear();
}

bool Party::leaderDead() {
  auto &party_leader = party_members.back();

  if (party_leader->dead) {
    return true;
  }
  else {
    return false;
  }
}

void Party::overview() {
  cout << "==========Party Overview==========\n";
  for (auto &member : party_members) {
    cout << "Name: " << member->name
      << ", HP: " << member->max_hp
      << ", SP: " << member->max_sp
      << ", Attack: " << member->attack
      << ", Defense: " << member->defense
      << ", Agility: " << member->agility << "\n";
  }
  cout << "==================================\n";
}
