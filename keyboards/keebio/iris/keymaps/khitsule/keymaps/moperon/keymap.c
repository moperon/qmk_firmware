#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

enum layer_number {
  _QWERTY = 0,
  _KEYPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  EISU,
  KANA,
  KEYPAD
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |  `~  |                    |  '"  |   6  |   7  |   8  |   9  |   0  |  -_  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |\  |                    |  =+  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  [{  |                    |  ]}  |   H  |   J  |   K  |   L  |  ;:  |Enter |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Eisu |                    | Kana |   N  |   M  |  ,>  |  .>  |  /?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |Adjust|      |Option| CMD  |||||||| Lower| Space|      ||||||||      | Space| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.

   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,                         KC_QUOT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSLS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    EISU,                           KANA ,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    ADJUST,  XXXXXXX, KC_LALT, KC_LGUI,          LOWER,   KC_SPC ,KC_SPC,          KC_SPC,KC_SPC , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Keypad mode
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |      |      |      |      |      |  `~  |                    |  '"  |      |  ESC |      |  %   |  /   |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |      |  Up  |      |      |      |  |\  |                    |  =+  |      |  7   |  8   |  9   |  *   | Del  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl | Left | Down | Right|      |      |  [{  |                    |  ]}  |      |  4   |  5   |  6   |  -   | Enter|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      |                    |      |      |  1   |  2   |  3   |  +   | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |Option|  CMD ||||||||      |Space |      ||||||||      | Space|  0   ||||||||  ,   |  .   |  =   |      |
   * `----------------------------------------------------------------------------------------------------------------------'
   */
    [_KEYPAD] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,                        KC_RCBR, XXXXXXX, KC_ESC,  KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
    _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,                       KC_PLUS, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LBRC,                       KC_RBRC, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PENT, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                       _______, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, _______, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, KC_KP_0,           KC_COMM, KC_PDOT, KC_PEQL, XXXXXXX \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |  !   |  @   |  #   |  $   |  %   |  `   |                    |   '  |  ^   |  &   |  *   |  (   |  )   |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  \   |                    |   =  |      |  =   |  [   |  ]   |  \   | Del  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |  F6  |  F7  |  F8  |  F9  |  F10 |  [   |                    |   ]  |      |      |  `   |  '   |  ;   | Enter|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|  F11 |  F12 |      |      |      | Eisu |                    | Kaza |      |      |  ,   |  .   |  /   | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |Option|  CMD |||||||| Lower|Space |      ||||||||      | Space|Raise |||||||| Home |PgDown| PgUp | End  |
   * `-------------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_GRV,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSLS,                       KC_PLUS, XXXXXXX, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LBRC,                       KC_RBRC, XXXXXXX, XXXXXXX, KC_GRV,  KC_QUOT, KC_SCLN, _______, \
    _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, _______,                       _______, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, _______, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   !  |   @  |   #  |   $  |   %  |   ~  |                    |   "  |   ^  |   &  |   *  |   (  |   )  |   _  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |   |  |                    |   +  |      |   +  |   {  |   }  |   |  |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |  F6  |  F7  |  F8  |  F9  |  F10 |   {  |                    |   }  |      |      |   ~  |   "  |   :  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|  F11 |  F12 |      |      |      |      |                    |      |      |      |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |Adjust|      |Option| CMD  |||||||| Lower| Space|      ||||||||      | Space| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD,                        KC_DQUO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PIPE,                        KC_PLUS, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LCBR,                        KC_RCBR, XXXXXXX, XXXXXXX, KC_TILD, KC_DQUO, KC_COLN, _______, \
    _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_QUES, _______, \
    _______, _______, _______, _______,          _______, _______,KC_SPC,          KC_SPC,_______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |BrtDwn|BrtUp |      |      |      |      |                    |      |      |      | MUTE |VolDwn| VolUp|      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |Reset |      |RGB ON| HUE+ | SAT+ | VAL+ |      |                    |      |RGB ON| HUE+ | SAT+ | VAL+ |      |Reset |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |RGBRst|      | MODE | HUE- | SAT- | VAL- |      |                    |      | MODE | HUE- | SAT- | VAL- |      |RGBRst|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BLTgl|BLBrtg|  BL+ |  BL- |QWERTY|                    |KEPAD| BLTgl|BLBrtg|  BL+ |  BL- |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    XXXXXXX, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX,KC__MUTE,KC__VOLDOWN,KC__VOLUP,XXXXXXX, \
    RESET,   XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,XXXXXXX,                       XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, RESET, \
    RGBRST,  XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,XXXXXXX,                       XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, RGBRST, \
    XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_INC,  BL_DEC, QWERTY,                        KEYPAD,  BL_TOGG, BL_BRTG, BL_INC,  BL_DEC,  XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif
bool TOG_STATUS = false;
int RGB_current_mode;
int current_default_layer = _QWERTY;

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
    case KEYPAD:
      if (record->event.pressed) {
        print("mode just switched to keypad and this is a huge string\n");
        set_single_persistent_default_layer(_KEYPAD);
        /*persistent_default_layer_set(1UL<<_KEYPAD);
        current_default_layer = _KEYPAD;*/
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
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
