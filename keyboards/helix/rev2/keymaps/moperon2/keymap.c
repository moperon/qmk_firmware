/* Copyright 2020 yushakobo
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
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  EISU,
  KANA,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | -_   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ;:  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |  ,<  |  .>  |  /?  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |      |Option| CMD  |Lower |Space |Space |Raise |  CMD | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT( \
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      ADJUST,  XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |  1!  |  2@  |  3#  |  4$  |  5%  |             |  6^  |  7&  |  8*  |  9(  |  0)  |  -_  |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------|
   * | ESC  |  1!  |  2@  |  3#  |  4$  |  5%  |             |  6^  |  7&  |  8*  |  9(  |  0)  | Del  |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------|
   * | Ctrl |  F1  |  F2  |  F3  |  F4  |  F5  |             | Left | Down |  Up  | Right|  \|  |  '"  |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 |  [   |  ]   |  _   |  +   |  {   |  }   |  |   |  ~   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |      |Option|  CMD |      |Space |Space |ADJUST|  CMD | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, KC_QUOT, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
    _______, _______, _______, _______, _______, _______, _______, _______, ADJUST, _______, _______, _______, _______, _______ \
  ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |  !   |  @   |  #   |  $   |  %   |             |  ^   |  &   |  *   |  (   |  )   |  -_  |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------|
   * | ESC  |  !   |  @   |  #   |  $   |  %   |             |  ^   |  &   |  *   |  (   |  )   |  -_  |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------|
   * | Ctrl |  F1  |  F2  |  F3  |  F4  |  F5  |             |  `~  |  =+  |  [{  |  ]}  |  \|  |  '"  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 |  [   |  ]   |  _   |  +   |  {   |  }   |  |   |  ~   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|             |Option|  CMD |ADJUST|Space | Space|      | CMD  | Home |PgDown| PgUp | End  |
   * `-------------------------------------------------------------------------------------------------'
   */

  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, \
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_GRV,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
    _______, _______, _______, _______, _______, ADJUST,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
  ),

  /* Adjust (Lower + Raise) TODO
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | RESET|      |      |      |      |      |             |      |      |      | Mute | VolDn| VolUp|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |RGBTOG| Mode | Hue+ | Sat+ | Va+  | SP+  |             | Home |PgDown| PgUp | End  |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |RGB_M_P|RMode| Hue- | Sat- | Va-  | SP-  |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,KC__MUTE,KC__VOLDOWN,KC__VOLUP,
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                   KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
      RGB_M_P,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      )
};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      break;
  }
  return true;
}

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_get_mode();
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}
