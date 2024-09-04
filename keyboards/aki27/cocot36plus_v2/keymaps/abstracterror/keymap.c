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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,             KC_J,    LT_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,             KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        LT_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_MEH,  LT_TAB,  MT_TAB,           LT_SPC,  MO_LSYM, KC_ENT
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT,          XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F11,
                          XXXXXXX, XXXXXXX, _______,          LT_F10,  XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PIPE,
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
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, CPI_SW,  SCRL_SW, XXXXXXX, XXXXXXX,
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


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _NUM:
        cocot_set_scroll_mode(true);
        state = remove_auto_mouse_layer(state, false);
        set_auto_mouse_enable(false);
        break;
    default:
        cocot_set_scroll_mode(false);
        set_auto_mouse_enable(true);
        break;
    }
  return state;
};

#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { 
    int is_layer = get_highest_layer(layer_state|default_layer_state);  
    HSV hsv = {0, 255, rgblight_get_val()};
    if (is_layer == 1) {
      hsv.h = 11; //CORAL
    } else if (is_layer == 2)  {
      hsv.h = 85; //GREEN
    } else if (is_layer == 3)  {
      hsv.h = 43; //YELLOW
    } else if (is_layer == 4)  {
      hsv.h = 0; //RED
    } else if (is_layer == 5)  {
      hsv.h = 191; //PURPLE
    } else if (is_layer == 6)  {
      hsv.h = 64; //CHARTREUSE
    } else if (is_layer == 7)  {
      hsv.h = 224;
    } else {
      hsv.h = 128; //CYAN
    }
    RGB rgb = hsv_to_rgb(hsv);
 
    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
};

#endif


void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}
