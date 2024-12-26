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

enum layers {
    BAS,
    FNB,
    EXT,
    FNE,
};

enum keycodes {
    XT_PARN = SAFE_RANGE, // Left parenthesis
    XT_BRCE, // Left brace
    XT_BRCK, // Left bracket

    MC_LGT,  // Log out macro

    JB_RUN,  // Run the selected configuration
    JB_DBG,  // Debug the selected configuration
    JB_STOP, // Stop the currently running process

    SP_NXTL, // Next layout
    SP_PRVL, // Previous layout
    SP_NXTO, // Next OS
    SP_PRVO, // Previous OS
};

enum os {
    LINUX,
    WINDOWS
};

enum layout {
    COLEMAK,
    CH
};

static uint8_t current_os = LINUX;
static uint8_t current_layout = COLEMAK;

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))

#define CK_EXT LT(EXT, KC_ESC)
#define CK_FNB MO(FNB)
#define CK_FNE MO(FNE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BAS] = LAYOUT_92_iso(
        KC_MUTE,    KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_INS,   KC_DEL,     KC_MUTE,
        XXXXXXX,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,              KC_DEL,
        XXXXXXX,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                        KC_PGUP,
        XXXXXXX,    CK_EXT,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,               KC_PGDN,
        XXXXXXX,    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        XXXXXXX,    KC_LCTL,  KC_LWIN,  KC_LALT,  CK_FNB,             KC_SPC,                        KC_SPC,             KC_RALT,  CK_FNB,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FNB] = LAYOUT_92_iso(
        RM_TOGG,    MC_LGT,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_PGUP,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                       XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_PGDN,  KC_END ),

    [EXT] = LAYOUT_92_iso(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XT_PARN,  XT_BRCE,  XT_BRCK,  XXXXXXX,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_EQL,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  CK_FNE,             XXXXXXX,                       XXXXXXX,            XXXXXXX,  CK_FNE,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

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
    [EXT] = { ENCODER_CCW_CW(SP_PRVL, SP_NXTL), ENCODER_CCW_CW(SP_PRVO, SP_NXTO) },
    [FNE] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif // ENCODER_MAP_ENABLE

static bool toggle_current_layout(void) {
    current_layout = current_layout == COLEMAK ? CH : COLEMAK;
    return false;
}

static bool toggle_current_os(void) {
    current_os = current_os == LINUX ? WINDOWS : LINUX;
    return false;
}

static bool register_code16_layout(uint16_t kc_cmk, uint16_t kc_ch) {
    if (current_layout == COLEMAK) {
        register_code16(kc_cmk);
    } else {
        register_code16(kc_ch);
    }
    return false;
}

static bool unregister_code16_layout(uint16_t kc_cmk, uint16_t kc_ch) {
    if (current_layout == COLEMAK) {
        unregister_code16(kc_cmk);
    } else {
        unregister_code16(kc_ch);
    }
    return false;
}

static bool handle_code16_layout(uint16_t kc_cmk, uint16_t kc_ch, keyrecord_t *record) {
    bool result;

    uint8_t mods = get_mods();
    clear_mods();

    if (record->event.pressed) {
        result = register_code16_layout(kc_cmk, kc_ch);
    } else {
        result = unregister_code16_layout(kc_cmk, kc_ch);
    }

    set_mods(mods);
    return result;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    current_layout = active ? COLEMAK : CH;

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool shifted = (get_mods() & MODS_SHIFT_MASK) != 0;

    switch (keycode) {
        case XT_PARN:
        return shifted
            ? handle_code16_layout(S(KC_0), S(KC_9), record)
            : handle_code16_layout(S(KC_9), S(KC_8), record);

        case XT_BRCE:
        return shifted
            ? handle_code16_layout(S(KC_RBRC), ALGR(KC_NUHS), record)
            : handle_code16_layout(S(KC_LBRC), ALGR(KC_QUOT), record);

        case XT_BRCK:
        return shifted
            ? handle_code16_layout(KC_RBRC, ALGR(KC_RBRC), record)
            : handle_code16_layout(KC_LBRC, ALGR(KC_LBRC), record);

        case SP_PRVL:
        case SP_NXTL: return toggle_current_layout();

        case SP_PRVO:
        case SP_NXTO: return toggle_current_os();
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
