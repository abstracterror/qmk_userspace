#include QMK_KEYBOARD_H
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

#ifdef CADET_ALPHAS
#   define TP_Z LT(_TOP, KC_Z)
#   define TP_SLSH LT(_TOP, KC_SLSH)
#else
#   define TP_Z KC_Z
#   define TP_SLSH KC_SLSH
#endif

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
         'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', '*',  '*', 'R', 'R', 'R', 'R'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
                 KC_W,    LT_F,    LT_P,    KC_B,       KC_J,    LT_L,    KC_U,    KC_Y,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,       KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        TP_Z,    KC_X,    KC_C,    KC_D,    MT_TAB,     LT_SPC,  KC_H,    KC_COMM, KC_DOT,  TP_SLSH
    ),

#ifdef CADET_ALPHAS
    [_TOP] = LAYOUT(
                 UM_OR,   UM_INTS, UM_UNIO, UM_SUBS,    UM_SUPS, UM_FALL, UM_INF,  UM_EXST,
        UM_BTTM, UM_TOP,  UM_RTAC, UM_LTAC, UM_UP,      UM_DOWN, UM_LEFT, UM_RGHT, UM_LR,   UM_PDIF,
        UM_LFLR, UM_LCEI, UM_NEQL, UM_AEQL, KC_LSFT,    _______, UM_GEQL, _______, _______, _______
    ),
#endif

    [_FUN] = LAYOUT(
                 XXXXXXX, _______, UK_TOGG, QK_BOOT,    XXXXXXX, KC_F4,   KC_F5,   KC_F6,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,    LT_F10,  KC_F7,   KC_F8,   KC_F9,   KC_F11
    ),

    [_NUM] = LAYOUT(
                 XXXXXXX, XXXXXXX, _______, XXXXXXX,    UM_EURO, KC_4,    KC_5,    KC_6,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,    LT_0,    KC_7,    KC_8,    KC_9,    KC_PIPE
    ),

    [_LSYM] = LAYOUT(
                 KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,    XXXXXXX, _______, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
                 PREVTAB, NEXTTAB, REDO,    CTL_BRK,    KC_LEFT, XXXXXXX, KC_DEL,  KC_BSPC,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,     KC_HOME, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   KC_LSFT,    _______, KC_PGDN, KC_PGUP, KC_END,  KC_INS
    ),
};
