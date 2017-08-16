/*
This layout was created by Jeremy Cowgar (@jcowgar) and tweaked by Adam Ford.
*/

#include "keymap_common.h"


// Reduce the time to decision of a tap or hold
#define TAPPING_TERM 250

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define BOOT  0 // Bootloader (not to be confused with default layer)
#define ALPH  0 // Alphabet Layer
#define NUMS  1 // Number Layer
#define FKEY  2 // Function Key Layer
#define CURS  3 // Cursor Layer
#define SYMB  4 // Symbol Layer
#define OPBS  5 // Option or Backspace
#define CMET  6 // Command or Enter
#define SFSP  7 // Right Shift or Space
#define SFET  8 // Left Shift or Enter
#define CTTB  9 // Control or Tab
#define CTES 10 // Control or Escape
#define SFBS 11 // Left shift or Backspace
#define CTET 12 // Control or Enter

// Mouse Values
#define MS_U 13
#define MS_D 14
#define MS_L 15
#define MS_R 16
#define WH_U 17
#define WH_D 18
#define WH_L 19
#define WH_R 20
#define BTN1 21
#define BTN2 22
#define BTN3 23
#define BTN4 24
#define BTN5 25
#define ACL0 26
#define ACL1 27
#define ACL2 28
#define MOUSE 29

#define FN_BOOT (KC_FN0 + BOOT)
#define FN_NUMS (KC_FN0 + NUMS)
#define FN_FKEY (KC_FN0 + FKEY)
#define FN_CURS (KC_FN0 + CURS)
#define FN_SYMB (KC_FN0 + SYMB)
#define FN_OPBS (KC_FN0 + OPBS)
#define FN_CMET (KC_FN0 + CMET)
#define FN_SFSP (KC_FN0 + SFSP)
#define FN_SFET (KC_FN0 + SFET)
#define FN_CTTB (KC_FN0 + CTTB)
#define FN_CTES (KC_FN0 + CTES)
#define FN_SFBS (KC_FN0 + SFBS)
#define FN_CTET (KC_FN0 + CTET)

#define FN_MOUSE (KC_FN0 + MOUSE)
#define FN_MS_U (KC_FN0 + MS_U)
#define FN_MS_D (KC_FN0 + MS_D)
#define FN_MS_L (KC_FN0 + MS_L)
#define FN_MS_R (KC_FN0 + MS_R)
#define FN_WH_U (KC_FN0 + WH_U)
#define FN_WH_D (KC_FN0 + WH_D)
#define FN_WH_L (KC_FN0 + WH_L)
#define FN_WH_R (KC_FN0 + WH_R)
#define FN_BTN1 (KC_FN0 + BTN1)
#define FN_BTN2 (KC_FN0 + BTN2)
#define FN_BTN3 (KC_FN0 + BTN3)
#define FN_BTN4 (KC_FN0 + BTN4)
#define FN_BTN5 (KC_FN0 + BTN5)
#define FN_ACL0 (KC_FN0 + ACL0)
#define FN_ACL1 (KC_FN0 + ACL1)
#define FN_ACL2 (KC_FN0 + ACL2)

