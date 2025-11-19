#include "quantum.h"
#include "abstracterror.h"

bool apple_os(void) {
    switch (detected_host_os()) {
        case OS_WINDOWS:
        case OS_LINUX:
            return false;
        default:
            return true;
    }
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}


#ifdef TASK_SWITCHING

static bool task_switching = false;

void ensure_task_switching(void) {
    if (!task_switching) {
        task_switching = true;
        register_code(KC_LALT);
    }
}

void end_task_switching(uint16_t keycode) {
    task_switching = false;
    if ((uint8_t)keycode == KC_ESCAPE) {
        tap_code(KC_ESCAPE);
    }
    unregister_code(KC_LALT);
}

void tap_next_window(void) {
    tap_code16(A(KC_GRAVE));
}

void tap_previous_window(void) {
    tap_code16(S(A(KC_GRAVE)));
}

bool process_record_task_switching(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case NEXT_TASK:
            if (record->event.pressed) {
                if (!task_switching && (get_mods() & MOD_MASK_SHIFT) != 0 && apple_os()) {
                    tap_next_window();
                } else {
                    ensure_task_switching();
                    tap_code(KC_TAB);
                }
            }
            return false;

        case PREVIOUS_TASK:
            if (record->event.pressed) {
                if (!task_switching && (get_mods() & MOD_MASK_SHIFT) != 0 && apple_os()) {
                    tap_previous_window();
                } else {
                    ensure_task_switching();
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            return false;

        case NEXT_WINDOW:
            if (!task_switching && record->event.pressed && apple_os()) {
                tap_next_window();
                return false;
            }
            break;

        case PREVIOUS_WINDOW:
            if (!task_switching && record->event.pressed && apple_os()) {
                tap_previous_window();
                return false;
            }
            break;

        case KC_H:
        case KC_Q:
            if (task_switching && record->event.pressed && apple_os()) {
                // pass through keys for hide and quit
                return true;
            }
            break;

        case KC_D:
            if (task_switching && record->event.pressed && apple_os()) {
                // allow D as an alternative to H
                tap_code(KC_H);
                return false;
            }
            break;

        default:
           break;
    }

    if (task_switching && record->event.pressed) {
        end_task_switching(keycode);
        return false;
    }

    return true;
}

#endif

bool process_os_undo_redo(bool redo, keyrecord_t *record) {
    uint16_t keycode;

    switch (detected_host_os()) {
        case OS_LINUX:
            // from the GNOME HIG
            keycode = redo ? S(C(KC_Z)) : C(KC_Z);
            break;
        case OS_WINDOWS:
            keycode = redo ? C(KC_Y) : C(KC_Z);
            break;
        default:
            keycode = redo ? S(A(KC_Z)) : A(KC_Z);
            return true;
    }

    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
    return false;
}

void process_os_command(uint16_t keycode, keyrecord_t *record) {
    switch (detected_host_os()) {
        case OS_WINDOWS:
        case OS_LINUX:
            keycode = LCTL(keycode);
            break;
        default:
            keycode = LALT(keycode);
            break;
    }
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

#ifdef TASK_SWITCHING
    if (!process_record_task_switching(keycode, record)) {
        return false;
    }
#endif

    switch (keycode) {
        case UNDO:
        case REDO:
            return process_os_undo_redo(keycode == REDO, record);
        case CUT:
            process_os_command(KC_X, record);
            return false;
        case COPY:
            process_os_command(KC_C, record);
            return false;
        case PASTE:
            process_os_command(KC_V, record);
            return false;
        case SEL_ALL:
            process_os_command(KC_A, record);
            return false;

        case UK_TOGG:
            if (record->event.pressed) {
                toggle_send_uk_codes();
            }
            return false;

        case MT_LSFT_CAPS_WORD_TOGGLE:
            if (record->tap.count) {
                if (record->event.pressed) {
                    caps_word_toggle();
                }
                return false;
            }
            return true;

        default:
            return true;
    }
}

uint16_t get_flow_tap_term(
    uint16_t keycode,
    keyrecord_t* record,
    uint16_t prev_keycode
) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        if (IS_QK_LAYER_TAP(keycode)) {
            return 0;
        }
        return FLOW_TAP_TERM;
    }
    return 0;
}
