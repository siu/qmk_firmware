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

/*
  [_QWERTY] = LAYOUT_5x6(
//  @         @         @         @         @         @         @         @         @         @         @         @         @
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_CAPS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
                        KC_LEFT,  KC_RGHT,  KC_LCTRL, KC_SPC,             LO_ENT,   LOWER,    KC_DOWN,  KC_UP,
                                            KC_DEL,   KC_LALT,            KC_1,     KC_BSPC,
                                            KC_LALT,  KC_LGUI,            KC_3,     RAISE
  ),
  [_LOWER] = LAYOUT_5x6(
//  @         @         @         @         @         @         @         @         @         @         @         @         @
    KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_LT,    KC_LPRN,  KC_LCBR,  KC_LBRC,  KC_MINUS,           KC_PLUS,  KC_RBRC,  KC_RCBR,  KC_RPRN,  KC_GT,    _______,
    _______,  _______,  _______,  _______,  _______,  KC_UNDS,            KC_EQUAL, _______,  _______,  _______,  _______,  _______,
                        KC_HOME,  KC_END,   _______,  _______,            _______,  _______,  KC_PGDN,  KC_PGUP,
                                            _______,  _______,            _______,  _______,
                                            _______,  _______,            _______,  _______
  ),
  [_RAISE] = LAYOUT_5x6(
//  @         @         @         @         @         @         @         @         @         @         @         @         @
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    RESET,    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,
                                            _______,  _______,            _______,  _______,
                                            _______,  _______,            _______,  _______
  )
};
*/

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT( \
     KC_GRV         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_NO         ,                                 KC_NO         , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_CAPS       ,\
     KC_TAB         , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_NO         ,                                 KC_NO         , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLS       ,\
     KC_ESC         , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_NO         ,                                 KC_NO         , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     KC_LSPO        , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , _______       , TG(_ADJUST)   , TG(_ADJUST)   , _______       , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , KC_RSPC       ,\
                                                      BASE          , KC_LGUI       , KC_LCTRL      , KC_SPC        , KC_TAB        , KC_BSPC       , KC_ENT        , MO(_LOWER)    , MO(_RAISE)    , BASE2 \
  ),
   [_BASE2] = LAYOUT( \
     KC_GRV         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_NO         ,                                 KC_NO         , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_CAPS       ,\
     KC_TAB         , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_NO         ,                                 KC_NO         , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLS       ,\
     KC_ESC         , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_NO         ,                                 KC_NO         , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     KC_LSPO        , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , _______       , TG(_ADJUST)   , TG(_ADJUST)   , _______       , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , KC_RSPC       ,\
                                                      BASE          , KC_LGUI       , MO(_LOWER)    , KC_SPC        , CTL_TAB       , KC_BSPC       , KC_ENT        , MO(_RAISE)    , KC_RALT       , BASE2 \
  ),
   [_LOWER] = LAYOUT( \
    KC_F12          , KC_F1         , KC_F2         , KC_F3         , KC_F4         , KC_F5         , _______       ,                                 _______       , KC_F6         , KC_F7         , KC_F8         , KC_F9         , KC_F10        , KC_F11        ,\
    _______         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , _______       ,                                 _______       , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , _______       ,\
    _______         , KC_LT         , KC_LPRN       , KC_LCBR       , KC_LBRC       , KC_MINUS      , _______       ,                                 _______       , KC_PLUS       , KC_RBRC       , KC_RCBR       , KC_RPRN       , KC_GT         , _______       ,\
    _______         , _______       , _______       , _______       , _______       , KC_UNDS       , _______       , _______       , _______       , _______       , KC_EQUAL      , _______       , _______       , _______       , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , KC_DEL        , _______       , _______       , _______       , _______       , _______ \
  ),
   [_RAISE] = LAYOUT( \
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______      	, _______       , _______       , KC_ASTR       , KC_SLSH       ,\
    _______         , _______       , KC_PGUP       , KC_UP         , KC_PGDN       , _______       , _______       ,                                 _______       , _______       , KC_7          , KC_8          , KC_9          , KC_PLUS       , KC_MINS       ,\
    _______         , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_END        , _______       ,                                 _______       , _______       , KC_4          , KC_5          , KC_6          , KC_COMM       , KC_DOT        ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , KC_0          , KC_1          , KC_2          , KC_3          , KC_SCLN       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
   [_ADJUST] = LAYOUT( \
    _______         , _______       , KC_ACL0       , KC_ACL1       , KC_ACL2       , _______       , RESET         ,                                 EEP_RST       , _______       , RGB_TOG       , RGB_M_SW      , _______       , _______       , _______       ,\
    _______         , _______       , KC_BTN1       , KC_MS_U       , KC_BTN2       , KC_PSCR       , _______       ,                                 _______       , _______       , RGB_HUI       , RGB_HUD       , RGB_SAI       , RGB_SAD       , _______       ,\
    _______         , _______       , KC_MS_L       , KC_MS_D       , KC_MS_R       , _______       , _______       ,                                 _______       , _______       , RGB_MOD       , RGB_RMOD      , RGB_SPI       , RGB_SPD       , _______       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , RGB_VAI       , RGB_VAD       , _______       , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
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

#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    //layer_state_t current_state = get_highest_layer(layer_state);

    if (index == _ENCODER_RIGHT) {
        if (clockwise) {
            tap_code_delay(KC_AUDIO_VOL_UP, 10);
        } else {
            tap_code_delay(KC_AUDIO_VOL_DOWN, 10);
        }
    } else if (index == _ENCODER_LEFT) {
        if (clockwise) {
            tap_code_delay(KC_MEDIA_NEXT_TRACK, 10);
        } else {
            tap_code_delay(KC_MEDIA_PREV_TRACK, 10);
        }
    }

    return false;
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
            break;
    }
}
#endif
