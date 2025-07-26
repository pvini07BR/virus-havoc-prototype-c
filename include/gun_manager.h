#ifndef GUN_MANAGER_H
#define GUN_MANAGER_H

#include "bullet_manager.h"
#include <raylib.h>

typedef struct Gun {
    const char* name;
    const char* texPath;
    Texture2D tex;
    void (*fire)(struct Gun* self, BulletManager* bm, Vector2 rootPosition);
    void (*draw)(struct Gun* self, Vector2 position);
} Gun;

void gun_manager_init_guns();
Gun* get_gun(unsigned int index);

#endif