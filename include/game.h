// Kaputchip Advance by HusYada
#ifndef GAME_H
#define GAME_H

// All Includes (dunno if i need all this)
#include "bn_bg_palettes.h"
#include "bn_blending.h"
#include "bn_camera_actions.h"
#include "bn_color.h"
#include "bn_core.h"
#include "bn_display.h"
#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_math.h"
#include "bn_rect_window.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_palette_actions.h"
#include "bn_sprite_palettes_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_string.h"
#include "bn_time.h"
#include "bn_unique_ptr.h"
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "load_attributes.h"
// audio player
#include "bn_music.h"
//#include "bn_music_items.h"
#include "bn_format.h"
#include "bn_config_audio.h"
#include "bn_sound_actions.h"
#include "bn_sound_items.h"

// Backgrounds
#include "bn_regular_bg_items_test_map_2.h"
#include "bn_regular_bg_items_test_map_3.h"
// #include "bn_regular_bg_items_bg_loop.h"

// Sprites.h"
#include "bn_sprite_items_bg_loop.h"
#include "bn_sprite_items_big_heart.h"
#include "bn_sprite_items_body.h"
#include "bn_sprite_items_bullet.h"
#include "bn_sprite_items_cursor.h"
#include "bn_sprite_items_e_blu.h"
#include "bn_sprite_items_e_bug.h"
#include "bn_sprite_items_e_itm.h"
#include "bn_sprite_items_e_jng.h"
#include "bn_sprite_items_e_pnk.h"
#include "bn_sprite_items_legs.h"
#include "bn_sprite_items_rarm.h"
#include "bn_sprite_items_p_shadow.h"
#include "bn_sprite_items_small_heart.h"

// Variables
bn::string<64> testing_text;
int scene = 0;
int px, py, speed = 1, bgx, bgy, bgspd, dx, dy;
int scrollx = 0, scrolly = 0, shrlx = 0, shrly = 0; // SHadow ScRoLl

bool walking;
int pa = 0; int paa = 0;

int direction; // 0 is front, 2 is side, 4 is back

#endif