// Some handy macros to keep the keymaps clean and easier to maintain
#define KM_SAVE ACTION_MODS_KEY(MOD_LGUI, KC_S)
#define KM_CLSE ACTION_MODS_KEY(MOD_LGUI, KC_W)
#define KM_OPEN ACTION_MODS_KEY(MOD_LGUI, KC_O)
#define KM_COPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define KM_CUT  ACTION_MODS_KEY(MOD_LGUI, KC_X)
#define KM_PAST ACTION_MODS_KEY(MOD_LGUI, KC_V)
#define KM_UNDO ACTION_MODS_KEY(MOD_LGUI, KC_Z)
#define KM_REDO ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_Z)

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
      {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
      {KC_A,    FN_NUMS, FN_FKEY, KC_F,    KC_G,    KC_TRNS, KC_H,    KC_J,    FN_CURS, FN_SYMB, FN_MOUSE},
      {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    FN_OPBS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
      {FN_CTES, KC_LBRC, KC_RBRC, FN_CTTB, FN_SFBS, FN_CMET, FN_SFSP, FN_CTET, KC_MINS, KC_QUOT, FN_CTES}
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
      {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
    },
    [CURS] = {
      {KC_TRNS, KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP, KC_TRNS, KC_TRNS, KM_SAVE, KC_TRNS, KM_OPEN, KC_TRNS},
      {KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, KM_UNDO, KC_LALT, KC_TRNS, KC_LGUI, KC_TRNS},
      {KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPLY, KM_COPY, KM_REDO, KM_CLSE, KC_TRNS, KC_TRNS, KC_TRNS},
      {KC_TRNS, KC_TRNS, FN_BOOT, KC_LSHIFT, KC_TAB,  KM_CUT,  KM_PAST, KC_RSHIFT, KC_TRNS, KC_TRNS, KC_TRNS}
    },
    [SYMB] = {
      {KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_TRNS, KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN},
      {KC_GRV,    KC_TILD, KC_LPRN,  KC_RPRN, KC_SCLN, KC_TRNS, KC_COMM,  KC_DOT,   KC_QUOT, KC_TRNS, KC_PIPE},
      {KC_MINS,   KC_BSLS, KC_LCBR,  KC_RCBR, KC_SLSH, KC_TRNS, KC_LABK,  KC_RABK,   KC_DQT,  KC_TRNS, KC_QUES},
      {KC_TRNS,   KC_TRNS, KC_LBRC,  KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS}
    },
    [MOUSE] = {
      {KC_TRNS,   KC_TRNS,   FN_MS_U,  KC_TRNS,  KC_TRNS, KC_TRNS, FN_WH_U,  FN_WH_L,  FN_WH_R, KC_TRNS, KC_TRNS},
      {KC_TRNS,    FN_MS_L, FN_MS_D,  FN_MS_R, KC_TRNS, KC_TRNS, FN_WH_D,  FN_ACL0,   FN_ACL1, FN_ACL2, KC_TRNS},
      {KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, FN_BTN1,  FN_BTN2,   FN_BTN3,  FN_BTN4, FN_BTN5},
      {KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS}
    }

};

const uint16_t PROGMEM fn_actions[] = {
  [BOOT] = ACTION_FUNCTION(BOOTLOADER),
  [NUMS] = ACTION_LAYER_TAP_KEY(NUMS, KC_S),
  [FKEY] = ACTION_LAYER_TAP_KEY(FKEY, KC_D),
  [CURS] = ACTION_LAYER_TAP_KEY(CURS, KC_K),
  [SYMB] = ACTION_LAYER_TAP_KEY(SYMB, KC_L),
  [OPBS] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),
  [CMET] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ENT),
  [SFSP] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC),
  [SFET] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT),
  [CTTB] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB),
  [CTES] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC),
  [CTET] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),
  [SFBS] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),
  [MOUSE] = ACTION_LAYER_TAP_KEY(MOUSE, KC_SCLN),
  [MS_U] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
  [MS_D] = ACTION_MOUSEKEY(KC_MS_D),
  [MS_L] = ACTION_MOUSEKEY(KC_MS_L),
  [MS_R] = ACTION_MOUSEKEY(KC_MS_R),
  [WH_U] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [WH_D] = ACTION_MOUSEKEY(KC_WH_D),
  [WH_L] = ACTION_MOUSEKEY(KC_WH_L),
  [WH_R] = ACTION_MOUSEKEY(KC_WH_R),
  [BTN1] = ACTION_MOUSEKEY(KC_BTN1), // clicks
  [BTN2] = ACTION_MOUSEKEY(KC_BTN2),
  [BTN3] = ACTION_MOUSEKEY(KC_BTN3),
  [BTN4] = ACTION_MOUSEKEY(KC_BTN4),
  [BTN5] = ACTION_MOUSEKEY(KC_BTN5),
  [ACL0] = ACTION_MOUSEKEY(KC_ACL0), // acceleration settings
  [ACL1] = ACTION_MOUSEKEY(KC_ACL1),
  [ACL2] = ACTION_MOUSEKEY(KC_ACL2)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
