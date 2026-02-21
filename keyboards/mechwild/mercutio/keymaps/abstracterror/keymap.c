/* Copyright 2026 @abstracterror
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
    [_BASE] = LAYOUT_full_lshift(
                                                                                                                    KC_MUTE,
        KC_TAB,           KC_Q,    KC_W,    LT_E,    LT_R,    KC_T,    KC_Y,    LT_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL,          MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           MT_SLSH,
        AE_MEH,  KC_LGUI, KC_LALT,          MT_TAB,  MO_TOP,           LT_SPC,           KC_RALT, KC_RGUI,          AE_MEH
    ),

    [_TOP] = LAYOUT_full_lshift(
                                                                                                                    _______,
        _______,          UM_AND,  UM_OR,   UM_INTS, UM_UNIO, UM_SUBS, UM_SUPS, UM_FALL, UM_INF,  UM_EXST, UM_PDIF, _______,
        _______,          UM_BTTM, UM_TOP,  UM_RTAC, UM_LTAC, UM_UP,   UM_DOWN, UM_LEFT, UM_RGHT, UM_LR,   _______, _______,
        _______,          UM_LFLR, UM_LCEI, UM_NEQL, UM_AEQL, UM_IDEN, UM_LEQL, UM_GEQL, _______, _______,          _______,
        _______, _______, _______,          KC_LSFT, _______,          _______,          _______, _______,          _______
    ),

    [_FUN] = LAYOUT_full_lshift(
                                                                                                                    _______,
        _______,          XXXXXXX, XXXXXXX, _______, UK_TOGG, QK_BOOT, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, _______,
        _______,          KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,            XXXXXXX,
        _______, _______, _______,          KC_LSFT, _______,          LT_F10,           _______, _______,          _______
    ),

    [_NUM] = LAYOUT_full_lshift(
                                                                                                                    _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
        _______,          KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UM_EURO, KC_7,    KC_8,    KC_9,             KC_PIPE,
        _______, _______, _______,          KC_LSFT, _______,          LT_0,             _______, _______,          _______
    ),

    [_LSYM] = LAYOUT_full_lshift(
                                                                                                                    _______,
        _______,          XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______,          KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        _______, _______, _______,          KC_LSFT, _______,          LT_0,             _______, _______,          _______
    ),

    [_NAV] = LAYOUT_full_lshift(
                                                                                                                    _______,
        _______,          XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX, _______,
        _______,          KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______,
        _______,          UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,           KC_INS,
        _______, _______, _______,          KC_LSFT, _______,          LT_0,             _______, _______,          _______
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_TOP]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FUN]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_NUM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LSYM] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_NAV]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
