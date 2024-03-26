// hud.cpp
#include <raylib.h>
#include "hud.h"
#include "battle_system/party_members.h"


Hud::Hud() {
  main_font = LoadFont("graphics/fonts/vcr.ttf");
  frame = LoadTexture("graphics/sprites/frame.png");

  text_spacing = 45;
}

Hud::~Hud() {
  UnloadTexture(frame);
}

void Hud::assignPartyList(party_list &party_members) {
  this->party_members = &party_members;
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

void Hud::draw() {
  DrawTexture(frame, 0, 0, WHITE);

  drawPartyText();
}
