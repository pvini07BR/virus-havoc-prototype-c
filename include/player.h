#ifndef PLAYER_H
#define PLAYER_H

#include "gun_manager.h"
#include "raylib.h"

#define GUN_SLOT_COUNT 2

typedef struct {
    Vector2 position;
    Vector2 velocity;
    unsigned int gun_index;
    Gun* guns[GUN_SLOT_COUNT];
    Texture2D tex;
} Player;

void player_init(Player* player, Vector2 pos);
void player_update(Player* player, BulletManager* bm);
void player_draw(Player* player);
void player_destroy(Player* player);

Gun* get_player_equipped_gun(Player* player);

#endif