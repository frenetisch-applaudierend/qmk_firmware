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
#include QMK_KEYBOARD_H

#include "keymap_swiss_de.h"

enum layers {
    NORMAL,
    REDUX,
    FUNCTION,
    NAVIGATION,
    SYMBOLS
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define SP_FN  MO(FUNCTION)

#define SPC_SYM LT(SYMBOLS, KC_SPC)
#define ENT_NAV LT(NAVIGATION, KC_ENTER)

#define OOOOOOO XXXXXXX

// Left-hand home row mods
#define A_GUI LGUI_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_SFT LSFT_T(KC_D)
#define F_CTL LCTL_T(KC_F)

// Right-hand home row mods
#define J_CTL RCTL_T(KC_J)
#define K_SFT RSFT_T(KC_K)
#define L_ALT LALT_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT_92_iso(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   XXXXXXX,  KC_PGUP,  KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_DEL,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  SP_FN,    KC_LWIN,  KC_LALT,            KC_SPACE,                      SPC_SYM,             KC_RALT,  SP_FN,     KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [REDUX] = LAYOUT_92_iso(
        KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  OOOOOOO,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  OOOOOOO,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     CH_UDIA,    XXXXXXX,                      XXXXXXX,
        _______,  KC_BSPC,  A_GUI,    S_ALT,    D_SFT,    F_CTL,    KC_G,      KC_H,     J_CTL,    K_SFT,    L_ALT,    CH_ODIA,  CH_ADIA,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  OOOOOOO,  KC_ESC,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  SP_FN,    XXXXXXX,  KC_TAB,             ENT_NAV,                       SPC_SYM,            KC_RALT,  SP_FN,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [FUNCTION] = LAYOUT_92_iso(
        RM_TOGG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
        _______,  KC_CAPS,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [NAVIGATION] = LAYOUT_92_iso(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  XXXXXXX,    XXXXXXX,                      XXXXXXX,
        XXXXXXX,  KC_BSPC,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  XXXXXXX,   XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                       KC_SPACE,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [SYMBOLS] = LAYOUT_92_iso(
        XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  CH_AT,    CH_DQUO,  CH_QUOT,  CH_DLR,   CH_EQL,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,                      XXXXXXX,
        XXXXXXX,  KC_BSPC,  CH_LABK,  CH_LBRC,  CH_LCBR,  CH_LPRN,  CH_SCLN,   XXXXXXX,  KC_RCTL,  KC_RSFT,  KC_LALT,  KC_RGUI,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  CH_SLSH,  XXXXXXX,  CH_AMPR,  CH_PIPE,  CH_HASH,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_ENTER,                       XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [NORMAL]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [REDUX]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FUNCTION]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [NAVIGATION] = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [SYMBOLS]    = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
};
#endif // ENCODER_MAP_ENABLE

#define ko_make_cap_dia(dia, base) {   \
    .trigger = dia,                    \
    .trigger_mods = MOD_MASK_SHIFT,    \
    .replacement = S(base),            \
    .suppressed_mods = MOD_MASK_SHIFT, \
    .layers = ~0,                      \
    .custom_action = make_dia,         \
    .options = ko_options_default      \
}

bool make_dia(bool key_down, void *ctx) {
    if (key_down) {
        register_code(CH_DIAE);
    } else {
        unregister_code(CH_DIAE);
    }
    return true;
}

const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t cap_adia_override = ko_make_cap_dia(CH_ADIA, CH_A);
const key_override_t cap_odia_override = ko_make_cap_dia(CH_ODIA, CH_O);
const key_override_t cap_udia_override = ko_make_cap_dia(CH_UDIA, CH_U);

#define LAYER_SYMBOLS (1 << SYMBOLS)
const key_override_t paren_override = ko_make_with_layers(MOD_MASK_SHIFT, CH_LPRN, CH_RPRN, LAYER_SYMBOLS); 
const key_override_t curly_override = ko_make_with_layers(MOD_MASK_SHIFT, CH_LCBR, CH_RCBR, LAYER_SYMBOLS); 
const key_override_t brace_override = ko_make_with_layers(MOD_MASK_SHIFT, CH_LBRC, CH_RBRC, LAYER_SYMBOLS); 
const key_override_t backslash_override = ko_make_with_layers(MOD_MASK_SHIFT, CH_SLSH, CH_BSLS, LAYER_SYMBOLS); 
const key_override_t excl_override = ko_make_with_layers(MOD_MASK_SHIFT, CH_AT, CH_EQL, LAYER_SYMBOLS);
const key_override_t question_override = ko_make_with_layers(MOD_MASK_SHIFT, CH_DQUO, CH_QUES, LAYER_SYMBOLS);

const key_override_t *key_overrides[] = {
	&delete_override,
    &cap_adia_override,
    &cap_odia_override,
    &cap_udia_override,

    &paren_override,
	&curly_override,
	&brace_override,
    &backslash_override,
    &excl_override,
    &question_override,
    
};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        // active = Mac, inactive = Win
        default_layer_set(1UL << (active ? 1 : 0));
    }
    return false;
}
