/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>
#include QMK_KEYBOARD_H

#include "keymap_swiss_de.h"
#include "sendstring_swiss_de.h"

enum layers {
    BAS,
    FNB,
    EXT,
    FNE,
};

enum keycodes {
    XT_PAR = SAFE_RANGE, // Left parenthesis
    XT_CBR, // Curly Braces
    XT_BRC, // Brackets

    MC_LCK,  // Lock screen macro

    JB_RUN,  // Run the selected configuration
    JB_DBG,  // Debug the selected configuration
    JB_STOP, // Stop the currently running process

    CH_ADIC, // Capital A with diacritic (Ä)
    CH_ODIC, // Capital O with diacritic (Ö)
    CH_UDIC, // Capital U with diacritic (Ü)
};

enum os {
    LINUX,
    WINDOWS
};

static uint8_t current_os = LINUX;

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))

#define SP_EXT LT(EXT, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BAS] = LAYOUT_92_iso(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,     KC_MUTE,
        XXXXXXX,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,              KC_DEL,
        XXXXXXX,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                        KC_PGUP,
        XXXXXXX,    SP_EXT,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,               KC_PGDN,
        XXXXXXX,    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        XXXXXXX,    KC_LCTL,  MO(FNB),  KC_LWIN,  KC_LALT,            KC_SPC,                        KC_SPC,             KC_RALT,  MO(FNB),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FNB] = LAYOUT_92_iso(
        RM_TOGG,    MC_LCK,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  CH_UDIC,  XXXXXXX,  CH_ODIC,  XXXXXXX,  CH_UDIC,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    KC_CAPS,  CH_ADIC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  CH_ODIC,  CH_ADIC,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_PGUP,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                       XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_PGDN,  KC_END ),

    [EXT] = LAYOUT_92_iso(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XT_PAR,   XT_CBR,   XT_BRC,   XXXXXXX,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  CH_EQL,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  MO(FNE),            XXXXXXX,                       XXXXXXX,            XXXXXXX,  MO(FNE),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [FNE] = LAYOUT_92_iso(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                       XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BAS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [FNB] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [EXT] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [FNE] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif // ENCODER_MAP_ENABLE

static bool handle_code16_explicit(uint16_t kc, keyrecord_t *record) {
    uint8_t mods = get_mods();
    clear_mods();

    if (record->event.pressed) {
        register_code16(kc);
    } else {
        unregister_code16(kc);
    }

    set_mods(mods);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    // current_os = active ? WINDOWS : LINUX;

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool shifted = (get_mods() & MODS_SHIFT_MASK) != 0;

    switch (keycode) {
        case XT_PAR:
        return shifted
            ? handle_code16_explicit(S(KC_9), record)
            : handle_code16_explicit(S(KC_8), record);

        case XT_CBR:
        return shifted
            ? handle_code16_explicit(CH_RCBR, record)
            : handle_code16_explicit(CH_LCBR, record);

        case XT_BRC:
        return shifted
            ? handle_code16_explicit(CH_RBRC, record)
            : handle_code16_explicit(CH_LBRC, record);

        case CH_ADIC:
            handle_code16_explicit(KC_CAPS, record);
            handle_code16_explicit(CH_ADIA, record);
            handle_code16_explicit(KC_CAPS, record);
            return false;

        case CH_ODIC:
            handle_code16_explicit(KC_CAPS, record);
            handle_code16_explicit(CH_ODIA, record);
            handle_code16_explicit(KC_CAPS, record);
            return false;

        case CH_UDIC:
            handle_code16_explicit(KC_CAPS, record);
            handle_code16_explicit(CH_UDIA, record);
            handle_code16_explicit(KC_CAPS, record);
            return false;


        case MC_LCK:
            return handle_code16_explicit(LGUI(CH_L), record);

    }

    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_WINDOWS:
            current_os = WINDOWS;
            break;

        case OS_LINUX:
            current_os = LINUX;
            break;

        case OS_IOS:
        case OS_MACOS:
        case OS_UNSURE:
            break;
    }

    return true;
}
