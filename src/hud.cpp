// hud.cpp
#include <raylib.h>
#include <memory>
#include "hud.h"
#include "battle_system/constants.h"
#include "battle_system/party_members.h"
#include "battle_system/enemy.h"

using std::shared_ptr;


Hud::Hud(Font &main_font) {
  this->main_font = &main_font;
  frame = LoadTexture("graphics/sprites/frame.png");

  text_spacing = 45;
  setupCommandBar();
  setupTargetReticle();
  setupTextBox();
}

Hud::~Hud() {
  UnloadTexture(frame);
  UnloadTexture(command_frame);
  UnloadRenderTexture(command_bar);

  UnloadTexture(target_reticle);

  UnloadTexture(box_frame);
  UnloadRenderTexture(text_box);
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

void Hud::setupTargetReticle() {
  target_reticle = LoadTexture("graphics/sprites/target_reticle.png");
  reticle_source = {0, 0, 92, 44};
  reticle_dest = {0, 0, 92, 44};
  reticle_origin = {46, 44};
}

void Hud::setupTextBox() {
  text_box = LoadRenderTexture(611, 126);
  box_frame = LoadTexture("graphics/sprites/text_box.png");
  box_source = {0, 0, 611, -126};
  box_dest = {95, 294, 611, 126};
}

shared_ptr<PartyMember> Hud::getAwaitingCommand() {
  auto member = *awaiting_command->_M_const_cast();
  return member;
}

shared_ptr<Enemy> Hud::getTargetedEnemy() {
  auto enemy = *targeted_enemy->_M_const_cast();
  return enemy;
}

void Hud::drawPartyText() {
  float y = 420;
  for (auto member : *party_members) {
    const char *name = TextFormat("%s", member->name.c_str());
    const char *hp = TextFormat("%02i/%02i", member->hp, member->max_hp);
    const char *sp = TextFormat("%02i", member->sp);
    const char *status = member->getStatusString();

    DrawTextEx(*main_font, name, {75, y}, 30, 3, WHITE);
    DrawTextEx(*main_font, hp, {260, y}, 30, 3, WHITE);
    DrawTextEx(*main_font, sp, {465, y}, 30, 3, WHITE);
    DrawTextEx(*main_font, status, {580, y}, 30, 3, WHITE);

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
        position = {145, 8};
        break;
      }
      case COMMAND_SKILL: {
        text = "SKILL";
        position = {275, 8};
        break;
      }
      case COMMAND_DEFEND: {
        text = "DEFEND";
        position = {390, 8};
        break;
      }
      case COMMAND_FLEE: {
        text = "FLEE";
        position = {530, 8};
        break;
      }
    }

    if (command == **selected_command) {
      tint = RED;
    }

    DrawTextEx(*main_font, text, position, 24, 0, tint);
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

void Hud::drawTargetingReticle() {
  auto targeted_enemy = getTargetedEnemy();

  int x = targeted_enemy->position.x + targeted_enemy->origin.x;
  int y = targeted_enemy->position.y;

  reticle_dest.x = x; 
  reticle_dest.y = y;

  DrawTexturePro(target_reticle, reticle_source, reticle_dest, 
                 reticle_origin, 0, WHITE);
}

void Hud::drawTextBox() {
  BeginTextureMode(text_box);
  {
    DrawTexture(box_frame, 0, 0, WHITE);
    DrawTextEx(*main_font, text_buffer.c_str(), {10, 10}, 32, 0, WHITE);
  }
  EndTextureMode();

  DrawTexturePro(text_box.texture, box_source, box_dest, 
                 {0, 0}, 0, WHITE);
}
