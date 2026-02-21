#include "quantum.h"
#include "abstracterror.h"

const uint16_t PROGMEM escape_combo[]        = { KC_Q, KC_W, COMBO_END };
#if defined(QWERTY_KEYMAP) || defined(QAZ_KEYMAP)
const uint16_t PROGMEM left_bracket_combo[]  = { KC_W, MT_S, COMBO_END };
const uint16_t PROGMEM left_brace_combo[]    = { LT_E, MT_D, COMBO_END };
const uint16_t PROGMEM left_paren_combo[]    = { LT_R, MT_F, COMBO_END };
const uint16_t PROGMEM right_paren_combo[]   = { LT_U, MT_J, COMBO_END };
const uint16_t PROGMEM right_brace_combo[]   = { KC_I, MT_K, COMBO_END };
const uint16_t PROGMEM right_bracket_combo[] = { KC_O, MT_L, COMBO_END };
const uint16_t PROGMEM semicolon_combo[]     = { MT_K, MT_L, COMBO_END };
const uint16_t PROGMEM lcapsword_combo[]     = { MT_S, MT_F, COMBO_END };
const uint16_t PROGMEM rcapsword_combo[]     = { MT_J, MT_L, COMBO_END };
#else
const uint16_t PROGMEM left_bracket_combo[]  = { KC_W, MT_R, COMBO_END };
const uint16_t PROGMEM left_brace_combo[]    = { LT_F, MT_S, COMBO_END };
const uint16_t PROGMEM left_paren_combo[]    = { LT_P, MT_T, COMBO_END };
const uint16_t PROGMEM right_paren_combo[]   = { LT_L, MT_N, COMBO_END };
const uint16_t PROGMEM right_brace_combo[]   = { KC_U, MT_E, COMBO_END };
const uint16_t PROGMEM right_bracket_combo[] = { KC_Y, MT_I, COMBO_END };
const uint16_t PROGMEM q_combo[]             = { MT_R, MT_S, COMBO_END };
const uint16_t PROGMEM v_combo[]             = { MT_S, MT_T, COMBO_END };
const uint16_t PROGMEM k_combo[]             = { MT_N, MT_E, COMBO_END };
const uint16_t PROGMEM semicolon_combo[]     = { MT_E, MT_I, COMBO_END };
const uint16_t PROGMEM lcapsword_combo[]     = { MT_R, MT_T, COMBO_END };
const uint16_t PROGMEM rcapsword_combo[]     = { MT_N, MT_I, COMBO_END };
#endif

combo_t key_combos[] = {
    COMBO(escape_combo,        KC_ESCAPE),
    COMBO(left_bracket_combo,  KC_LEFT_BRACKET),
    COMBO(left_brace_combo,    KC_LEFT_CURLY_BRACE),
    COMBO(left_paren_combo,    KC_LEFT_PAREN),
    COMBO(right_paren_combo,   KC_RIGHT_PAREN),
    COMBO(right_brace_combo,   KC_RIGHT_CURLY_BRACE),
    COMBO(right_bracket_combo, KC_RIGHT_BRACKET),
    COMBO(semicolon_combo,     KC_SCLN),
    COMBO(lcapsword_combo,     QK_CAPS_WORD_TOGGLE),
    COMBO(rcapsword_combo,     QK_CAPS_WORD_TOGGLE),
#if !defined(QWERTY_KEYMAP) && !defined(QAZ_KEYMAP)
    COMBO(q_combo,             KC_Q),
    COMBO(v_combo,             KC_V),
    COMBO(k_combo,             KC_K),
#endif
};
