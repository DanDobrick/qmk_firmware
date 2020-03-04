/* Copyright 2019 Dan Dobrick
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

/* This is adapted from the official ANSI layout provided by the KBP V60 Type R
* as depicted in their manual and on the stock keycaps.
*/
#include QMK_KEYBOARD_H

// Custom Keycodes
#define TAB_MEH MT(MOD_MEH, KC_TAB)
#define _______ KC_TRNS

// Layer names; using underscore to differentiate between layers and other variables
enum layers {
  _QWERTY,
  _FUNC,
  _CTRL,
  _MOUSE
};

// enum for Tap Dance
enum {
  TD_SHIFT_CAPS = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPS] =  ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _QWERTY: Default Layer (Qwerty)
   * CAPS opens Layer 1 if held and triggers ESC when tapped.
   * Fn toggles layer 1 on/off.
   * ,-------------------------------------------------------------.
   * |  `  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-------------------------------------------------------------|
   * |Tab/Meh|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-------------------------------------------------------------|
   * |LT(1,Esc)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-------------------------------------------------------------|
   * |LShift    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-------------------------------------------------------------|
   * |Ctrl|Alt |Gui |        Space             |_FUNC|Gui|Lead|Ctrl|
   * `-------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT_60_ansi(
	       KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       TAB_MEH,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
	       LT(1, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
	       TD(TD_SHIFT_CAPS),       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,   \
	       KC_LCTL,        KC_LALT, KC_LGUI,          KC_SPC,                                      TO(_FUNC),   KC_RGUI, KC_LEAD,  KC_RCTL),

  /* _FUNC: FN Layer
   * Backlight/Underglow keys are all the same as the printed keys
   * Arrow keys are like vim but shifted by one (jkl;)
   * Pause is mapped to media pause and previous/skip abut it.
   * ,-----------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |Prv|Pau|Nxt|   |      |
   * |-----------------------------------------------------------|
   * |     |C+<-|   |C+->|   |   |   |Up |Dwn|Lft|Rgt|   |       |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |Vld|Vlu|Mut|   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                     |_QWERTY|    |    |    |
   * `-----------------------------------------------------------'
   */
  [_FUNC] = LAYOUT_60_ansi(
	       _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,        KC_F6,       KC_F7,    KC_F8,     KC_F9,        KC_F10,  KC_F11,   KC_F12,  KC_DEL, \
	       _______,   _______,  _______,  _______,  _______,  _______,      _______,     _______,  _______,   KC_MPRV,      KC_MPLY,  KC_MNXT,  _______, _______, \
	       _______,   C(KC_LEFT), _______,  C(KC_RIGHT),  _______,  _______,      _______,     KC_UP,    KC_DOWN,   KC_LEFT,      KC_RIGHT, _______,      _______, \
	       _______,   _______,  _______,  _______,  _______,  KC__VOLDOWN,  KC__VOLUP,   KC__MUTE, _______,   _______,      _______,           _______,  \
	       _______,   _______,  _______,            _______,                                                  TO(_QWERTY),  _______, TO(_MOUSE), _______),
    
  /* _MOUSE: mouse Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |MUP|   |   |   |   |   |    |   |   |   |   |    |
   * |-----------------------------------------------------------|
   * |      |MLt|MDn|MRt|   |   |   |   |   |   |   |   |   Ms1  |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                     |_QWERTY|   |   |    |
   * `-----------------------------------------------------------'
   */
  [_MOUSE] = LAYOUT_60_ansi(
	       _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______, _______,  _______, _______, \
	       _______,   _______,  KC_MS_UP,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______, _______,  _______, _______, \
	    TO(_QWERTY),   KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  _______,  _______,  _______,  _______, _______, _______,  _______, _______,      KC_MS_BTN1, \
	       _______,   _______,   _______,  _______,   _______,  _______,  _______,  _______, _______, _______,  _______,           _______,  \
	       _______,   _______,  _______,            _______,                                                  TO(_QWERTY),  _______, _______, _______),


  /* CTRL: Control Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |RGB|HUI|SAI|VAI|   |    |   |   |   |   |    |
   * |-----------------------------------------------------------|
   * |      |   |   |   |HUD|SAD|VAD|   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |BLD|BLT|BLI|   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                     |_QWERTY|   |RESET|    |
   * `-----------------------------------------------------------'
   */
  [_CTRL] = LAYOUT_60_ansi(
	       _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______, _______,  _______, _______, \
	       _______,   _______,  _______,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______, _______, _______,  _______, _______,  _______, _______, \
         _______,   _______,  _______,  _______,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______, _______, _______,  _______, _______,      _______, \
	       _______,   BL_DEC,   BL_STEP,  BL_INC,   _______,  _______,  _______,  _______, _______, _______,  _______,           _______,  \
	       _______,   _______,  _______,            _______,                                                  TO(_QWERTY),  _______, RESET, _______),

};

// Leader Key
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Switch to CTRL layer
    SEQ_THREE_KEYS(KC_C, KC_M, KC_D) {
      layer_invert(_CTRL);
    }
  }
}


// changes underglow based on current layer
#define RBG_VAL 120
layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
  case _FUNC:
    // green-ish
    rgblight_sethsv_noeeprom(72, 221, RBG_VAL);
    break;
  case _CTRL:
    // Red
    rgblight_sethsv_noeeprom(0, 255, RBG_VAL);
    break;
  case _MOUSE:
    // Dark Blue
    rgblight_sethsv_noeeprom(255, 0, RBG_VAL);
    break;
  default:
    // Default colors
    rgblight_sethsv(32, 170, RBG_VAL);
    break;
  }
  return state;
}

// Handle Caps lock led
void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
      // output low
      DDRE  |=  (1<<PE6);
      PORTE &= ~(1<<PE6);
  }
  else {
      // Hi-Z
      DDRE  &= ~(1<<PE6);
      PORTE &= ~(1<<PE6);
  }
}

// // Turn lights on/of when computer powers on/off
// extern rgblight_config_t rgblight_config;
// extern backlight_config_t backlight_config;
// void suspend_power_down_user(void)
// {
//   // rgb
//   rgblight_config.enable = false;
//   rgblight_set();

//   // backlight
//   /** I don't know why, but 3 means "off" and down is up */
//   backlight_config.level = 3;
//   backlight_config.enable = false;
//   backlight_set(3);
// }

// void suspend_wakeup_init_user(void)
// {
//   rgblight_config.raw = eeconfig_read_rgblight();
//   backlight_config.raw = eeconfig_read_backlight();

//   backlight_set(backlight_config.level);
//   rgblight_set();
// }
