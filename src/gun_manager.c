#include "gun_manager.h"
#include <stdlib.h>

#include "guns/double_laser_gun.h"
#include "guns/generic_laser_gun.h"

const unsigned int gun_count = 2;
static Gun guns[] = {
    {
        .name = "Generic Laser Gun",
        .texPath = "assets/sprites/guns/generic_laser_gun.png",
        .fire = generic_laser_gun_fire,
        .draw = generic_laser_gun_draw
    },
    {
        .name = "Double Laser Gun",
        .texPath = "assets/sprites/guns/double_laser_gun.png",
        .fire = double_laser_gun_fire,
        .draw = double_laser_gun_draw
    }
};

void gun_manager_init_guns() {
    for (unsigned int i = 0; i < gun_count; i++) {
        guns[i].tex = LoadTexture(guns[i].texPath);
    }
}

Gun* get_gun(unsigned int index) {
    if (index >= gun_count) return NULL;
    return &guns[index];
}