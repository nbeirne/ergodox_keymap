#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.     ,--------------------------------------------------.
 * |  Esc   | 1  ! | 2  @ | 3  # | 4  $ | 5  % | ` ~  |     | + =  | 6  ^ | 7  & | 8  * | 9  ( | 0  ) |  + _   |
 * |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | [ {  |     | } ]  |   Y  |   U  |   I  |   O  |   P  | \   |  |
 * |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
 * |  Ctrl  |  *A  |   S  |  D   |  *F  |   G  |------|     |------|   H  |  *J  |   K  |   L  |*;  : |  ' "   |
 * |--------+------+------+------+------+------|  L1  |     | L1   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |     |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
 *   |  L2  |      | LGui | Alt  | Ctrl |                                 | Ctrl | Alt  | RGui |      |  L2  | 
 *   `----------------------------------'                                 `----------------------------------'
 *                                      ,--------------.   ,--------------.
 *                                      |  Esc  | Ctrl |   | Ctrl |  Esc  |
 *                               ,------|-------|------|   |------+-------+------.
 *                               |      |       |  Alt |   | Alt  |       |      |
 *                               | Bksp |  Del  |------|   |------| Enter |Space |
 *                               |      |       | LGUI |   | LGUI |       |      |
 *                               `---------------------'   `---------------------'
 */
/*
 * hold F/A/J/; - should reverse
 * hold l1/l2:  - work as expected
 * tap l1/l2:   - next keypress should be on that layer
 *
 * double tap `~: press ~
 * double tap brace: curly
 *
 * media layers
 *
 * shortcuts:
 *    ctrl+(arrows) <- mac  workspaces
 *    gui+(arrows) <- linux workspaces
 *    gui+shift+arrows
 *    ctrl+alt+??
 *    shift+ctrl+f - find in android
 *    gui+shift+o  - goto in xcode/android
 */

[BASE] = KEYMAP(  // layer 0 : default
  // left hand
  KC_ESC,     KC_1,    KC_2,     KC_3,     KC_4,          KC_5,  KC_GRV,
  KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,          KC_T,  KC_LBRC,
  KC_LCTL,    KC_A,    KC_S,     KC_D,     KC_F,          KC_G,
  KC_LSFT,    KC_Z,    KC_X,     KC_C,     KC_V,          KC_B,  MO(1),
  MO(2),      KC_NO,   KC_LGUI,  KC_LALT,  KC_LCTRL,

                                               KC_ESC,    KC_LCTRL,
                                                          KC_LALT,
                                     KC_BSPC,  KC_DEL,    KC_LGUI,

  // right hand
  KC_EQL,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_MINS,
  KC_RBRC, KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
           KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
  MO(1),   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_RSFT,
                     KC_RCTRL, KC_RALT,  KC_RGUI,  KC_NO,   MO(2),

  KC_RCTRL, KC_ESC,
  KC_RALT,
  KC_RGUI,  KC_ENT,  KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   `    |   !  |   @  |   {  |   }  |   |  |      |           |      | Home | PgUp |  End |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      | PgDn |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  Spc | Ent  |------|       |------| Bksp | Del  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
       KC_GRAVE, KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
       KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  

                                     KC_TRNS,  KC_TRNS,
                                               KC_TRNS,
                           KC_SPC,   KC_ENT,   KC_TRNS,

       // right hand
       KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,
       KC_TRNS,  KC_HOME,  KC_PGUP,  KC_END,   KC_TRNS,   KC_TRNS,  KC_F12,
                 KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BSPC, KC_DEL
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Mup  | Expl |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |GuiLft|GuiDwn|GuiRgt|      |      |------|           |------| Left | Down |  Up  |Right |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |VolDwn|VolUp | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       | Play | Prev | Next |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------|Fwd   |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
KEYMAP(
         RESET, KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,     KC_MS_U,  KC_TRNS,     KC_BTN1, LGUI(KC_T), KC_TRNS,
       KC_TRNS, KC_MS_L,     KC_MS_D,  KC_MS_R,     KC_MS_D, KC_MS_R,
       KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,  KC_TRNS, KC_TRNS,
                          KC_MPLY, KC_MPRV, KC_MNXT,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_WBAK, KC_WFWD
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
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
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
