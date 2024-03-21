#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    BASE_LAYER = 0,
    NUM_LAYER,
    NAV_LAYER,
    FUN_LAYER,
    PT_LAYER,
    MULTIMEDIA_LAYER,
};
#define _KC_MCON _KC_SHOW_ALL_WINDOWS
#define _KC_LPAD _KC_SHOW_ALL_APPS

enum my_keycodes { _KC_SHOW_ALL_WINDOWS = SAFE_RANGE, _KC_SHOW_ALL_APPS };

enum my_consumer_usages { _AC_SHOW_ALL_WINDOWS = 0x29F, _AC_SHOW_ALL_APPS = 0x2A0 };

// Left-hand home row mods
#ifdef WIN_HOME_ROW
#    define HOME_A LGUI_T(KC_A)
#    define HOME_D LCTL_T(KC_D)
#else
#    define HOME_A LCTL_T(KC_A)
#    define HOME_D LGUI_T(KC_D)
#endif
#define HOME_S LALT_T(KC_S)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#ifdef WIN_HOME_ROW
#    define HOME_K RCTL_T(KC_K)
#    define HOME_SCLN RGUI_T(KC_SCLN)
#else
#    define HOME_K RGUI_T(KC_K)
#    define HOME_SCLN RCTL_T(KC_SCLN)
#endif
#define HOME_J RSFT_T(KC_J)
#define HOME_L LALT_T(KC_L)

// Russian characters
#define RUS_M LT(BASE_LAYER, KC_M)
#define RUS_T LT(BASE_LAYER, KC_T)

// Layers
#define PT_Z LT(PT_LAYER, KC_Z)
#define PT_SLSH LT(PT_LAYER, KC_SLSH)

#define NUM_ENT LT(NUM_LAYER, KC_ENT)
#define NAV_BSPC LT(NAV_LAYER, KC_BSPC)
#define FUN_SPC LT(FUN_LAYER, KC_SPC)
#define MULT_ESC LT(MULTIMEDIA_LAYER, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      RUS_T,       KC_Y,       KC_U,       KC_I,       KC_O,      KC_P,      KC_LBRC,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       KC_ESC,    HOME_A,    HOME_S,    HOME_D,    HOME_F,    KC_G,       KC_H,       HOME_J,     HOME_K,     HOME_L,    HOME_SCLN, KC_QUOT,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   PT_Z,      KC_X,      KC_C,      KC_V,      KC_B,       KC_N,       RUS_M,       KC_COMM,    KC_DOT,    PT_SLSH,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        NAV_BSPC,  FUN_SPC,   KC_TAB,     MULT_ESC,     NUM_ENT
  //                                  ╰───────────────────────────────╯ ╰──────────────────────╯
  ),

  [NUM_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   KC_LBRC,   KC_7,      KC_8,      KC_9,      KC_RBRC,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_SCLN,   KC_4,      KC_5,      KC_6,      KC_EQL,     XXXXXXX,    KC_RSFT,    KC_RGUI,    KC_RALT,   KC_RCTL,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_GRV,    KC_1,      KC_2,      KC_3,      KC_BSLS,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        KC_MINS,   KC_0,      XXXXXXX,    XXXXXXX,   _______
  //                                  ╰───────────────────────────────╯ ╰────────────────────╯
  ),

  [NAV_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,  XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        XXXXXXX,   XXXXXXX,   _______,    XXXXXXX,   XXXXXXX
  //                                  ╰───────────────────────────────╯ ╰────────────────────╯
  ),

  [FUN_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   KC_F7,       KC_F8,      KC_F9,     KC_F12,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,    XXXXXXX,   KC_F4,       KC_F5,      KC_F6,     KC_F11,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   KC_F1,       KC_F2,      KC_F3,     KC_F10,    XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        XXXXXXX,   _______,   XXXXXXX,    XXXXXXX,   XXXXXXX
  //                                  ╰───────────────────────────────╯ ╰────────────────────╯
  ),
 
  [PT_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       EE_CLR,    XXXXXXX,   XXXXXXX,   XXXXXXX,   DPI_RMOD,  S_D_RMOD,   S_D_MOD,    DPI_MOD,    XXXXXXX,    XXXXXXX,   XXXXXXX,   EE_CLR,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   XXXXXXX,    XXXXXXX,    KC_RSFT,    KC_RGUI,    KC_RALT,   KC_RCTL,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   _______,   XXXXXXX,   SNIPING,   DRGSCRL,   XXXXXXX,    XXXXXXX,    DRGSCRL,    SNIPING,    XXXXXXX,   _______,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        KC_BTN1,   KC_BTN2,   KC_BTN3,    KC_BTN3,   KC_BTN1
  //                                  ╰───────────────────────────────╯ ╰────────────────────╯
  ),

  [MULTIMEDIA_LAYER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       XXXXXXX,   XXXXXXX,   XXXXXXX,   _KC_LPAD,  _KC_MCON,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   XXXXXXX,   KC_MUTE,   KC_VOLD,   KC_VOLU,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ├────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                                        XXXXXXX,   XXXXXXX,   XXXXXXX,    _______,   XXXXXXX
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

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RUS_M:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_RBRC);
                return false;
            }
            return true;
        case RUS_T:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_BSLS);
                return false;
            }
            return true;
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