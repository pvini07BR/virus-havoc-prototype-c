#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#define MAX_BULLETS 5000

#include <raylib.h>

typedef struct {
    Vector2 position;
    Vector2 velocity;
    Color color;
    bool active;
} Bullet;

typedef struct {
    Bullet bullets[MAX_BULLETS];
    int next_bullet;
    int active_bullet_count;
} BulletManager;

void bullet_manager_init(BulletManager* bm);
void bullet_manager_shoot_bullet(BulletManager* bm, Vector2 pos, Vector2 vel, Color color);
void bullet_manager_update(BulletManager* bm);
void bullet_manager_draw(BulletManager* bm);

#endif