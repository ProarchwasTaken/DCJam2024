// hud.cpp
#include <cstddef>
#include <raylib.h>
#include <memory>
#include "hud.h"
#include "battle_system/constants.h"
#include "battle_system/party_members.h"

using std::shared_ptr;


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

  if (awaiting_command != NULL) {
    delete awaiting_command;
  }
}

void Hud::assignPartyList(party_list &party_members) {
  this->party_members = &party_members;
}

void Hud::setupCommandBar() {
  command_bar = LoadRenderTexture(629, 43);
  command_frame = LoadTexture("graphics/sprites/command_bar.png");
  command_source = {0, 0, 629, -43};
  command_dest = {86, 333, 629, 43};
}

shared_ptr<PartyMember> Hud::getAwaitingCommand() {;
  auto member = *awaiting_command->_M_const_cast();
  return member;
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

void Hud::drawCommandText() {
  for (int command = 0; command < 4; command++) {
    const char *text;
    Vector2 position;
    Color tint = WHITE;

    switch (command) {
      case COMMAND_ATTACK: {
        text = "ATTACK";
        position = {140, 8};
        break;
      }
      case COMMAND_SKILL: {
        text = "SKILL";
        position = {274, 8};
        break;
      }
      case COMMAND_DEFEND: {
        text = "DEFEND";
        position = {385, 8};
        break;
      }
      case COMMAND_FLEE: {
        text = "FLEE";
        position = {530, 8};
        break;
      }
    }

    DrawTextEx(main_font, text, position, 24, 2, tint);
  }
}

void Hud::drawCommandBar() {
  Texture *portrait = &getAwaitingCommand()->command_portrait;
  BeginTextureMode(command_bar); 
  {
    DrawTexture(command_frame, 0, 0, WHITE);
    drawCommandText();
    DrawTexture(*portrait, 4, 4, WHITE);
  }
  EndTextureMode();

  DrawTexturePro(
    command_bar.texture, command_source, command_dest, {0, 0}, 0, WHITE
  );
}
