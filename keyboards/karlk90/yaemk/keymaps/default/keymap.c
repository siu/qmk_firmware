#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

enum Layers {
    _BASE = 0,
    _SYM  = 1,
    _NAV  = 2,
    _FN   = 3,
    _RGB  = 4,
    _GAME = 5,
};

enum Encoder {
    _ENCODER_LEFT  = 0,
    _ENCODER_RIGHT = 1,
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT( \
     KC_ESC         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , LCTL(KC_GRV)  ,                                 KC_ESC        , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_MINS       ,\
     KC_TAB         , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , MO(_RGB)      ,                                 MO(_RGB)      , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_LBRC       ,\
     MO(_SYM)       , LGUI_T(KC_A)  , LALT_T(KC_S)  , LCTL_T(KC_D)  , LT(_SYM,KC_F) , KC_G          , MO(_FN)       ,                                 MO(_FN)       , KC_H          , LT(_SYM, KC_J), LCTL_T(KC_K)  , LALT_T(KC_L)  ,LGUI_T(KC_SCLN), KC_QUOT       ,\
     MO(_NAV)       , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , KC_BSPC       , MO(_NAV)      , MO(_NAV)      , KC_ENT        , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , MO(_NAV)      ,\
                                                      TG(_GAME)     , KC_ESC        , LSFT_T(KC_SPC), KC_BSPC       , MO(_NAV)      , MO(_NAV)      , KC_ENT        , RSFT_T(KC_SPC), KC_RALT       , TG(_GAME)\
  ),
   [_SYM] = LAYOUT( \
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , _______       , _______       ,\
    _______         , _______       , US_UNDS       , US_LBRC       , US_RBRC       , US_DCIR       , _______       ,                                 _______       , US_EXLM       , US_LABK       , US_RABK       , US_EQL        , US_AMPR       , _______       ,\
    _______         , US_BSLS       , US_SLSH       , US_LCBR       , US_RCBR       , US_ASTR       , _______       ,                                 _______       , US_QUES       , US_LPRN       , US_RPRN       , US_MINS       , US_COLN       , US_AT         ,\
    _______         , US_HASH       , US_DLR        , US_PIPE       , US_DTIL       , US_DGRV       , _______       , _______       , _______       , _______       , US_PLUS       , US_PERC       , S(KC_QUOT)    , KC_QUOT       , US_SCLN       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
   [_NAV] = LAYOUT( \
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , _______       , _______       , _______       , KC_ASTR       , KC_SLSH       ,\
    _______         , KC_PGUP       , KC_BSPC       , KC_UP         , KC_DELETE     , KC_PGDN       , _______       ,                                 _______       , _______       , KC_7          , KC_8          , KC_9          , KC_PLUS       , KC_MINS       ,\
    _______         , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_END        , _______       ,                                 _______       , _______       , KC_4          , KC_5          , KC_6          , KC_COMM       , KC_DOT        ,\
    _______         , KC_ESC        , KC_TAB        , _______       , KC_ENT        , _______       , _______       , _______       , _______       , _______       , _______       , KC_1          , KC_2          , KC_3          , KC_SCLN       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , KC_0          , _______       , _______ \
  ),
   [_FN] = LAYOUT( \
    _______         , _______       , KC_ACL0       , KC_ACL1       , KC_ACL2       , RESET         , _______       ,                                 _______       , RESET         , KC_F10        , KC_F11        , KC_F12        , _______       , _______       ,\
    _______         , _______       , KC_BTN1       , KC_MS_U       , KC_BTN2       , KC_PSCR       , _______       ,                                 _______       , _______       , KC_F7         , KC_F8         , KC_F9         , _______       , _______       ,\
    _______         , _______       , KC_MS_L       , KC_MS_D       , KC_MS_R       , _______       , _______       ,                                 _______       , _______       , KC_F4         , KC_F5         , KC_F6         , _______       , _______       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , KC_F1         , KC_F2         , KC_F3         , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
  [_RGB] = LAYOUT( \
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , RGB_TOG       , RGB_M_SW      , _______       , _______       , _______       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , RGB_HUI       , RGB_HUD       , RGB_SAI       , RGB_SAD       , _______       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , RGB_MOD       , RGB_RMOD      , RGB_SPI       , RGB_SPD       , _______       ,\
    _______         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , RGB_VAI       , RGB_VAD       , _______       , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
  [_GAME] = LAYOUT( \
     KC_ESC         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , LCTL(KC_GRV)  ,                                 KC_ESC        , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_MINS       ,\
     KC_TAB         , KC_LSFT       , KC_Q          , KC_X          , KC_E          , KC_R          , KC_T          ,                                 _______       , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_LBRC       ,\
     KC_LSFT        , KC_LSFT       , KC_A          , KC_W          , KC_D          , KC_F          , KC_G          ,                                 _______       , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     KC_LALT        , KC_LCTL       , KC_Z          , KC_S          , KC_C          , KC_V          , KC_SPC        , KC_BSPC       , KC_BSPC       , KC_ENT        , KC_ENT        , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       ,\
                                                      _______       , KC_LCTL       , KC_SPC        , KC_SPC        , KC_LGUI       , KC_CAPS       , KC_ENT        , KC_SPC        , KC_LALT       , _______
  )
};

// clang-format on

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
    layer_state_t current_state = get_highest_layer(layer_state);

    if (index == _ENCODER_LEFT) {
        if (clockwise) {
            switch (current_state) {
                case _BASE:
                default:
                    tap_code(KC_MS_WH_DOWN);
                    break;
                case _NAV:
                    tap_code(KC_MS_WH_RIGHT);
                    break;
                case _FN:
                    tap_code_delay(KC_AUDIO_VOL_UP, 10);
                    break;
                case _RGB:
                    tap_code(KC_PGUP);
                    break;
            }
        } else {
            switch (current_state) {
                case _BASE:
                default:
                    tap_code(KC_MS_WH_UP);
                    break;
                case _NAV:
                    tap_code(KC_MS_WH_LEFT);
                    break;
                case _FN:
                    tap_code_delay(KC_AUDIO_VOL_DOWN, 10);
                    break;
                case _RGB:
                    tap_code(KC_PGDN);
                    break;
            }
        }
    } else if (index == _ENCODER_RIGHT) {
        if (clockwise) {
            switch (current_state) {
                case _BASE:
                default:
                    tap_code(KC_MS_WH_DOWN);
                    break;
                case _NAV:
                    tap_code(KC_MS_WH_RIGHT);
                    break;
                case _FN:
                    tap_code_delay(KC_MEDIA_NEXT_TRACK, 10);
                    break;
                case _RGB:
                    tap_code(KC_PGUP);
                    break;
            }
        } else {
            switch (current_state) {
                case _BASE:
                default:
                    tap_code(KC_MS_WH_UP);
                    break;
                case _NAV:
                    tap_code(KC_MS_WH_LEFT);
                    break;
                case _FN:
                    tap_code_delay(KC_MEDIA_PREV_TRACK, 10);
                    break;
                case _RGB:
                    tap_code(KC_PGDN);
                    break;
            }
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
    layer_state_t        current_state = get_highest_layer(layer_state);

    if (last_state <= _NAV && current_state <= _NAV) {
        // Don't do anything if we are on the default layers
        return;
    } else if (last_state != current_state) {
        oled_clear();
        last_state = current_state;
    } else if (current_state != _RGB && current_state != _FN) {
        return;
    }

    char buffer[25];
    switch (current_state) {
        case _FN:
            oled_write_ln("Function\n", false);
#    if defined(DEBUG_MATRIX_SCAN_RATE)
            oled_write_ln("Scan Freq:", false);
            w_val("%05ld", get_matrix_scan_rate());
#    endif
            break;
        case _RGB:
#    if defined(RGB_MATRIX_ENABLE)
            oled_write_ln("RGB\n", false);
            w_val("En:   %03d\n", rgb_matrix_config.enable);
            w_val("Mode: %03d\n", rgb_matrix_config.mode);
            w_val("Hue:  %03d\n", rgb_matrix_config.hsv.h);
            w_val("Sat:  %03d\n", rgb_matrix_config.hsv.s);
            w_val("Bri:  %03d\n", rgb_matrix_config.hsv.v);
            w_val("Spd:  %03d\n", rgb_matrix_config.speed);
            break;
#    endif
        case _GAME:
            oled_write_ln("Game", false);
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
