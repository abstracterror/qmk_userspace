#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layer_names {
    _BASE,
    _FUN,
    _NUM,
    _RSYM,
    _LSYM,
    _TSYM,
    _NAV
};

#define LT_F    LT(_FUN,   KC_F)
#define LT_P    LT(_RSYM,  KC_P)
#define LT_TAB  LT(_NUM,   KC_TAB)
#define LT_SPC  LT(_NAV,   KC_SPC)
#define LT_0    LT(_NAV,   KC_0)
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
                 KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
                 MT_A,    MT_R,    MT_S,    MT_T,    KC_G,       KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Q,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN,
                                   MT_ESC,  LT_TAB,  KC_LSFT,    LT_SPC,  MO_LSYM, KC_ENT
    ),

    [_FUN] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, _______,    KC_F10,  KC_F11,  XXXXXXX
    ),

    [_NUM] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PIPE, XXXXXXX,
                                   XXXXXXX, XXXXXXX, _______,    LT_0,    MO_TSYM, XXXXXXX
    ),

    [_RSYM] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_AMPR, KC_ASTR, KC_GRV,  XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, _______,    KC_TILD, XXXXXXX, XXXXXXX
    ),

    [_LSYM] = LAYOUT(
                 KC_COLN, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, MO_TSYM, _______,    XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_TSYM] = LAYOUT(
                 KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,
                 MT_CAPS, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS, XXXXXXX,
                                   XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

void keyboard_pre_init_user(void) {
    // turn off the red user-addressable LED (GPIO 17)
    setPinOutput(17);
    writePinHigh(17);

    // turn off the green user-addressable LED (GPIO 16)
    setPinOutput(16);
    writePinHigh(16);

    // turn off the blue user-addressable LED (GPIO 25)
    setPinOutput(25);
    writePinHigh(25);
}
