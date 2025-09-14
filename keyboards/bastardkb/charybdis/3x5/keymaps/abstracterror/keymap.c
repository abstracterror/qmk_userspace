#include QMK_KEYBOARD_H
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
              '*', '*', '*',  '*', '*'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,        KC_J,    LT_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,        KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        LT_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          AE_MEH,  MT_TAB,  MO_NUM,      MO_LSYM, LT_SPC
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, _______, UK_TOGG, QK_BOOT,     XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F11,
                          XXXXXXX, _______, XXXXXXX,     XXXXXXX, LT_F10
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,     XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,     UM_GBP,  KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     UM_EURO, KC_7,    KC_8,    KC_9,    KC_PIPE,
                          XXXXXXX, _______, _______,     MO_TSYM, LT_0
    ),

    [_LSYM] = LAYOUT(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,     XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,     XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, _______, MO_TSYM,     _______, _______
    ),

    [_TSYM] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,     RM_NEXT, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RM_PREV, XXXXXXX, RM_HUED, RM_SATD, RM_VALD,
                          XXXXXXX, _______, _______,     _______, _______
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK,     XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                          XXXXXXX, MT_CWT,  XXXXXXX,     XXXXXXX, _______
    ),

    [_MOUSE] = LAYOUT(
        DPI_MOD, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, _______,     _______, _______, _______, _______, _______,
        _______, SNIPING, _______, MS_BTN3, _______,     _______, _______, _______, _______, _______,
                          DRGSCRL, MS_BTN1, MS_BTN2,     _______, _______
    )
};

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case DRGSCRL:
        case SNIPING:
        case SNP_TOG:
        case S_D_MOD:
        case DPI_MOD:
            return true;
        default:
            return false;
    }
}
