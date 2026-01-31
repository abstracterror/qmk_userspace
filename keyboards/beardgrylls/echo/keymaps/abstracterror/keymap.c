#include QMK_KEYBOARD_H
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L',      '*', '*',  '*', '*',      'R', 'R', 'R'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_F1,   KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,       KC_J,    LT_L,    KC_U,    KC_Y,    KC_SCLN, KC_F12,
        KC_F5,   MT_A,    MT_R,    MT_S,    MT_T,    KC_G,       KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_F8,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, AE_MEH,           XXXXXXX, MT_TAB,     LT_SPC,  XXXXXXX,          QK_REP,  KC_F10,  KC_F11
    ),

    [_NUM] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    UM_EURO, KC_7,    KC_8,    KC_9,    KC_PIPE, _______,
        _______, _______, _______,          _______, _______,    LT_0,    _______,          _______, _______, _______
    ),

    [_FUN] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, _______, UK_TOGG, QK_BOOT,    XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, _______,
        _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F11,  _______,
        _______, _______, _______,          _______, _______,    LT_F10,  _______,          _______, _______, _______
    ),

    [_LSYM] = LAYOUT(
        _______, XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,    XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______,          _______, _______,    _______, _______,          _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK,    XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX, _______,
        _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______,
        _______, UNDO,    CUT,     COPY,    PASTE,   XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,
        _______, _______, _______,          _______, KC_LSFT,    _______, _______,          _______, _______, _______
    ),
};
