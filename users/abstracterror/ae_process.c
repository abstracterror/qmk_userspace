#include "quantum.h"
#include "abstracterror.h"

bool apple_os(void) {
    switch (detected_host_os()) {
        case OS_IOS:
        case OS_MACOS:
            return true;
        default:
            return false;
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

void tap_undo(bool redo) {
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            tap_code16(redo ? S(A(KC_Z)) : A(KC_Z));
            break;
        case OS_LINUX:
            // from the GNOME HIG
            tap_code16(redo ? S(C(KC_Z)) : C(KC_Z));
            break;
        case OS_WINDOWS:
            tap_code16(redo ? C(KC_Y) : C(KC_Z));
            break;
        case OS_UNSURE:
            break;
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
            if (record->event.pressed) {
                tap_undo(keycode == REDO);
            }
            return false;

        case UK_TOGG:
            if (record->event.pressed) {
                toggle_send_uk_codes();
            }
            return false;

        default:
            return true;
    }
}
