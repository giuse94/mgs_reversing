#include "linker.h"
#include "psyq.h"
#include "overlays/s00a/Enemy/enemy.h"

int SECTION("overlay.bss") s01a_dword_800E4B24;

short SECTION("overlay.bss") sphere_image_width_800E4B28;
short SECTION("overlay.bss") sphere_image_height_800E4B2A;
short SECTION("overlay.bss") sphere_visible_tiles_x_800E4B2C;
short SECTION("overlay.bss") sphere_visible_tiles_y_800E4B2E;
short SECTION("overlay.bss") sphere_tiles_x_800E4B30;
short SECTION("overlay.bss") sphere_tiles_y_800E4B32;
short SECTION("overlay.bss") sphere_tile_width_800E4B34;
short SECTION("overlay.bss") sphere_tile_height_800E4B36;
short SECTION("overlay.bss") sphere_elevation_800E4B38;
short SECTION("overlay.bss") sphere_word_800E4B3A;
