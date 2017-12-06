#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_french.h"

#define BASE 0 // default Colemak Mod-DH layer
#define QWERTY 1 // qwerty
#define SYMB 2 // symbols
#define MDIA 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base Colemak Mod-DH layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   B  | TO(0)|           |TO(2) |   J  |   L  |   U  |   Y  |   ;  | Del    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  | Bcksp  |
 * |--------+------+------+------+------+------| TO(1)|           |TG(3) |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   :  | Rshift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ins  | Caps | Left | Right| MO(1)|                                       | MO(1)| Down |  Up  | PgDn | PgUp  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Tmx  | Cslt |       | RAlt | LGui   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | End  |        |      |
 *                                 | Space| Back |------|       |------| Ctrl   |Enter |
 *                                 |      |      | Hype |       | Mehe |        |      |
 *                                 `--------------------'       `--------------------'
 */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TRNS,        KC_Q,         KC_W,   KC_F,   KC_P,   KC_B,   TO(BASE),
        KC_TAB,         KC_A,         KC_R,   KC_S,   KC_T,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_D,   KC_V,   TO(SYMB),
        KC_INS,         KC_CAPS,      KC_LEFT,KC_RIGHT, MO(SYMB),
                                               RCTL(KC_B),  LALT(KC_LSFT),
                                                                  KC_HOME,
                                               KC_SPC, KC_BSPC,   ALL_T(KC_NO),
        // right hand
        KC_RGHT,     KC_6,    KC_7,   KC_8,     KC_9,    KC_0,             KC_TRNS,
        TO(MDIA),    KC_J,    KC_L,   KC_U,     KC_Y,    KC_SCLN,          KC_DELT,
                     KC_M,    KC_N,   KC_E,     KC_I,    KC_O,             KC_BSPC,
        TG(QWERTY),    KC_K,    KC_H,   KC_COMM,  KC_DOT,  KC_COLN,          KC_RSFT,
        MO(SYMB),    KC_DOWN, KC_UP,  KC_PGDN,  KC_PGUP,

        KC_RALT,        KC_LGUI,
        KC_END,
        MEH_T(KC_NO),KC_RCTL, KC_ENT
                  ),
/* Keymap 3: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |  LGui  |
 * |--------+------+------+------+------+------| Hyper|           |      |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  '"  |Left  | Right |MO(4)|                                | MO(4)| Up   |  Down|   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [QWERTY] = KEYMAP(  // layer 1
  // left hand
  KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
  KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
  KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
  KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
  KC_TRNS,KC_QUOT, KC_LEFT,KC_RGHT, MO(SYMB),
                                        ALT_T(KC_APP),  KC_LGUI,
                                                        KC_HOME,
                                         KC_SPC,KC_BSPC,KC_END,
  // right hand
       KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
       KC_TRNS,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                    KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN,KC_LGUI,
       KC_TRNS,KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                            MO(SYMB), KC_UP,  KC_DOWN,KC_RBRC,     KC_TRNS,
       KC_LALT,        CTL_T(KC_ESC),
       KC_PGUP,
       KC_PGDN,KC_TAB, KC_ENT
),


/* Keymap 2: Symbol Layer
 * // TODO missing: ¤
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   §  |   <  |   {  |   \  |   ~  |      |           |      |   %  |   @  |   }  |  >   |  µ   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   '  |   =  |   -  |   (  |   +  |------|           |------|   *  |   )  |   _  |  /   |   "  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   `  |   ?  |   #  |   [  |   |  |      |           |      |   &  |   ]  |   $  |   !  |   ^  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   €  |   £  |   $  |      |      |                                       |      |      |      |   ß  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_LABK,  KC_LCBR,KC_BSLS,KC_TILD,KC_TRNS,
       KC_TRNS,KC_QUOT,KC_EQL, KC_MINS,KC_LPRN,KC_PLUS,
       KC_TRNS,KC_GRV,KC_QUES,KC_HASH,KC_LBRC,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_DLR,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_PERC, KC_AT,  KC_RCBR, KC_RABK, KC_TRNS, KC_F12,
       KC_ASTR,   KC_RPRN, KC_UNDS, KC_SLSH, S(KC_QUOT), KC_TRNS,
       KC_TRNS, KC_AMPR,  KC_RBRC, KC_DLR,  KC_EXLM,  KC_CIRC, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS,  ALGR(KC_S),  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Lclk | Rclk |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    case QWERTY:
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
    }

};
