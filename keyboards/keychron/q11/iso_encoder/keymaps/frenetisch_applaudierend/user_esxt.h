#include <stdint.h>
#include QMK_KEYBOARD_H

#include "action_layer.h"

#include "user_layers.h"
#include "user_keycodes.h"

#pragma once

static bool esxt_active = false;
static bool esxt_keys_pressed = false;

bool esxt_process(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SP_ESXT && record->event.pressed == true) {
        esxt_active = true;
        esxt_keys_pressed = false;

        layer_on(EXT);

        return false;
    }

    if (keycode == SP_ESXT && record->event.pressed == false) {
        if (!esxt_keys_pressed) {
            tap_code(KC_ESC);
        }
        esxt_active = false;
        esxt_keys_pressed = false;

        layer_off(EXT);

        return false;
    }

    if (esxt_active && record->event.pressed == true) {
        esxt_keys_pressed = true;
    }

    return true;
}
