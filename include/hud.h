// hud.h
#pragma once
#include <raylib.h>
#include <string>
#include <array>
#include "battle_system/party_members.h"

using std::string, std::array;


class Hud {
public:
  Hud();
  ~Hud();

  void setupCommandBar();

  void assignPartyList(party_list &party_members);
  void drawPartyText();
  void drawCommandBar();
  void drawMainFrame();

private:
  Texture frame;

  Font main_font;
  int text_spacing;

  party_list *party_members;

  RenderTexture command_bar;
  Texture command_frame;
  Rectangle command_source;
  Rectangle command_dest;
};
