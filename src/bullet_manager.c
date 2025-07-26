#include "bullet_manager.h"
#include "defines.h"

void bullet_manager_init(BulletManager* bm) {
    if (!bm) return;

    bm->active_bullet_count = 0;
    bm->next_bullet = 0;
    for (int i = 0; i < MAX_BULLETS; i++) {
        bm->bullets[i].active = false;
    }
}

void bullet_manager_shoot_bullet(BulletManager* bm, Vector2 pos, Vector2 vel, Color color) {
    if (!bm) return;
    
    int index = bm->next_bullet;
    
    if (bm->bullets[index].active) {
        bool found = false;
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bm->bullets[i].active) {
                index = i;
                found = true;
                break;
            }
        }
        if (!found) {
            index = bm->next_bullet;
        }
    }
    
    bm->bullets[index].position = pos;
    bm->bullets[index].velocity = vel;
    bm->bullets[index].color = color;
    bm->bullets[index].active = true;
    bm->active_bullet_count++;
    
    bm->next_bullet = (bm->next_bullet + 1) % MAX_BULLETS;
}

void bullet_manager_update(BulletManager* bm) {
    if (!bm) return;

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bm->bullets[i].active) continue;
        bm->bullets[i].position.x += bm->bullets[i].velocity.x * GetFrameTime();
        bm->bullets[i].position.y += bm->bullets[i].velocity.y * GetFrameTime();
        
        if (bm->bullets[i].position.x < 0 || bm->bullets[i].position.x > WINDOW_WIDTH || 
            bm->bullets[i].position.y < 0 || bm->bullets[i].position.y > WINDOW_HEIGHT) {
            bm->bullets[i].active = false;
            bm->active_bullet_count--;
        }
    }
}

void bullet_manager_draw(BulletManager* bm) {
    if (!bm) return;

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bm->bullets[i].active) continue;
        DrawCircleV(bm->bullets[i].position, 2.5f, bm->bullets[i].color);
    }
}