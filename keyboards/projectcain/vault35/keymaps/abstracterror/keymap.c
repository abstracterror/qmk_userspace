/* Copyright 2024 @abstracterror
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_4space(
        KC_Q,    KC_W,    LT_E,    LT_R,    KC_T,    KC_Y,    LT_U,    KC_I,    KC_O,    KC_P,    KC_F12,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN,
        MT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MT_SLSH,
                          KC_MEH,  LT_TAB,  MT_TAB,  LT_SPC,  MO_LSYM, KC_ENT
    ),

    [_FUN] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
                          XXXXXXX, XXXXXXX, _______, LT_F10,  KC_F11,  XXXXXXX
    ),

    [_NUM] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    _______, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PIPE,
                          XXXXXXX, XXXXXXX, _______, LT_0,    MO_TSYM, XXXXXXX
    ),

    [_LSYM] = LAYOUT_split_4space(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, MO_TSYM, _______, _______, XXXXXXX, XXXXXXX
    ),

    [_TSYM] = LAYOUT_split_4space(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMD, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,
                          XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_split_4space(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                          XXXXXXX, XXXXXXX, MT_CWT,  _______, XXXXXXX, XXXXXXX
    ),
};
