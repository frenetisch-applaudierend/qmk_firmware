#include <stdint.h>
#include QMK_KEYBOARD_H

#pragma once

enum os {
    LINUX,
    WINDOWS
};

static uint8_t os_current = LINUX;

void os_process_detected_os(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_WINDOWS:
            os_current = WINDOWS;
            // set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            break;

        case OS_LINUX:
            os_current = LINUX;
            // set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;

        case OS_IOS:
        case OS_MACOS:
        case OS_UNSURE:
            break;
    }
}
