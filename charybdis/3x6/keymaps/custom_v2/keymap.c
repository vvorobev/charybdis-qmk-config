#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    BASE_LAYER = 0,
    NUM_LAYER,
    NAV_LAYER,
    SYM_LAYER,
    PT_LAYER,
};
#define _KC_MCON _KC_SHOW_ALL_WINDOWS
#define _KC_LPAD _KC_SHOW_ALL_APPS

enum my_keycodes { _KC_SHOW_ALL_WINDOWS = SAFE_RANGE, _KC_SHOW_ALL_APPS };

enum my_consumer_usages { _AC_SHOW_ALL_WINDOWS = 0x29F, _AC_SHOW_ALL_APPS = 0x2A0 };

// Left-hand
#ifdef WIN_MODE
#    define RUS_YO KC_GRV
#    define HOME_A LGUI_T(KC_A)
#    define HOME_D LCTL_T(KC_D)
#    define HOME_F11 LGUI_T(KC_F11)
#    define HOME_F5 LCTL_T(KC_F5)
#    define HOME_L1 KC_LGUI 
#    define HOME_L3 KC_LCTL 
#else
#    define RUS_YO KC_BSLS
#    define HOME_A LCTL_T(KC_A)
#    define HOME_D LGUI_T(KC_D)
#    define HOME_F11 LCTL_T(KC_F11)
#    define HOME_F5 LGUI_T(KC_F5)
#    define HOME_L1 KC_LCTL 
#    define HOME_L3 KC_LGUI 
#endif
#define HOME_S LALT_T(KC_S)
#define HOME_F LSFT_T(KC_F)
#define HOME_F4 LALT_T(KC_F4)
#define HOME_F6 LSFT_T(KC_F6)

// Right-hand
#ifdef WIN_MODE
#    define HOME_K RCTL_T(KC_K)
#    define HOME_SCLN RGUI_T(KC_SCLN)
#    define HOME_R4 KC_RGUI 
#    define HOME_R2 KC_RCTL 
#else
#    define HOME_K RGUI_T(KC_K)
#    define HOME_SCLN RCTL_T(KC_SCLN)
#    define HOME_R4 KC_RCTL 
#    define HOME_R2 KC_RGUI 
#endif
#define HOME_J RSFT_T(KC_J)
#define HOME_L RALT_T(KC_L)

// Pointer
#define PT_Z LT(PT_LAYER, KC_Z)
#define PT_SLSH LT(PT_LAYER, KC_SLSH)

// Layers left
#define NAV_BSPC LT(NAV_LAYER, KC_BSPC)
#define SYM_TAB LT(SYM_LAYER, KC_TAB)

// Layers right
#define NUM_ENT LT(NUM_LAYER, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       RUS_YO,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,      KC_P,      KC_LBRC,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   HOME_A,    HOME_S,    HOME_D,    HOME_F,    KC_G,       KC_H,       HOME_J,     HOME_K,     HOME_L,    HOME_SCLN, KC_QUOT,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   PT_Z,      KC_X,      KC_C,      KC_V,      KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,    PT_SLSH,   KC_RBRC,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        NAV_BSPC,  KC_SPC,    SYM_TAB,    KC_ESC,     NUM_ENT
  //                                  ╰───────────────────────────────╯ ╰─────────────────────╯
  ),

  [NUM_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   KC_ASTR,   KC_7,      KC_8,      KC_9,      KC_PLUS,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_COLN,   KC_4,      KC_5,      KC_6,      KC_MINS,    XXXXXXX,    KC_RSFT,    HOME_R2,    KC_RALT,   HOME_R4,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_BSLS,   KC_1,      KC_2,      KC_3,      KC_EQL,     XXXXXXX,    XXXXXXX,    KC_LT,      KC_GT,     XXXXXXX,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        KC_BSPC,   KC_0,      XXXXXXX,    KC_ESC,     _______    
  //                                  ╰───────────────────────────────╯ ╰─────────────────────╯
  ),

  [NAV_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   KC_F12,    KC_F7,     KC_F8,     KC_F9,     KC_VOLU,    XXXXXXX,    _KC_LPAD,   _KC_MCON,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   HOME_F11,  HOME_F4,   HOME_F5,   HOME_F6,   KC_VOLD,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,  XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_F10,    KC_F1,     KC_F2,     KC_F3,     KC_MUTE,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        _______,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX    
  //                                  ╰───────────────────────────────╯ ╰─────────────────────╯
  ),

  [SYM_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   KC_ASTR,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PIPE,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_AT,     KC_EXLM,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_COLN,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_GRV,     KC_MINS,    KC_LPRN,    KC_RPRN,    KC_DLR,    KC_HASH,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_BSLS,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_TILD,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_CIRC,   KC_PERC,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        XXXXXXX,   XXXXXXX,   _______,    KC_AMPR,    XXXXXXX
  //                                  ╰───────────────────────────────╯ ╰─────────────────────╯
  ),
 
  [PT_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       EE_CLR,    XXXXXXX,   XXXXXXX,   XXXXXXX,   DPI_RMOD,  S_D_RMOD,   S_D_MOD,    DPI_MOD,    XXXXXXX,    XXXXXXX,   XXXXXXX,   EE_CLR,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   HOME_L1,   KC_LALT,   HOME_L3,   KC_LSFT,   XXXXXXX,    XXXXXXX,    KC_RSFT,    HOME_R2,    KC_RALT,   HOME_R4,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   _______,   XXXXXXX,   SNIPING,   DRGSCRL,   XXXXXXX,    XXXXXXX,    DRGSCRL,    SNIPING,    XXXXXXX,   _______,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        KC_BTN1,   KC_BTN2,   KC_BTN3,    KC_BTN3,   KC_BTN1
  //                                  ╰───────────────────────────────╯ ╰────────────────────╯
  ),
};

//   [LAYER] = LAYOUT(
//   // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
//        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
//   // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
//        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
//   // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
//        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
//   // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
//                                         XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX
//   //                                  ╰───────────────────────────────╯ ╰────────────────────╯
//   ),


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _KC_SHOW_ALL_WINDOWS:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_WINDOWS);
            } else {
                host_consumer_send(0);
            }
            return false;

        case _KC_SHOW_ALL_APPS:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_APPS);
            } else {
                host_consumer_send(0);
            }
            return false;
    }
    return true;
}