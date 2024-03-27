// hud.h
#pragma once
#include <raylib.h>
#include <memory>
#include <string>
#include <array>
#include "battle_system/enemy.h"
#include "battle_system/party_members.h"

using std::string, std::array, std::shared_ptr;


class Hud {
public:
  Hud();
  ~Hud();

  void setupCommandBar();
  void setupTargetReticle();

  void assignPartyList(party_list &party_members);

  shared_ptr<PartyMember> getAwaitingCommand();
  shared_ptr<Enemy> getTargetedEnemy();

  void drawPartyText();
  void drawCommandText();
  void drawCommandBar();
  void drawTargetingReticle();
  void drawMainFrame();

  party_list::iterator *awaiting_command;
  enemy_list::iterator *targeted_enemy;
  array<int, 4>::iterator *selected_command;

private:
  Texture frame;

  Font main_font;
  int text_spacing;

  party_list *party_members;

  RenderTexture command_bar;
  Texture command_frame;
  Rectangle command_source;
  Rectangle command_dest;

  Texture target_reticle;
  Rectangle reticle_source;
  Rectangle reticle_dest;
  Vector2 reticle_origin;
};
