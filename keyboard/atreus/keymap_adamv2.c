/*
This layout was created by Adam Ford.
To compile: make clean && make KEYMAP=adamv2
To upload: make upload KEYMAP=adam USB=/dev/cu.usbmodem14311
Or use Avrodudess with the following settings:
  - Programmer: AVR109
  - MCU: ATmega32U4
  -Port: find port by going to device manager "Ports" section when in bootloader mode
NO_TRACK_KEY_PRESS
*/

#include "keymap_common.h"
#include "config.h"


// Reduce the time to decision of a tap or hold
#define TAPPING_TERM 150

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define BOOT  0 // Bootloader (not to be confused with default layer)
#define ALPH  0 // Alphabet Layer
#define NUMS  1 // Number Layer
#define FKEY  2 // Function Key Layer
#define SYMB  4 // Symbol Layer
#define IDE   5 // IDE layer
#define NAV   6 // Navigation layer
#define SFSP  7 // Right Shift or Space
#define SFBS  8 // Left shift or Backspace
#define CTES  9 // Control or Escape
#define OPGV  10 // Option or Grave/tilde

#define FN_BOOT (KC_FN0 + BOOT)
#define FN_NUMS (KC_FN0 + NUMS)
#define FN_FKEY (KC_FN0 + FKEY)
#define FN_SYMB (KC_FN0 + SYMB)
#define FN_IDE  (KC_FN0 + IDE)
#define FN_NAV  (KC_FN0 + NAV)
#define FN_SFSP (KC_FN0 + SFSP)
#define FN_CTES (KC_FN0 + CTES)
#define FN_SFBS (KC_FN0 + SFBS)
#define FN_OPGV (KC_FN0 + OPGV)

// Helpers for IDE layer
#define IDE_RENAME ACTION_MODS_KEY(MOD_LSFT, KC_F6)
#define IDE_FIND_USAGES ACTION_MODS_KEY(MOD_LGUI | MOD_LALT, KC_F7)
#define IDE_LINE_U ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_UP)
#define IDE_LINE_D ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_DOWN)
#define IDE_LINE_R ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_RGHT)
#define IDE_LINE_L ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_LEFT)
#define IDE_COMPILE ACTION_MODS_KEY(MOD_LGUI, KC_F9)
#define IDE_CHANGE_SIG ACTION_MODS_KEY(MOD_LGUI, KC_F6)
#define IDE_NAV_B ACTION_MODS_KEY(MOD_LGUI | MOD_LALT, KC_LEFT)
#define IDE_NAV_F ACTION_MODS_KEY(MOD_LGUI | MOD_LALT, KC_RGHT)
#define IDE_TOGGLE_PROJ ACTION_MODS_KEY(MOD_LGUI, KC_1)
#define IDE_FILE_STRUC ACTION_MODS_KEY(MOD_LGUI, KC_F12)
#define IDE_FIND_ACTION ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_A)
#define IDE_OPEN_RECENT ACTION_MODS_KEY(MOD_LGUI | MOD_RCTL, KC_E)
#define IDE_CLOSE ACTION_MODS_KEY(MOD_LGUI | MOD_RCTL, KC_W)

