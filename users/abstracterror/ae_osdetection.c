#include QMK_KEYBOARD_H
#include "os_detection.h"
#include <tmk_core/protocol/usb_device_state.h>
#include "abstracterror.h"

uint32_t os_detection_timeout(uint32_t trigger_time, void *cb_arg) {
    switch (detected_host_os()) {
        case OS_IOS:
        case OS_MACOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            set_send_uk_codes(false);
            break;
        default:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            set_send_uk_codes(true);
            break;
    }
    return 0;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state) {
    if (usb_device_state == USB_DEVICE_STATE_INIT) {
        erase_wlength_data();
        defer_exec(1000, os_detection_timeout, NULL);
    }
}
