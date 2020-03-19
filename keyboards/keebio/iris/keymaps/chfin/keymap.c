#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────────────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────────────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT(_ADJUST, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────────────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,             KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────────────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────────────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                KC_LALT, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_LGUI
                                            // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                              ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                              ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                              ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                                KC_RBRC, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_HOME,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐            ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_DOWN, KC_LCBR, KC_MEDIA_PLAY_PAUSE,  KC_RPRN, KC_RCBR, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘            └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                        KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                     └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_P1,   KC_P2,   KC_PLUS, KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                       ┌───────────┬───────────┬──────────────┬─────────────┬──────────────┬──────────────┐
     RGUI(KC_Q), RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5),                         RGUI(KC_6), RGUI(KC_7), RGUI(KC_8),    RGUI(KC_9),   RGUI(KC_0),    KC_NO,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                       ├───────────┼───────────┼──────────────┼─────────────┼──────────────┼──────────────┤
     _______,    RGUI(KC_A), RGUI(KC_W), RGUI(KC_E), RGUI(KC_R), RGUI(KC_T),                         RGUI(KC_Z), RGUI(KC_U), RGUI(KC_I),    RGUI(KC_O),   RGUI(KC_P),    RGUI(KC_BSLS),
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                       ├───────────┼───────────┼──────────────┼─────────────┼──────────────┼──────────────┤
     KC_LSFT,    RGUI(KC_A), RGUI(KC_S), RGUI(KC_D), RGUI(KC_F), RGUI(KC_G),                         RGUI(KC_H), RGUI(KC_J), RGUI(KC_K),    RGUI(KC_L),   RGUI(KC_SCLN), RGUI(KC_QUOT),
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼─── ─────┐   ┌─────────┼───────────┼───────────┼──────────────┼─────────────┼──────────────┼──────────────┤
     KC_LCTL,    RGUI(KC_Z), RGUI(KC_X), RGUI(KC_C), RGUI(KC_V), RGUI(KC_B),  _______,     _______,  RGUI(KC_N), RGUI(KC_M), RGUI(KC_COMM), RGUI(KC_DOT), RGUI(KC_SLSH), KC_RSFT,
  //└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬────┘   └───┬─────┴─────┬─────┴─────┬─────┴────┬─────────┴─────────────┴──────────────┴──────────────┘
                                               KC_LGUI,    _______,    RGUI(KC_ENT),           RGUI(KC_SPC), _______,  KC_RALT
                                           // └───────────┴───────────┴────────────┘          └───────────┴───────────┴──────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  // clockwise is reversed
  if (index == 0) {
    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
      break;
    case _LOWER:
      clockwise ? tap_code(KC_MEDIA_PREV_TRACK) : tap_code(KC_MEDIA_NEXT_TRACK);
      break;
    case _RAISE:
      clockwise ? tap_code(KC_BRIGHTNESS_DOWN) : tap_code(KC_BRIGHTNESS_UP);
      break;
    }
  }
  else if (index == 1) {
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
      //rgblight_setrgb (0x00,  0x00, 0x00);
      break;
    case _LOWER:
      //rgblight_setrgb (0x00,  0x00, 0x00);
      break;
    case _ADJUST: //#1a5fb4
      rgblight_setrgb_range (0x1A,  0x5F, 0xB4, 0, 12);
      break;
    default: //  for any other layers, or the default layer
      rgblight_setrgb_range (0x00,  0x00, 0x00, 0, 12);
      break;
    }
  return state;
}
