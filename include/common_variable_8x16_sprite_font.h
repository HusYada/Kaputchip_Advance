/*
 * Copyright (c) 2020-2023 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef COMMON_VARIABLE_8x16_SPRITE_FONT_H
#define COMMON_VARIABLE_8x16_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_common_variable_8x16_font.h"

namespace common
{

constexpr bn::utf8_character variable_8x16_sprite_font_utf8_characters[] = {
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿"
};

constexpr int8_t variable_8x16_sprite_font_character_widths[] = {
    2,  // 32 space (OG=6)
    4,  // 33 !
    4,  // 34 " (OG=7)
    6,  // 35 # (OG=8)
    8,  // 36 $
    7,  // 37 %
    6,  // 38 & (OG=8)
    3,  // 39 ' (OG=4)
    3,  // 40 ( (OG=5)
    3,  // 41 ) (OG=5)
    7,  // 42 *
    6,  // 43 + (OG=7)
    3,  // 44 , (OG=4)
    5,  // 45 - (OG=7)
    2,  // 46 . (OG=4)
    7,  // 47 /
    5,  // 48 0 (OG=7)
    5,  // 49 1 (OG=4)
    5,  // 50 2 (OG=7)
    5,  // 51 3 (OG=7)
    5,  // 52 4 (OG=7)
    5,  // 53 5 (OG=7)
    5,  // 54 6 (OG=7)
    5,  // 55 7 (OG=7)
    5,  // 56 8 (OG=7)
    5,  // 57 9 (OG=7)
    2,  // 58 : (OG=4)
    2,  // 59 ; (OG=4)
    6,  // 60 <
    7,  // 61 =
    6,  // 62 >
    6,  // 63 ? (OG=7)
    8,  // 64 @
    5,  // 65 A (OG=7)
    5,  // 66 B (OG=7)
    5,  // 67 C (OG=7)
    5,  // 68 D (OG=7)
    5,  // 69 E (OG=7)
    5,  // 70 F (OG=7)
    5,  // 71 G (OG=7)
    5,  // 72 H (OG=7)
    4,  // 73 I (OG=5)
    5,  // 74 J (OG=7)
    5,  // 75 K (OG=7)
    5,  // 76 L (OG=7)
    6,  // 77 M (OG=8)
    5,  // 78 N (OG=7)
    5,  // 79 O (OG=7)
    5,  // 80 P (OG=7)
    6,  // 81 Q (OG=8)
    5,  // 82 R (OG=7)
    5,  // 83 S (OG=7)
    6,  // 84 T (OG=7)
    5,  // 85 U (OG=7)
    6,  // 86 V (OG=7)
    6,  // 87 W (OG=8)
    5,  // 88 X (OG=7)
    6,  // 89 Y (OG=7)
    5,  // 90 Z (OG=7)
    5,  // 91 [
    7,  // 92
    5,  // 93 ]
    3,  // 94 ^ (OG=4)
    5,  // 95 _ (OG=7)
    3,  // 96 ` (OG=4)
    5,  // 97 a (OG=7)
    5,  // 98 b (OG=7)
    5,  // 99 c (OG=7)
    5,  // 100 d (OG=7)
    5,  // 101 e (OG=7)
    5,  // 102 f (OG=6)
    5,  // 103 g (OG=7)
    5,  // 104 h (OG=7)
    2,  // 105 i (OG=3)
    3,  // 106 j (OG=4)
    4,  // 107 k (OG=6)
    2,  // 108 l (OG=3)
    6,  // 109 m (OG=8)
    5,  // 110 n (OG=7)
    5,  // 111 o (OG=7)
    5,  // 112 p (OG=7)
    5,  // 113 q (OG=7)
    4,  // 114 r (OG=6)
    5,  // 115 s (OG=7)
    4,  // 116 t (OG=6)
    5,  // 117 u (OG=7)
    6,  // 118 v (OG=7)
    6,  // 119 w (OG=8)
    6,  // 120 x (OG=7)
    5,  // 121 y (OG=7)
    5,  // 122 z (OG=7)
    6,  // 123 {
    3,  // 124 |
    6,  // 125 }
    8,  // 126 ~
    7,  // Á
    7,  // É
    5,  // Í
    7,  // Ó
    7,  // Ú
    7,  // Ü
    7,  // Ñ
    7,  // á
    7,  // é
    4,  // í
    7,  // ó
    7,  // ú
    7,  // ü
    7,  // ñ
    3,  // ¡
    7,  // ¿
};

constexpr bn::span<const bn::utf8_character> variable_8x16_sprite_font_utf8_characters_span(
        variable_8x16_sprite_font_utf8_characters);

constexpr auto variable_8x16_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<variable_8x16_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font variable_8x16_sprite_font(
        bn::sprite_items::common_variable_8x16_font, variable_8x16_sprite_font_utf8_characters_map.reference(),
        variable_8x16_sprite_font_character_widths);

}

#endif