// Helpers for my symbol layer
#define KC_EXLM ACTION_MODS_KEY(MOD_LSFT, KC_1)
#define KC_AT   ACTION_MODS_KEY(MOD_LSFT, KC_2)
#define KC_HASH ACTION_MODS_KEY(MOD_LSFT, KC_3)
#define KC_DLR  ACTION_MODS_KEY(MOD_LSFT, KC_4)
#define KC_PERC ACTION_MODS_KEY(MOD_LSFT, KC_5)
#define KC_CIRC ACTION_MODS_KEY(MOD_LSFT, KC_6)
#define KC_AMPR ACTION_MODS_KEY(MOD_LSFT, KC_7)
#define KC_ASTR ACTION_MODS_KEY(MOD_LSFT, KC_8)
#define KC_LPRN ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define KC_RPRN ACTION_MODS_KEY(MOD_LSFT, KC_0)
#define KC_UNDS ACTION_MODS_KEY(MOD_LSFT, KC_MINUS)
#define KC_PLUS ACTION_MODS_KEY(MOD_LSFT, KC_EQL)
#define MY_COLN ACTION_MODS_KEY(MOD_LSFT, KC_SCLN)
#define KC_QUES ACTION_MODS_KEY(MOD_LSFT, KC_SLSH)
#define KC_TILD ACTION_MODS_KEY(MOD_LSFT, KC_GRV)
#define KC_PIPE ACTION_MODS_KEY(MOD_LSFT, KC_BSLS)
#define KC_LCBR ACTION_MODS_KEY(MOD_LSFT, KC_LBRC)
#define KC_RCBR ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)
#define KC_DQT  ACTION_MODS_KEY(MOD_LSFT, KC_QUOT)
#define KC_LABK ACTION_MODS_KEY(MOD_LSFT, KC_COMM)
#define KC_RABK ACTION_MODS_KEY(MOD_LSFT, KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPH] = {
      {KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,    KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
      {KC_A,    KC_S,    FN_NAV,    FN_IDE,  KC_G,    KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
      {KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,    FN_NUMS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
      {FN_CTES, FN_OPGV, KC_LGUI,   FN_FKEY, FN_SFBS, FN_SYMB, FN_SFSP, KC_MINS, KC_EQL,  KC_QUOT, KC_ENT}
    },
    [NUMS] = {
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_SLSH, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_SLSH},
      {KC_TRNS, KC_TRNS, KC_EQL,  KC_PLUS, KC_MINS, KC_TRNS, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR},
      {KC_TRNS, KC_TRNS, KC_DOT,  KC_COMM, KC_SCLN, KC_TRNS, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS},
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_DOT,  KC_EQL,  KC_PLUS}
    },
    [FKEY] = {
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7,   KC_F8,  KC_F9,  KC_F10},
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F11},
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12},
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FN_BOOT}
    },
    [SYMB] = {
      {KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_TRNS, KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN},
      {KC_GRV,    KC_TILD, KC_LPRN,  KC_RPRN, KC_SCLN, KC_TRNS, KC_COMM,  KC_DOT,   KC_QUOT, KC_TRNS, KC_PIPE},
      {KC_MINS,   KC_BSLS, KC_LCBR,  KC_RCBR, KC_SLSH, KC_TRNS, KC_LABK,  KC_RABK,   KC_DQT,  KC_TRNS, KC_QUES},
      {KC_TRNS,   KC_TRNS, KC_LBRC,  KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS}
    },
    [IDE] = {
      {KC_TRNS,          IDE_CLOSE, IDE_OPEN_RECENT, KC_TRNS,  KC_TRNS, KC_TRNS,        IDE_RENAME,    IDE_FIND_USAGES,    IDE_CHANGE_SIG, IDE_COMPILE,    IDE_FILE_STRUC},
      {IDE_FIND_ACTION,  KC_TRNS,   KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS,        IDE_NAV_B,     IDE_LINE_D,         IDE_LINE_U,     IDE_NAV_F,      IDE_TOGGLE_PROJ},
      {KC_TRNS,          KC_TRNS,   KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS,        IDE_LINE_L,    IDE_LINE_D,         IDE_LINE_U,     IDE_LINE_R,     KC_TRNS},
      {KC_TRNS,          KC_TRNS,   KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,       KC_TRNS,            KC_TRNS,        KC_TRNS,        KC_TRNS}
    },
    [NAV] = {
      {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS},
      {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,    KC_DOWN,    KC_UP,   KC_RIGHT,   KC_TRNS},
      {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS},
      {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS}
    }
};

const uint16_t PROGMEM fn_actions[] = {
  [BOOT] = ACTION_FUNCTION(BOOTLOADER),
  [NUMS] = ACTION_LAYER_TAP_KEY(NUMS, KC_LBRC),
  [FKEY] = ACTION_LAYER_TAP_KEY(FKEY, KC_TAB),
  [SYMB] = ACTION_LAYER_TAP_KEY(SYMB, KC_RBRC),
  [IDE] =  ACTION_LAYER_TAP_KEY(IDE, KC_F),
  [NAV] =  ACTION_LAYER_TAP_KEY(NAV, KC_D),
  [SFBS] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),
  [SFSP] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC),
  [CTES] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC),
  [OPGV] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_GRV)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}

//static void layer_state_set(uint32_t state) {
//    // ...
//    clear_keyboard_but_mods(); // To avoid stuck keys
//}

