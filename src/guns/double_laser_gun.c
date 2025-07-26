#include "guns/double_laser_gun.h"
#include "bullet_manager.h"
#include <raylib.h>
#include <raymath.h>

bool dlg_cooldown = false;
double dlg_lastTime = 0.0;

void double_laser_gun_fire(Gun* gun, BulletManager* bm, Vector2 rootPosition) {
    if (!gun || !bm) return;

    if (!dlg_cooldown) {
        Vector2 topShootPoint = Vector2Add(rootPosition, (Vector2){ 38, 7 });
        Vector2 bottomShootPoint = Vector2Add(rootPosition, (Vector2){ 38, 18 });

        bullet_manager_shoot_bullet(bm, topShootPoint, (Vector2){1000, 0}, BLUE);
        bullet_manager_shoot_bullet(bm, bottomShootPoint, (Vector2){1000, 0}, BLUE);

        dlg_lastTime = GetTime();
        dlg_cooldown = true;
    } else {
        if ((GetTime() - dlg_lastTime) >= 0.2) dlg_cooldown = false;
    }
}

void double_laser_gun_draw(Gun* gun, Vector2 position) {
    if (!gun) return;

    DrawTextureEx(
        gun->tex,
        position,
        0.0f,
        1.0f,
        WHITE
    );
}