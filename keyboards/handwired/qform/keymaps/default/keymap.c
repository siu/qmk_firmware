#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define LO_ENT LT(_LOWER, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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

#if 0
  [_LOWER] = LAYOUT_5x6(
//  @         @         @         @         @         @         @         @         @         @         @         @         @
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,
                                            _______,  _______,            _______,  _______,
                                            _______,  _______,            _______,  _______
  )
#endif
