#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |  -_  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |  ;:  |Enter |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |  ,>  |  .>  |  /?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |Adjust|      |Option| CMD  |||||||| Lower| Space|      ||||||||      | Space| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                        XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,                        XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,                        XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    ADJUST,  XXXXXXX, KC_LALT, KC_LGUI,          LOWER,   KC_SPC ,KC_SPC,          KC_SPC,KC_SPC , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |  1!  |  2@  |  3#  |  4$  |  5%  |      |                    |      |  6^  |  7&  |  8*  |  9(  |  0)  |  -_  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |  1!  |  2@  |  3#  |  4$  |  5%  |      |                    |      |  6^  |  7&  |  8*  |  9(  |  0)  | Del  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      | Left | Down |  Up  | Right|  \|  |  '"  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 |      |                    |      |  _   |  +   |  {   |  }   |  |   |  ~   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |Option|  CMD |||||||| Lower|Space |      ||||||||      | Space|Raise ||||||||      |      |      |      |
   * `----------------------------------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                       _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                       _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, KC_QUOT, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,                       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, _______,          _______, _______, _______, _______ \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |  !   |  @   |  #   |  $   |  %   |      |                    |      |  ^   |  &   |  *   |  (   |  )   |  -_  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |  !   |  @   |  #   |  $   |  %   |      |                    |      |  ^   |  &   |  *   |  (   |  )   |  -_  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  `~  |  =+  |  [{  |  ]}  |  \|  |  '"  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 |      |                    |      |  _   |  +   |  {   |  }   |  |   |  ~   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |Option|  CMD |||||||| Lower|Space |      ||||||||      | Space|Raise |||||||| Home |PgDown| PgUp | End  |
   * `----------------------------------------------------------------------------------------------------------------------'
   */

  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,                        XXXXXXX, KC_GRV,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,                        XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
    _______, _______, _______, _______,          _______, _______,KC_SPC,          KC_SPC,_______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END \
  ),


 /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |BrtDwn|BrtUp |      |      |      |      |                    |      |      |      | MUTE |VolDwn| VolUp|      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |RGB ON| MODE+| HUE+ | SAT+ | VAL+ |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | MODE-| HUE- | SAT- | VAL- |      |                    |      | Home |PgDown| PgUp | End  |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BLTgl|BLBrtg|  BL+ |  BL- |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    XXXXXXX, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX,KC__MUTE,KC__VOLDOWN,KC__VOLUP,XXXXXXX, \
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,XXXXXXX,                       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_INC,  BL_DEC, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
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
