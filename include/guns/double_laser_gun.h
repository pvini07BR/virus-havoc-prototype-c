#ifndef DOUBLE_LASER_GUN_H
#define DOUBLE_LASER_GUN_H

#include "gun_manager.h"

void double_laser_gun_fire(Gun* gun, BulletManager* bm, Vector2 rootPosition);
void double_laser_gun_draw(Gun* gun, Vector2 position);

#endif