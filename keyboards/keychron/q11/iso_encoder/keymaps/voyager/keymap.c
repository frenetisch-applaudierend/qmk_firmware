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
#define OE_RALT RALT_T(CH_ODIA)
#define SL_GUI RGUI_T(KC_SLASH)

// Umlauts
#define CH_ADIA RALT(KC_Q)
#define CH_ODIA RALT(KC_P)
#define CH_UDIA RALT(KC_Y)

// Symbols
#define SY_LPRN S(KC_9)
#define SY_RPRN S(KC_0)
#define SY_LCBR S(KC_LBRC)
#define SY_RCBR S(KC_RBRC)
#define SY_LBRC KC_LBRC
#define SY_RBRC KC_RBRC
#define SY_LABK S(KC_COMMA)
#define SY_RABK S(KC_DOT)
#define SY_AT S(KC_2)

enum custom_keycodes {
    SY_QUOT = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT_92_iso(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   XXXXXXX,  KC_PGUP,  KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_DEL,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  SP_FN,    KC_LWIN,  KC_LALT,            KC_SPACE,                      KC_SPACE,            KC_RALT,  SP_FN,     KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [REDUX] = LAYOUT_92_iso(
        KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  OOOOOOO,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  KC_EQL,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     CH_UDIA,    XXXXXXX,                      XXXXXXX,
        _______,  KC_BSPC,  A_GUI,    S_ALT,    D_SFT,    F_CTL,    KC_G,      KC_H,     J_CTL,    K_SFT,    L_ALT,    OE_RALT,  CH_ADIA,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        _______,  XXXXXXX,  KC_ESC,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   SL_GUI,               KC_MINS,  XXXXXXX,
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
        XXXXXXX,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,   OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,   OOOOOOO,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  OOOOOOO,    XXXXXXX,                      XXXXXXX,
        XXXXXXX,  KC_BSPC,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  OOOOOOO,   OOOOOOO,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  OOOOOOO,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  QK_LLCK,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,   OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,              QK_LLCK,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                       KC_SPACE,           XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [SYMBOLS] = LAYOUT_92_iso(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  OOOOOOO,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   OOOOOOO,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  OOOOOOO,  SY_AT,    SY_QUOT,  OOOOOOO,  OOOOOOO,  OOOOOOO,   OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,    XXXXXXX,                      XXXXXXX,
        XXXXXXX,  KC_BSPC,  SY_LABK,  SY_LBRC,  SY_LCBR,  SY_LPRN,  KC_SCLN,   OOOOOOO,  KC_RCTL,  KC_RSFT,  KC_LALT,  KC_RGUI,  OOOOOOO,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  QK_LLCK,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,   OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,  OOOOOOO,              QK_LLCK,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  OOOOOOO,            KC_ENTER,                       XXXXXXX,           XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
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

const key_override_t bspc_del = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

#define LAYER_SYMBOLS (1 << SYMBOLS)
const key_override_t sy_rprn = ko_make_with_layers(MOD_MASK_SHIFT, SY_LPRN, SY_RPRN, LAYER_SYMBOLS);
const key_override_t sy_rcbr = ko_make_with_layers(MOD_MASK_SHIFT, SY_LCBR, SY_RCBR, LAYER_SYMBOLS);
const key_override_t sy_rbrc = ko_make_with_layers(MOD_MASK_SHIFT, SY_LBRC, SY_RBRC, LAYER_SYMBOLS);
const key_override_t sy_rabk = ko_make_with_layers(MOD_MASK_SHIFT, SY_LABK, SY_RABK, LAYER_SYMBOLS);

const key_override_t *key_overrides[] = {
	&bspc_del,

    &sy_rprn,
	&sy_rcbr,
	&sy_rbrc,
    &sy_rabk,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Work around issue with mod-tap:
        // https://docs.qmk.fm/mod_tap#caveats
        case OE_RALT: {
            if (record->tap.count && record->event.pressed) {
                tap_code16(CH_ODIA);
                return false;
            }
            break;
        }

        // In the US international layout, the quote keys are dead
        case SY_QUOT: {
            if (record->event.pressed) {
                tap_code16(KC_QUOTE);
                tap_code16(KC_SPACE);
            }
            return false;
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        // active = Mac, inactive = Win
        default_layer_set(1UL << (active ? 1 : 0));
    }
    return false;
}
