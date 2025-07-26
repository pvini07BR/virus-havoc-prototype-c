#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>

#include "bullet_manager.h"
#include "defines.h"
#include "string_utils.h"
#include "player.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Virus Havoc");

    Camera2D camera = { 0 };

    gun_manager_init_guns();

    Player player;
    player_init(&player, (Vector2){WINDOW_WIDTH/4.0f, WINDOW_HEIGHT/2.0f});

    BulletManager bulletManager;
    bullet_manager_init(&bulletManager);

    bool cooldown = false;
    double lastTime = 0.0;

    char* info = NULL;

    while (!WindowShouldClose()) {
        float scale = fmin((float)GetScreenWidth() / WINDOW_WIDTH, (float)GetScreenHeight() / WINDOW_HEIGHT);
        float scissorWidth = (int)(WINDOW_WIDTH * scale);
        float scissorHeight = (int)(WINDOW_HEIGHT * scale);
        float scissorX = (GetScreenWidth() - scissorWidth) / 2.0f;
        float scissorY = (GetScreenHeight() - scissorHeight) / 2.0f;

        camera.zoom = scale;
        camera.offset = (Vector2){ scissorX, scissorY };

        player_update(&player, &bulletManager);
        bullet_manager_update(&bulletManager);

        if (GetTime() - lastTime >= 0.1) {
            cooldown = false;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        BeginScissorMode(scissorX, scissorY, scissorWidth, scissorHeight);
        BeginMode2D(camera);

        ClearBackground((Color){77, 77, 77, 255});

        bullet_manager_draw(&bulletManager);

        player_draw(&player);

        EndMode2D();

        if (info) free(info);
        info = formatted_string(
            "FPS: %d\nBullets: %d/%d\nEquipped gun: %s",
            GetFPS(),
            bulletManager.active_bullet_count,
            MAX_BULLETS,
            get_player_equipped_gun(&player)->name
        );
        DrawText(info, 0, 0, 20, WHITE);

        EndScissorMode();
        EndDrawing();
    }
    player_destroy(&player);
    CloseWindow();
}