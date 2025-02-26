#include QMK_KEYBOARD_H
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

#ifdef PHOENICIAN_ENABLE
#define PH_TOG TG(_PHOENICIAN)
#else
#define PH_TOG KC_TRANSPARENT
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_no_knob(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,       KC_J,    LT_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,       KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   AE_MEH,  MT_TAB,     LT_SPC,  QK_REP
    ),

#ifdef PHOENICIAN_ENABLE
    [_PHOENICIAN] = LAYOUT_no_knob(
        UM_QOF,  UM_WAU,  UM_HE,   UM_ROSH, UM_TAU,     UM_WAU,  UM_WAU,  UM_YOD,  UM_AIN,  UM_PE,
        UM_ALF,  UM_SHIN, UM_DELT, UM_TET,  UM_GAML,    UM_HET,  UM_YOD,  UM_KAF,  UM_LAMD, KC_SCLN,
        UM_ZAI,  UM_SEMK, UM_SADE, UM_VAV,  UM_BET,     UM_NUN,  UM_MEM,  _______, _______, _______,
                                   _______, _______,    _______, _______
    ),
#endif

    [_NUM] = LAYOUT_no_knob(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    UM_EURO, KC_7,    KC_8,    KC_9,    KC_PIPE,
                                   _______, _______,    LT_0,    _______
    ),

    [_FUN] = LAYOUT_no_knob(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT,    XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F11,
                                   _______, _______,    LT_F10,  _______
    ),

    [_LSYM] = LAYOUT_no_knob(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,    _______, _______
    ),

    [_NAV] = LAYOUT_no_knob(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK,    XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                                   _______, MT_CWT,     _______, PH_TOG
    ),
};
