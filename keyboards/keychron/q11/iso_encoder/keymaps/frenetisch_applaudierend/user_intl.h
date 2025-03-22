#include <stdint.h>
#include QMK_KEYBOARD_H

#include "user_keycodes.h"

#include "keymap_swiss_de.h"

#pragma once

void _intl_tap_with_umlaut(uint16_t keycode);

bool intl_process_keys(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case SP_ADIC:
                _intl_tap_with_umlaut(S(CH_A));
                return false;
            case SP_ODIC:
                _intl_tap_with_umlaut(S(CH_O));
                return false;
            case SP_UDIC:
                _intl_tap_with_umlaut(S(CH_U));
                return false;
        }
    }

    return true;
}

void _intl_tap_with_umlaut(uint16_t keycode) {
    register_code(CH_DIAE);
    tap_code(keycode);
    unregister_code(CH_DIAE);
}