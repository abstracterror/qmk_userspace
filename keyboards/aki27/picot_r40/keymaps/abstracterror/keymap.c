/*
Copyright 2024 @abstracterror

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

#define MO_MOUS MO(_MOUSE)
#define TS_PREV PREVIOUS_TASK
#define TS_NEXT NEXT_TASK

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    '*', '*', '*', '*', '*',  '*', '*', '*', '*', '*'
);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    LT_E,    LT_R,    KC_T,    KC_Y,    LT_U,    KC_I,    KC_O,    KC_P,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SLSH,
        MT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    SCRL_TO, KC_N,    KC_M,    KC_COMM, MT_DOT,
        XXXXXXX, XXXXXXX, AE_MEH,  MT_TAB,  MS_BTN1, MS_BTN2, LT_SPC,  XXXXXXX, XXXXXXX, MO_MOUS
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, _______, UK_TOGG, QK_BOOT, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, LT_F10,  XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, UM_EURO, KC_7,    KC_8,    KC_9,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, LT_0,    XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_LSYM] = LAYOUT(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, KC_INS,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        XXXXXXX, XXXXXXX, XXXXXXX, MT_CWT,  _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, CPI_SW,  SCRL_SW, ROT_L15, ROT_R15,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(TS_PREV, TS_NEXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [5] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif
