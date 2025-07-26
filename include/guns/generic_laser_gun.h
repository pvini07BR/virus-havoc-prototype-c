#ifndef GENERIC_LASER_GUN_H
#define GENERIC_LASER_GUN_H

#include "gun_manager.h"

void generic_laser_gun_fire(Gun* gun, BulletManager* bm, Vector2 rootPosition);
void generic_laser_gun_draw(Gun* gun, Vector2 position);

#endif