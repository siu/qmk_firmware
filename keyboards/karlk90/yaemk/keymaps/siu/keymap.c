#include QMK_KEYBOARD_H

#include <stdio.h>

enum Layers {
    _BASE   = 0,
    _BASE2  = 1,
    _LOWER  = 2,
    _RAISE  = 3,
    _ADJUST = 4,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  BASE2,
};

enum Encoder {
    _ENCODER_LEFT  = 0,
    _ENCODER_RIGHT = 1,
};

#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define LO_SPC LT(_LOWER, KC_SPC)
#define RS_ENT LT(_RAISE, KC_ENT)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT( \
     KC_GRV         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_NO         ,                                 KC_NO         , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_CAPS       ,\
     KC_GRV         , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_LBRC       ,                                 KC_RBRC       , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLS       ,\
     KC_ESC         , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_MINS       ,                                 KC_EQL        , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     SC_LSPO        , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , _______       , TG(_ADJUST)   , TG(_ADJUST)   , _______       , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , SC_RSPC       ,\
                                                      BASE          , KC_LGUI       , LO_SPC        , CTL_TAB       , KC_NO         , KC_NO         , KC_BSPC       , RS_ENT        , KC_RALT    , BASE2 \
  ),
   [_BASE2] = LAYOUT( \
     KC_GRV         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_NO         ,                                 KC_NO         , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_CAPS       ,\
     KC_TAB         , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_LBRC       ,                                 KC_RBRC       , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLS       ,\
     KC_ESC         , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_MINS       ,                                 KC_EQL        , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     SC_LSPO        , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , _______       , TG(_ADJUST)   , TG(_ADJUST)   , _______       , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , SC_RSPC       ,\
                                                      BASE          , KC_LGUI       , MO(_LOWER)    , KC_SPC        , CTL_TAB       , KC_BSPC       , KC_ENT        , MO(_RAISE)    , KC_RALT       , BASE2 \
  ),
   [_LOWER] = LAYOUT( \
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______      	, _______       , _______       , KC_ASTR       , KC_SLSH       ,\
    _______         , _______       , KC_PGUP       , KC_UP         , KC_PGDN       , _______       , _______       ,                                 _______       , KC_COLN       , KC_7          , KC_8          , KC_9          , KC_PPLS       , KC_PAST       ,\
    _______         , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_END        , _______       ,                                 _______       , KC_EQL        , KC_4          , KC_5          , KC_6          , KC_PMNS       , KC_PSLS       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , KC_0          , KC_1          , KC_2          , KC_3          , KC_DOT        , KC_DEL        ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , KC_SPC        , _______ \
  ),
   [_RAISE] = LAYOUT( \
    KC_F12          , KC_F1         , KC_F2         , KC_F3         , KC_F4         , KC_F5         , _______       ,                                 _______       , KC_F6         , KC_F7         , KC_F8         , KC_F9         , KC_F10        , KC_F11        ,\
    _______         , _______       , _______       , _______       , _______       , KC_PLUS       , _______       ,                                 _______       , KC_COLN       , _______       , _______       , _______       , _______       , _______       ,\
    _______         , KC_LT         , KC_LPRN       , KC_LCBR       , KC_LBRC       , KC_MINUS      , _______       ,                                 _______       , KC_EQL        , KC_RBRC       , KC_RCBR       , KC_RPRN       , KC_GT         , _______       ,\
    _______         , _______       , _______       , _______       , _______       , KC_UNDS       , _______       , _______       , _______       , _______       , KC_VOLD       , KC_VOLU       , KC_MPRV       , KC_MNXT       , KC_MPLY       , KC_MUTE       ,\
                                                      _______       , _______       , _______       , _______       , KC_DEL        , _______       , _______       , _______       , _______       , _______ \
  ),
   [_ADJUST] = LAYOUT( \
    KC_SLEP         , _______       , KC_ACL0       , KC_ACL1       , KC_ACL2       , _______       , Q_RESET       ,                                 EE_CLR        , _______       , RGB_TOG       , RGB_M_SW      , _______       , _______       , RGB_TOG       ,\
    _______         , _______       , KC_BTN1       , KC_MS_U       , KC_BTN2       , KC_PSCR       , _______       ,                                 _______       , _______       , RGB_HUI       , RGB_HUD       , RGB_SAI       , RGB_SAD       , _______       ,\
    _______         , _______       , KC_MS_L       , KC_MS_D       , KC_MS_R       , _______       , _______       ,                                 _______       , _______       , RGB_MOD       , RGB_RMOD      , RGB_SPI       , RGB_SPD       , _______       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , RGB_VAI       , RGB_VAD       , _______       , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_BASE2]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER]  = { ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_RAISE]  = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_MOD, RGB_RMOD) },
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
            break;
        case BASE2:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE2);
            }
            return false;
            break;
    }
    return true;
}

#if defined(IGNORE_MOD_TAP_INTERRUPT_PER_KEY)
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return false;
        case RSFT_T(KC_SPC):
            return false;
        default:
            return true;
    }
}
#endif

#if defined(HOLD_ON_OTHER_KEY_PRESS_PER_KEY)
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return true;
        case RSFT_T(KC_SPC):
            return true;
        default:
            return false;
    }
}
#endif

#if defined(OLED_ENABLE)

#    define w_val(str, val)                         \
        snprintf(buffer, sizeof(buffer), str, val); \
        oled_write_ln(buffer, false)

void render_display(void) {
    static layer_state_t last_state    = ~0;
    layer_state_t current_state = get_highest_layer(layer_state);

    if (last_state != current_state) {
        oled_clear();
        last_state = current_state;
    }

    char buffer[25];
    switch (current_state) {
        case _ADJUST:
            oled_write_ln("ADJUST", false);
            oled_write_ln("Keyb | RGB", false);
#    if defined(DEBUG_MATRIX_SCAN_RATE)
            w_val("%05ld", get_matrix_scan_rate());
#    endif
#    if defined(RGB_MATRIX_ENABLE)
            oled_write_ln("RGB", false);
            w_val("En:   %03d", rgb_matrix_config.enable);
            w_val("Mode: %03d", rgb_matrix_config.mode);
            w_val("Hue:  %03d", rgb_matrix_config.hsv.h);
            w_val("Sat:  %03d", rgb_matrix_config.hsv.s);
            w_val("Bri:  %03d", rgb_matrix_config.hsv.v);
            w_val("Spd:  %03d", rgb_matrix_config.speed);
            break;
#    endif
            break;
        case _LOWER:
            oled_write_ln("LOWER", false);
            oled_write_ln("Fn", false);
            oled_write_ln("Num", false);
            oled_write_ln("Sym", false);
            break;
        case _RAISE:
            oled_write_ln("RAISE", false);
            oled_write_ln("Nav | Numpad", false);
            break;
        default:
            if (is_keyboard_master()) {
                oled_write_ln("\x7QWERTY\x7", false);
            } else {
                oled_write_ln("QWERTY", false);
            }
            layer_state_t current_default_layer = get_highest_layer(default_layer_state);
            switch (current_default_layer)
            {
                case (_BASE): oled_write_ln("BASE", false); break;
                case (_BASE2): oled_write_ln("BASE2", false); break;
            }
            break;
    }
}
#endif
