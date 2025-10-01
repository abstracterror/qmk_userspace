/* Copyright 2025 @abstracterror
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

#define INACTIVE_H 20
#define ACTIVE_H 160
#define BRIGHTNESS 10

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_split_4space(
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    '*', '*', '*', '*',       '*',      '*', '*', '*', '*'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_4space(
        KC_Q,    KC_W,    LT_E,    LT_R,    KC_T,    KC_Y,    LT_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SLSH, XXXXXXX,
        MT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, AE_MEH,  MT_TAB,           LT_SPC,           QK_REP,  XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_FUN] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   _______, _______,
        _______, _______, _______, _______,          LT_F10,           _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    _______, _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UM_EURO, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______,          LT_0,             _______, _______, _______, _______
    ),

    [_LSYM] = LAYOUT_split_4space(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        _______, _______, _______, _______,          _______,          _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_split_4space(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX, _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,
        KC_CAPS, _______, _______, MT_CWT,           _______,          _______, _______, _______, _______
    ),
};

void keyboard_post_init_user(void) {
    rgblight_sethsv_range(INACTIVE_H, 200, BRIGHTNESS, 0, 3);
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        rgblight_sethsv_at(ACTIVE_H, 200, BRIGHTNESS, 0);
    } else {
        rgblight_sethsv_at(INACTIVE_H, 200, BRIGHTNESS, 0);
    }
    return false;
}

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_at(ACTIVE_H, 200, BRIGHTNESS, 1);
    } else {
        rgblight_sethsv_at(INACTIVE_H, 200, BRIGHTNESS, 1);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    rgblight_sethsv_at(INACTIVE_H + (ACTIVE_H - INACTIVE_H) * layer / 4, 200, BRIGHTNESS, 2);
    return state;
}
