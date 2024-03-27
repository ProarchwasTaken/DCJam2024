// hud.cpp
#include <raylib.h>
#include "hud.h"
#include "battle_system/party_members.h"


Hud::Hud() {
  main_font = LoadFont("graphics/fonts/vcr.ttf");
  frame = LoadTexture("graphics/sprites/frame.png");

  text_spacing = 45;
  setupCommandBar();
}

Hud::~Hud() {
  UnloadTexture(frame);
  UnloadTexture(command_frame);
  UnloadRenderTexture(command_bar);
}

void Hud::assignPartyList(party_list &party_members) {
  this->party_members = &party_members;
}

void Hud::setupCommandBar() {
  command_bar = LoadRenderTexture(629, 43);
  command_frame = LoadTexture("graphics/sprites/command_bar.png");
  command_source = {0, 0, 629, 43};
  command_dest = {86, 333, 629, 43};
}

void Hud::drawPartyText() {
  float y = 420;
  for (auto member : *party_members) {
    const char *name = TextFormat("%s", member->name.c_str());
    const char *hp = TextFormat("%02i/%02i", member->hp, member->max_hp);
    const char *sp = TextFormat("%02i", member->sp);
    const char *status = member->getStatusString();

    DrawTextEx(main_font, name, {75, y}, 30, 3, WHITE);
    DrawTextEx(main_font, hp, {260, y}, 30, 3, WHITE);
    DrawTextEx(main_font, sp, {465, y}, 30, 3, WHITE);
    DrawTextEx(main_font, status, {580, y}, 30, 3, WHITE);

    y += text_spacing; 
  }
}

void Hud::drawMainFrame() {
  DrawTexture(frame, 0, 0, WHITE);
}

void Hud::drawCommandBar() {
  BeginTextureMode(command_bar); 
  {
    DrawTexture(command_frame, 0, 0, WHITE);
  }
  EndTextureMode();

  DrawTexturePro(
    command_bar.texture, command_source, command_dest, {0, 0}, 0, WHITE
  );
}
