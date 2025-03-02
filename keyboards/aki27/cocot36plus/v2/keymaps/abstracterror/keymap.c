/*
Copyright 2023 @abstracterror

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

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'L',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
              '*', '*', '*',  '*', '*', '*'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,             KC_J,    LT_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,             KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        LT_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          XXXXXXX, KC_MEH,  MT_TAB,           LT_SPC,  MO_LSYM, QK_REP
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT,          XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F11,
                          XXXXXXX, XXXXXXX, _______,          LT_F10,  XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          UM_EURO, KC_7,    KC_8,    KC_9,    KC_PIPE,
                          XXXXXXX, XXXXXXX, _______,          LT_0,    MO_TSYM, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
        KC_ESC,  _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
                          KC_BTN2, SCRL_MO, KC_BTN1,          _______, _______, _______
    ),

    [_LSYM] = LAYOUT(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,          XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, MO_TSYM, _______,          _______, XXXXXXX, XXXXXXX
    ),

    [_TSYM] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          RM_NEXT, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU,
        QK_BOOT, AM_TOG,  SCRL_IN, XXXXXXX, XXXXXXX,          XXXXXXX, CPI_SW,  SCRL_SW, ROT_L15, ROT_R15,
                          XXXXXXX, XXXXXXX, _______,          _______, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK,          XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                          XXXXXXX, XXXXXXX, MT_CWT,           _______, XXXXXXX, XXXXXXX
    ),
};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]  = { ENCODER_CCW_CW(PREVIOUS_TASK, NEXT_TASK) },
    [_FUN]   = { ENCODER_CCW_CW(UNDO,    REDO) },
    [_NUM]   = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_MOUSE] = { ENCODER_CCW_CW(_______, _______) },
    [_LSYM]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_TSYM]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_NAV]   = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case KC_LCTL:
        case KC_LSFT:
        case KC_LGUI:
        case KC_LALT:
        case SCRL_MO:
            return true;
        default:
            return false;
    }
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
}
