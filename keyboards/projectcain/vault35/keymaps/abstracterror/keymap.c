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
#include "g/keymap_combo.h"
#include "abstracterror.h"

enum layer_names {
    _BASE,
    _FUN,
    _NUM,
    _RSYM,
    _LSYM,
    _TSYM,
    _NAV
};

#define LT_E    LT(_FUN,   KC_E)
#define LT_R    LT(_RSYM,  KC_R)
#define LT_TAB  LT(_NUM,   KC_TAB)
#define LT_SPC  LT(_NAV,   KC_SPC)
#define LT_0    LT(_NAV,   KC_0)
#define MO_LSYM MO(_LSYM)
#define MO_TSYM MO(_TSYM)

#define MT_A    MT(MOD_LCTL, KC_A)
#define MT_S    MT(MOD_LSFT, KC_S)
#define MT_D    MT(MOD_LGUI, KC_D)
#define MT_F    MT(MOD_LALT, KC_F)
#define MT_Z    MT(MOD_LSFT, KC_Z)

#define MT_J    MT(MOD_LALT, KC_J)
#define MT_K    MT(MOD_LGUI, KC_K)
#define MT_L    MT(MOD_LSFT, KC_L)
#define MT_SCLN MT(MOD_LCTL, KC_SCLN)
#define MT_SLSH MT(MOD_LSFT, KC_SLSH)

#define MT_ESC  MT(MOD_LCTL | MOD_LSFT | MOD_LGUI, KC_ESC)
#define MT_CAPS MT(MOD_LCTL, KC_CAPS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_4space(
        KC_Q,    KC_W,    LT_E,    LT_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN,
        MT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MT_SLSH,
                          MT_ESC,  LT_TAB,  KC_LSFT, LT_SPC,  MO_LSYM, KC_ENT
    ),

    [_FUN] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
                          XXXXXXX, XXXXXXX, _______, KC_F10,  KC_F11,  XXXXXXX
    ),

    [_NUM] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    _______, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PIPE,
                          XXXXXXX, XXXXXXX, _______, LT_0,    MO_TSYM, XXXXXXX
    ),

    [_RSYM] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, KC_GRV,  XXXXXXX,
                          XXXXXXX, XXXXXXX, _______, KC_TILD, XXXXXXX, XXXXXXX
    ),

    [_LSYM] = LAYOUT_split_4space(
        KC_COLN, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, MO_TSYM, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_TSYM] = LAYOUT_split_4space(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_split_4space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL, KC_DEL,
        MT_CAPS, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                          XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
