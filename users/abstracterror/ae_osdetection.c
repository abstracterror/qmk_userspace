#include "quantum.h"
#include "abstracterror.h"

__attribute__ ((weak))
bool process_detected_host_os_keymap(os_variant_t detected_os) {
    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (!process_detected_host_os_keymap(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            set_send_uk_codes(true);
            break;
        default:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            set_send_uk_codes(false);
            break;
    }

    return true;
}
