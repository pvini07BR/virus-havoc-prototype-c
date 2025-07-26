#include "player.h"
#include "gun_manager.h"

#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>

const Vector2 GUN_ANCHOR = {3, 15};

void player_init(Player* player, Vector2 pos) {
    if (!player) return;
    
    player->position = pos;
    player->velocity = (Vector2){ 0, 0 };

    player->gun_index = 0;

    player->guns[0] = get_gun(0);
    player->guns[1] = get_gun(1);

    player->tex = LoadTexture("assets/sprites/player.png");
}

void player_update(Player* player, BulletManager* bm) {
    if (!player || !bm) return;

    Vector2 input = { 0 };
    input.x = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) ? 1 : (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) ? -1 : 0);
    input.y = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S) ? 1 : (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) ? -1 : 0);

    player->velocity = Vector2Lerp(player->velocity, Vector2Scale(Vector2Normalize(input), 400.0f), 15.0f * GetFrameTime());

    player->position.x += player->velocity.x * GetFrameTime();
    player->position.y += player->velocity.y * GetFrameTime();

    if (IsKeyDown(KEY_SPACE)) {
        Vector2 origin = Vector2Add(player->position, GUN_ANCHOR);
        Gun* currGun = player->guns[player->gun_index];
        if (currGun && currGun->fire) currGun->fire(currGun, bm, origin);
    }

    if (IsKeyPressed(KEY_Q)) {
        if (player->gun_index >= 1) player->gun_index--;
    }
    if (IsKeyPressed(KEY_E)) {
        if (player->gun_index < GUN_SLOT_COUNT) player->gun_index++;
    }
    player->gun_index = Clamp(player->gun_index, 0, GUN_SLOT_COUNT-1);
}

void player_draw(Player* player) {
    if (!player) return;

    rlPushMatrix();
    rlTranslatef(player->position.x, player->position.y, 0.0f);
    Gun* currGun = player->guns[player->gun_index];
    if (currGun && currGun->draw) currGun->draw(currGun, GUN_ANCHOR);
    DrawTextureEx(
        player->tex,
        (Vector2){ -37, -38 },
        0.0f,
        1.0f,
        WHITE
    );
    rlPopMatrix();
}

void player_destroy(Player* player) {
    if (!player) return;

    UnloadTexture(player->tex);
}

Gun* get_player_equipped_gun(Player* player) {
    return player->guns[player->gun_index];
}