#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif //HAPTIC ENABLE
#include "abstracterror.h"
#include "ae_combos.c"
#include "ae_keyoverrides.c"

enum custom_keycodes {
    OS_SWAP = SAFE_RANGE
};

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
 
  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
#endif // AUDIO_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_saegewerk(
        KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,                      KC_J,    LT_L,    KC_U,    KC_Y,    KC_SCLN,
        MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                      KC_M,    MT_N,    MT_E,    MT_I,    MT_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE, KC_MPLY, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_MEH,  LT_TAB,  MT_TAB,                    LT_SPC,  MO_LSYM, KC_ENT
    ),

    [_FUN] = LAYOUT_saegewerk(
        XXXXXXX, XXXXXXX, XXXXXXX, UK_TOGG, QK_BOOT,                   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,                   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F11,
                          XXXXXXX, XXXXXXX, _______,                   LT_F10,  XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_saegewerk(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_4,    KC_5,    KC_6,    _______,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,                   XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PIPE,
                          XXXXXXX, XXXXXXX, _______,                   LT_0,    MO_TSYM, XXXXXXX
    ),

    [_LSYM] = LAYOUT_saegewerk(
        XXXXXXX, KC_PLUS, KC_UNDS, KC_DQUO, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_EQL,  KC_MINS, KC_QUOT, XXXXXXX,                   XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, MO_TSYM, _______,                   _______, XXXXXXX, XXXXXXX
    ),

    [_TSYM] = LAYOUT_saegewerk(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, AU_TOGG,                   RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
        QK_BOOT, HF_RST,  HF_TOGG, HF_PREV, HF_NEXT, KC_MUTE, KC_MPLY, RGB_RMD, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,
                          XXXXXXX, XXXXXXX, _______,                   _______, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_saegewerk(
        XXXXXXX, PREVTAB, NEXTTAB, REDO,    CTL_BRK,                   XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, KC_MUTE, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                          XXXXXXX, XXXXXXX, MT_CWT,                    _______, XXXXXXX, XXXXXXX
    ),
};


void keyboard_post_init_user(void) {
#if HAPTIC_ENABLE
    // disable per-key haptic feedback by default
    haptic_disable();
#endif

#ifdef CONVERT_TO_LIATRIS
    // turn off the Liatris power LED
    setPinOutput(24);
    writePinHigh(24);
#endif
}


#ifdef OLED_ENABLE

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0; 

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    void dynamic_macro_record_start_user(void) {
          dmacro_num = 1;
        return;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return; 
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return; 
    }
#endif //DYNAMIC_MACRO_ENABLE


void matrix_scan_user(void) {
  #ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }    
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
   #endif //DYNAMIC_MACRO_ENABLE
}


void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};  
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0}; 
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE  
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);


// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE 
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE 
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) { 
          oled_write_P(aud_en, false); 
        } else {
          oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
        oled_write_P(hap_en, false); 
     #endif // HAPTIC ENABLE
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            strcpy(layer_state_str, "BASE COLEMAK");
            break;
        case _FUN:
            strcpy(layer_state_str, "FUNCTION");
            break;
        case _NUM:
            strcpy(layer_state_str, "NUM");
            break;
        case _LSYM:
            strcpy(layer_state_str, "LSYM");
            break;
        case _TSYM:
            strcpy(layer_state_str, "TSYM");
            break;
        case _NAV:
            strcpy(layer_state_str, "NAV");
            break;
       default:
            strcpy(layer_state_str, "XXXXXX");
    }
    if (dmacro_num < 1) {
          strcpy(o_text, layer_state_str);
    }
    return state;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
        #ifdef DYNAMIC_MACRO_ENABLE
            if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
            if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
            if(dmacro_num == 3){ oled_write_P(play_ico, false); }
        #endif //DYNAMIC_MACRO_ENABLE

        oled_write_ln(o_text, false);
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
            0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 
            0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE



bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP: 
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE
                }
              #ifdef HAPTIC_ENABLE
                drv2605l_pulse(DRV2605L_EFFECT_PULSING_STRONG_1_100);
              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }

      case KC_MPLY:
        if (record->event.pressed) {
          #ifdef HAPTIC_ENABLE
                  drv2605l_pulse(DRV2605L_EFFECT_SHARP_CLICK_100);
          #endif // HAPTIC_ENABL
        }
        break;
    }
    return true;
}


#ifdef ENCODER_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  L                                          │
// └───────────────────────────────────────────────────────────┘ 

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  R                                          │
// └───────────────────────────────────────────────────────────┘

    } else if (index == 1) {
      if(IS_LAYER_ON(_NUM)){
          if (clockwise) {
              tap_code(KC_MNXT);
          } else {
              tap_code(KC_MPRV);
          }
      }else {
            if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
      }
    }
    return false;
}

#endif // ENCODER_ENABLE
