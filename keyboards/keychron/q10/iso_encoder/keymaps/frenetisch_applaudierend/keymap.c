/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H

// clang-format off

#include "../../../../common/user/user_esxt.h"
#include "../../../../common/user/user_intl.h"
#include "../../../../common/user/user_keycodes.h"
#include "../../../../common/user/user_layers.h"
#include "../../../../common/user/user_os.h"

#include "keymap_swiss_de.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BAS] = LAYOUT_iso_90(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,               KC_DEL,
        XXXXXXX,    CH_SECT,  CH_1,     CH_2,     CH_3,     CH_4,     CH_5,      CH_6,     CH_7,     CH_8,     CH_9,     CH_0,     CH_QUOT,  CH_CIRC,  KC_BSPC,              KC_PGUP,
        XXXXXXX,    KC_TAB,   CH_Q,     CH_W,     CH_E,     CH_R,     CH_T,      CH_Z,     CH_U,     CH_I,     CH_O,     CH_P,     CH_UDIA,  CH_DIAE,                        KC_PGDN,
        XXXXXXX,    MO(EXT),  CH_A,     CH_S,     CH_D,     CH_F,     CH_G,      CH_H,     CH_J,     CH_K,     CH_L,     CH_ODIA,  CH_ADIA,  CH_DLR,   KC_ENT,               KC_HOME,
        XXXXXXX,    KC_LSFT,  CH_LABK,  CH_Y,     CH_X,     CH_C,     CH_V,      CH_B,     CH_B,     CH_N,     CH_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        XXXXXXX,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   MO(FNB),                       KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FNB] = LAYOUT_iso_90(
        RM_TOGG,    MC_LCK,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,            XXXXXXX,                      KC_HOME,  KC_PGDN,  KC_END ),

    [EXT] = LAYOUT_iso_90(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  CH_LPRN,  CH_LCBR,  CH_LBRC,  SP_UDIC,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  MO(EXS),  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  SP_ODIC,  SP_ADIC,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  CH_EQL,   XXXXXXX,  XXXXXXX,  CH_SLSH,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  MO(FNE),                       XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX),

    [EXS] = LAYOUT_iso_90(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          ut    XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  CH_RPRN,  CH_RCBR,  CH_RBRC,  SP_UDIC,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   SP_ODIC,  SP_ADIC,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX),

    [FNE] = LAYOUT_iso_90(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BAS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FNB] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
    [EXT] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [EXS] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [FNE] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif // ENCODER_MAP_ENABLE

bool dip_switch_update_user(uint8_t index, bool active) {
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!esxt_process(keycode, record)) {
        return false;
    }

    if (!intl_process_keys(keycode, record)) {
        return false;
    }

    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    os_process_detected_os(detected_os);

    return true;
}
