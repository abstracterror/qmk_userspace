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
#include "g/keymap_combo.h"

enum layer_names {
    _BASE,
    _FUN,
    _NUM,
    _RSYM,
    _MOUSE,
    _LSYM,
    _TSYM,
    _NAV
};

#define LT_F    LT(_FUN,  KC_F)
#define LT_P    LT(_RSYM, KC_P)
#define LT_TAB  LT(_NUM,  KC_TAB)
#define LT_SPC  LT(_NAV,  KC_SPC)
#define MO_LSYM MO(_LSYM)
#define MO_TSYM MO(_TSYM)

#define MT_A    MT(MOD_LCTL, KC_A)
#define MT_R    MT(MOD_LSFT, KC_R)
#define MT_S    MT(MOD_LGUI, KC_S)
#define MT_T    MT(MOD_LALT, KC_T)

#define MT_N    MT(MOD_LALT, KC_N)
#define MT_E    MT(MOD_LGUI, KC_E)
#define MT_I    MT(MOD_LSFT, KC_I)
#define MT_O    MT(MOD_LCTL, KC_O)

#define MT_ESC  MT(MOD_LCTL | MOD_LSFT | MOD_LGUI, KC_ESC)
#define MT_CAPS MT(MOD_LCTL, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,             KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          MT_ESC,  LT_TAB,  KC_LSFT,          LT_SPC,  MO_LSYM, KC_ENT
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
                          XXXXXXX, XXXXXXX, _______,          KC_F10,  KC_F11,  XXXXXXX
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PIPE,
                          XXXXXXX, XXXXXXX, _______,          KC_0,    MO_TSYM, XXXXXXX
    ),

    [_RSYM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_AMPR, KC_ASTR, KC_GRV,  XXXXXXX,
                          XXXXXXX, XXXXXXX, _______,          KC_TILD, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, SCRL_MO,          SCRL_MO, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_LCTL, KC_LALT, _______,          KC_LSFT, KC_LALT, KC_LCTL
    ),

    [_LSYM] = LAYOUT(
        KC_COLN, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,          XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LGUI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, MO_TSYM, _______,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_TSYM] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,
        MT_CAPS, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                          XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX
    )
};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [2] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [3] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [4] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [5] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [6] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [7] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif


bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case KC_LCTL:
        return true;
      case KC_LSFT:
        return true;
      case SCRL_MO:
        return true;
      default:
        return false;
    }
    return is_mouse_record_user(keycode, record);
}


/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        //rgblight_sethsv_range(HSV_YELLOW, 0, 9);
        cocot_set_scroll_mode(true);
        break;
    case 2:
        //rgblight_sethsv_range(HSV_GREEN, 0, 9);
        cocot_set_scroll_mode(true);
        break;
    case 3:
        //rgblight_sethsv_range(HSV_CYAN, 0, 9);
        cocot_set_scroll_mode(false);
        break;
    case 4:
        //rgblight_sethsv_range(HSV_AZURE, 0, 9);
        cocot_set_scroll_mode(false);
        break;
    case 5:
        //rgblight_sethsv_range(HSV_BLUE, 0, 9);
        cocot_set_scroll_mode(false);
        break;
    case 6:
        //rgblight_sethsv_range(HSV_MAGENTA, 0, 9);
        cocot_set_scroll_mode(false);
        break;
    case 7:
        //rgblight_sethsv_range(HSV_MAGENTA, 0, 9);
        cocot_set_scroll_mode(false);
        break;
    default:
        //rgblight_sethsv_range(HSV_RED, 0, 9);
        cocot_set_scroll_mode(false);
        break;
    }
    //rgblight_set_effect_range( 9, 36);
  return state;
};
*/

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
    set_auto_mouse_enable(true);
}
