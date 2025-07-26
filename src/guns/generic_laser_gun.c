#include "guns/generic_laser_gun.h"
#include "bullet_manager.h"
#include <raylib.h>
#include <raymath.h>

bool glg_cooldown = false;
double glg_lastTime = 0.0;

void generic_laser_gun_fire(Gun* gun, BulletManager* bm, Vector2 rootPosition) {
    if (!gun || !bm) return;

    if (!glg_cooldown) {
        Vector2 shootPoint = Vector2Add(rootPosition, (Vector2){ 38, 18 });
        bullet_manager_shoot_bullet(bm, shootPoint, (Vector2){1000, 0}, RED);
        glg_lastTime = GetTime();
        glg_cooldown = true;
    } else {
        if ((GetTime() - glg_lastTime) >= 0.1) glg_cooldown = false;
    }
}

void generic_laser_gun_draw(Gun* gun, Vector2 position) {
    if (!gun) return;

    DrawTextureEx(
        gun->tex,
        position,
        0.0f,
        1.0f,
        WHITE
    );
}