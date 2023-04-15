// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum Layers {
    _BASE   = 0,
    _BASE2  = 1,
    _LOWER  = 2,
    _RAISE  = 3,
    _ADJUST = 4,
};

// TODO: Find official keycode
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define LO_SPC LT(_LOWER, KC_SPC)
#define RS_ENT LT(_RAISE, KC_ENT)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ ` │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │CAP│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ESC│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤L_S├───┐   ┌───┤R_E├───┘
      *                   └───┤Ctl│   │Bsp├───┘
      *                       └───┘   └───┘
      */
   [_BASE] = LAYOUT_split_3x6_3( \
     KC_GRV         , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T                                          , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLS       ,\
     KC_ESC         , KC_A          , KC_S          , KC_D          , KC_F          , KC_G                                          , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     SC_LSPO        , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B                                          , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , SC_RSPC       ,\
                                                                      KC_LGUI       , LO_SPC        , CTL_TAB       , KC_BSPC       , RS_ENT        , KC_RALT        \
   ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │PUp│Up │PDw│   │       │ : │ 7 │ 8 │ 9 │ + │ * │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │Hom│Lft│Dwn│Rgt│End│       │ = │ 4 │ 5 │ 6 │ - │ / │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │ 0 │ 1 │ 2 │ 3 │ . │Del│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤Spc│
      *               └───┤(X)├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
   [_LOWER] = LAYOUT_split_3x6_3( \
    _______         , _______       , KC_PGUP       , KC_UP         , KC_PGDN       , _______                                       , KC_COLN       , KC_7          , KC_8          , KC_9          , KC_PPLS       , KC_PAST       ,\
    _______         , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_END                                        , KC_EQL        , KC_4          , KC_5          , KC_6          , KC_PMNS       , KC_PSLS       ,\
    _______         , _______       , _______       , _______       , _______       , _______                                       , KC_0          , KC_1          , KC_2          , KC_3          , KC_DOT        , KC_DEL        ,\
                                                                      _______       , _______       , _______       , _______       , _______       , KC_SPC         \
   ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │ + │       │ : │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ < │ ( │ { │ [ │ - │       │ = │ ] │ } │ ) │ > │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │ _ │       │ 🔉│ 🔊│ ⏮ │ ⏭ │ ⏯ │ 🔇│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤(X)├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
   [_RAISE] = LAYOUT_split_3x6_3( \
    _______         , _______       , _______       , _______       , _______       , KC_PLUS                                       , KC_COLN       , _______       , _______       , _______       , _______       , _______       ,\
    _______         , KC_LT         , KC_LPRN       , KC_LCBR       , KC_LBRC       , KC_MINUS                                      , KC_EQL        , KC_RBRC       , KC_RCBR       , KC_RPRN       , KC_GT         , _______       ,\
    _______         , _______       , _______       , _______       , _______       , KC_UNDS                                       , KC_VOLD       , KC_VOLU       , KC_MPRV       , KC_MNXT       , KC_MPLY       , KC_MUTE       ,\
                                                                      _______       , _______       , _______       , _______       , _______       , _______        \
   ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ 💤│   │MB1│MUp│MB2│Psc│       │F12│ F7│ F8│ F9│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │MLf│MDw│MRg│   │       │F11│ F4│ F5│ F6│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │F10│ F1│ F2│ F3│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
   [_ADJUST] = LAYOUT_split_3x6_3( \
    KC_SLEP         , _______       , KC_BTN1       , KC_MS_U       , KC_BTN2       , KC_PSCR                                       , KC_F12        , KC_F7         , KC_F8         , KC_F9         , KC_MPRV       , KC_MNXT       ,\
    _______         , _______       , KC_MS_L       , KC_MS_D       , KC_MS_R       , _______                                       , KC_F11        , KC_F4         , KC_F5         , KC_F6         , KC_MPLY       , KC_MUTE       ,\
    _______         , _______       , _______       , _______       , _______       , _______                                       , KC_F10        , KC_F1         , KC_F2         , KC_F3         , KC_VOLD       , KC_VOLU       ,\
                                                                      _______       , _______       , _______       , _______       , _______       , _______        \
  ),
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
