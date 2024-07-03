#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "abstracterror.h"

enum layer_names {
    _BASE,
    _FUN,
    _NUM,
    _RSYM,
    _LSYM,
    _NAV
};

enum tap_dance_names {
    TD_LT_TILD
};

#define LT_F    LT(_FUN,   KC_F)
#define LT_P    LT(_RSYM,  KC_P)
#define LT_U    LT(_LSYM,  KC_U)
#define LT_TAB  LT(_NUM,   KC_TAB)
#define LT_SPC  LT(_NAV,   KC_SPC)
#define LT_0    LT(_NAV,   KC_0)
#define LT_F10  LT(_NAV,   KC_F10)
#define LT_TILD TD(TD_LT_TILD)

#define MT_A    MT(MOD_LCTL, KC_A)
#define MT_R    MT(MOD_LGUI, KC_R)
#define MT_S    MT(MOD_LALT, KC_S)
#define MT_T    MT(MOD_LSFT, KC_T)

#define MT_N    MT(MOD_LSFT, KC_N)
#define MT_E    MT(MOD_LALT, KC_E)
#define MT_I    MT(MOD_LGUI, KC_I)
#define MT_O    MT(MOD_LCTL, KC_O)

#define MT_CAPS MT(MOD_LCTL, KC_CAPS)

tap_dance_action_t tap_dance_actions[] = {
    [TD_LT_TILD] = ACTION_TAP_DANCE_LAYER_TAP(_NAV, KC_TILD)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,       KC_J,    KC_L,    LT_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,       KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    LT_TAB,     LT_SPC,  KC_H,    KC_COMM, KC_DOT,  KC_SLSH
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT,    XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    LT_F10,  KC_F7,   KC_F8,   KC_F9,   KC_F11
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    LT_0,    KC_7,    KC_8,    KC_9,    KC_PIPE
    ),

    [_RSYM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, _______,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    LT_TILD, KC_AMPR, KC_ASTR, KC_GRV,  XXXXXXX
    ),

    [_LSYM] = LAYOUT(
        KC_COLN, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,
        MT_CAPS, KC_LGUI, KC_LALT, KC_LSFT, KC_ESC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, KC_PGDN, KC_PGUP, KC_END,  KC_INS
    ),
};
