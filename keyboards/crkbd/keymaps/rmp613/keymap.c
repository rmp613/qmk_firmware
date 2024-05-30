#include "quantum.h"
#include QMK_KEYBOARD_H
// #include "features/achordion.h"
// #include "features/custom_shift_keys.h"

// // Left-hand HRM row mods
// #define HRM_C LCTL_T(KC_C)
// #define HRM_I LALT_T(KC_I)
// #define HRM_E LGUI_T(KC_E)
// #define HRM_A LSFT_T(KC_A)

// // Right-hand HRM row mods
// #define HRM_H RSFT_T(KC_H)
// #define HRM_T RGUI_T(KC_T)
// #define HRM_S LALT_T(KC_S)
// #define HRM_N RCTL_T(KC_N)

enum custom_keycodes { // Make sure have the awesome keycode ready
    FIND = SAFE_RANGE,
    CUT,
    COPY,
    PASTE,
    UNDO,
    OS_CG // CTRL or GUI depending on OS
};
// todo: combos
enum combos {
    COMBO_BASE_ENTER,
    COMBO_BASE_BKSPC,
    COMBO_BASE_ESC,
    COMBO_SHIFTED_BSPC,
    COMBO_BASE_DEL,
    COMBO_BASE_TAB,
    COMBO_BASE_L_BRACKET,
    COMBO_BASE_R_BRACKET,
    COMBO_BASE_L_PAR,
    COMBO_BASE_R_PAR,
    COMBO_BASE_L_CURLY,
    COMBO_BASE_R_CURLY,
    COMBO_BASE_SEMICOLON,
    COMBO_BASE_COLON,
    COMBO_BASE_COMMA,
    COMBO_BASE_PERIOD,
    COMBO_BASE_EQUAL,
    COMBO_BASE_PLUS,
    COMBO_BASE_MINUS,
    COMBO_BASE_ASTERISK,
    COMBO_BASE_BACKSLASH,
    COMBO_BASE_TILDE,
    COMBO_BASE_AMPERSAND,
    COMBO_BASE_PIPE,
    COMBO_BASE_CARAT,
    COMBO_BASE_PERCENT,
    COMBO_BASE_DOLLAR,
    COMBO_BASE_HASH,
    COMBO_BASE_AT,
    COMBO_BASE_BANG,
    COMBO_BASE_QUOT,
    COMBO_BASE_DBL_QUOT,
    COMBO_BASE_QMARK,
    COMBO_BASE_LT,
    COMBO_BASE_GT,
    COMBO_CTRL,
    COMBO_BOOT_L,
    COMBO_BOOT_R,
    COMBO_GRAVE,

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

const uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued
// todo: add find,
const uint16_t PROGMEM base_enter_combo[]     = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM base_backspace_combo[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM shifted_bspc_combo[]   = {KC_RSFT, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM base_del_combo[]       = {KC_S, KC_N, COMBO_END};
// const uint16_t PROGMEM raise_del_combo[]          = {KC_6, KC_0, COMBO_END};
const uint16_t PROGMEM base_esc_combo[]           = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM base_tab_combo[]           = {KC_C, KC_I, COMBO_END};
const uint16_t PROGMEM base_l_bracket_combo[]     = {KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM base_r_bracket_combo[]     = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM base_l_parentheses_combo[] = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM base_r_parentheses_combo[] = {KC_D, KC_W, COMBO_END};
const uint16_t PROGMEM base_l_curly_combo[]       = {KC_X, KC_J, COMBO_END};
const uint16_t PROGMEM base_r_curly_combo[]       = {KC_M, KC_F, COMBO_END};
const uint16_t PROGMEM base_semicolon_combo[]     = {KC_T, KC_F, COMBO_END};
const uint16_t PROGMEM base_colon_combo[]         = {KC_X, KC_E, COMBO_END};
const uint16_t PROGMEM base_equal_combo[]         = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM base_plus_combo[]          = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM grave_combo[]              = {KC_G, KC_I, COMBO_END};
const uint16_t PROGMEM base_asterisk_combo[]      = {KC_G, KC_X, COMBO_END};
const uint16_t PROGMEM base_backslash_combo[]     = {KC_S, KC_P, COMBO_END};
const uint16_t PROGMEM base_tilde_combo[]         = {KC_B, KC_Y, COMBO_END};
const uint16_t PROGMEM base_ampersand_combo[]     = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM base_pipe_combo[]          = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM base_carat_combo[]         = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM base_percent_combo[]       = {KC_W, KC_N, COMBO_END};
const uint16_t PROGMEM base_dollar_combo[]        = {KC_H, KC_S, COMBO_END};
const uint16_t PROGMEM base_hash_combo[]          = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM base_at_combo[]            = {KC_C, KC_Y, COMBO_END};
const uint16_t PROGMEM base_bang_combo[]          = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM base_quot_combo[]          = {KC_E, KC_K, COMBO_END};
const uint16_t PROGMEM base_dbl_quot_combo[]      = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM base_qmark_combo[]         = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM base_lt_combo[]            = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM base_gt_combo[]            = {KC_R, KC_M, COMBO_END};
const uint16_t PROGMEM ctrl_combo[]               = {OS_CG, KC_LALT, COMBO_END};
const uint16_t PROGMEM boot_l[]                   = {KC_B, KC_Y, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM boot_r[]                   = {KC_L, KC_D, KC_W, KC_V, COMBO_END};

combo_t key_combos[] = {[COMBO_BASE_ENTER]     = COMBO(base_enter_combo, KC_ENTER),
                        [COMBO_BASE_BKSPC]     = COMBO(base_backspace_combo, KC_BACKSPACE),
                        [COMBO_SHIFTED_BSPC]   = COMBO(shifted_bspc_combo, KC_BACKSPACE),
                        [COMBO_BASE_DEL]       = COMBO(base_del_combo, KC_DEL),
                        [COMBO_BASE_L_BRACKET] = COMBO(base_l_bracket_combo, KC_LEFT_BRACKET),
                        [COMBO_BASE_R_BRACKET] = COMBO(base_r_bracket_combo, KC_RIGHT_BRACKET),
                        [COMBO_BASE_L_CURLY]   = COMBO(base_l_curly_combo, KC_LCBR),
                        [COMBO_BASE_R_CURLY]   = COMBO(base_r_curly_combo, KC_RCBR),
                        [COMBO_BASE_L_PAR]     = COMBO(base_l_parentheses_combo, KC_LPRN),
                        [COMBO_BASE_R_PAR]     = COMBO(base_r_parentheses_combo, KC_RPRN),
                        [COMBO_BASE_ESC]       = COMBO(base_esc_combo, KC_ESC),
                        [COMBO_BASE_TAB]       = COMBO(base_tab_combo, KC_TAB),
                        [COMBO_BASE_SEMICOLON] = COMBO(base_semicolon_combo, KC_SEMICOLON),
                        [COMBO_BASE_COLON]     = COMBO(base_colon_combo, KC_COLON),
                        [COMBO_BASE_EQUAL]     = COMBO(base_equal_combo, KC_EQUAL),
                        [COMBO_BASE_PLUS]      = COMBO(base_plus_combo, KC_PLUS),
                        [COMBO_GRAVE]          = COMBO(grave_combo, KC_GRAVE),
                        [COMBO_BASE_ASTERISK]  = COMBO(base_asterisk_combo, KC_ASTERISK),
                        [COMBO_BASE_BACKSLASH] = COMBO(base_backslash_combo, KC_BACKSLASH),
                        [COMBO_BASE_TILDE]     = COMBO(base_tilde_combo, KC_TILD),
                        [COMBO_BASE_AMPERSAND] = COMBO(base_ampersand_combo, KC_AMPERSAND),
                        [COMBO_BASE_PIPE]      = COMBO(base_pipe_combo, KC_PIPE),
                        [COMBO_BASE_CARAT]     = COMBO(base_carat_combo, KC_CIRC),
                        [COMBO_BASE_PERCENT]   = COMBO(base_percent_combo, KC_PERCENT),
                        [COMBO_BASE_DOLLAR]    = COMBO(base_dollar_combo, KC_DOLLAR),
                        [COMBO_BASE_HASH]      = COMBO(base_hash_combo, KC_HASH),
                        [COMBO_BASE_AT]        = COMBO(base_at_combo, KC_AT),
                        [COMBO_BASE_BANG]      = COMBO(base_bang_combo, KC_EXLM),
                        [COMBO_BASE_QUOT]      = COMBO(base_quot_combo, KC_QUOTE),
                        [COMBO_BASE_DBL_QUOT]  = COMBO(base_dbl_quot_combo, KC_DQUO),
                        [COMBO_BASE_QMARK]     = COMBO(base_qmark_combo, KC_QUES),
                        [COMBO_BASE_LT]        = COMBO(base_lt_combo, KC_LT),
                        [COMBO_BASE_GT]        = COMBO(base_gt_combo, KC_GT),
                        [COMBO_BOOT_L]         = COMBO(boot_l, QK_BOOT),
                        [COMBO_BOOT_R]         = COMBO(boot_r, QK_BOOT),
                        [COMBO_CTRL]           = COMBO(ctrl_combo, KC_LCTL)};

int get_ctrl_gui(void);
int get_ctrl_gui() {
    if (detected_host_os() == OS_MACOS) {
        return KC_LGUI;
    }
    return KC_LCTL;
};
int CTRL_GUI(int);
int CTRL_GUI(int key) {
    if (detected_host_os() == OS_MACOS) {
        return LGUI(key);
    }
    return LCTL(key);
};

void handle_ctrl_gui(keyrecord_t *record, uint16_t keycode) {
    if (record->event.pressed) {
        register_code(get_ctrl_gui());
        register_code(keycode);
    } else {
        unregister_code(keycode);
        unregister_code(get_ctrl_gui());
    }
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    // switch (combo->keycode) {
    //     case KC_LCTL:
    //         return 80;
    // }

    // or with combo index, i.e. its name from enum.
    return COMBO_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) { // This will do most of the grunt work with the keycodes.
        case OS_CG:
            if (record->event.pressed) {
                register_code(get_ctrl_gui());
            } else {
                unregister_code(get_ctrl_gui());
            }
            break;

        case FIND:
            handle_ctrl_gui(record, KC_F);
            break;
        case CUT:
            handle_ctrl_gui(record, KC_X);
            break;
        case COPY:
            handle_ctrl_gui(record, KC_C);
            break;
        case PASTE:
            handle_ctrl_gui(record, KC_V);
            break;
        case UNDO:
            handle_ctrl_gui(record, KC_Z);
            break;

    }
    return true;
}


// bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
//     // Exceptionally consider the following chords as holds, even though they
//     // are on the same hand in Dvorak.
//     // switch (tap_hold_keycode) {
//     //  case HRM_A:  // A + U.
//     //    if (other_keycode == HRM_U) { return true; }
//     //    break;

//     //  case HRM_S:  // S + H and S + G.
//     //     if (other_keycode == HRM_H || other_keycode == KC_G) { return true; }
//     //    break;
//     //  }

//     // Also allow same-hand holds when the other key is in the rows below the
//     // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
//     if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
//         return true;
//     }

//     // Otherwise, follow the opposite hands rule.
//     return achordion_opposite_hands(tap_hold_record, other_record);
// }

// uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
//   return 800;  // Otherwise use a timeout of 800 ms.
// }

// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//   if (!process_achordion(keycode, record)) { return false; }
//   if (!process_custom_shift_keys(keycode, record)) { return false; }

// use custom code to accomplish complex mod taps such as using
// shifted symbols
//   switch (keycode) {
//     case LCTL_T(KC_DQUO):
//       if (record->tap.count && record->event.pressed) {
//         tap_code16(KC_DQUO); // Send KC_DQUO on tap
//         return false;        // Return false to ignore further processing of keycode
//       }
//     break;
//   }
//   return true;
// }

// void matrix_scan_user(void) {
//   achordion_task();
// }

// this is for complex combo results such as macros based off combos
// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case EM_EMAIL:
//       if (pressed) {
//       //  SEND_STRING("john.doe@example.com");
//       }
//       break;
//     case BSPC_LSFT_CLEAR:
//       if (pressed) {
//      //   tap_code16(KC_END);
//        // tap_code16(S(KC_HRM));
//         //tap_code16(KC_BSPC);
//       }
//       break;
//   }
// }

// #deprecated for using a swapper key
// swap alt and gui depending on os to make alt tab
// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }
//     switch (detected_os) {
//         case OS_MACOS:
//         case OS_IOS:
//             tap_code16(QK_MAGIC_SWAP_ALT_GUI);
//             break;
//         case OS_WINDOWS:
//         case OS_LINUX:
//         case OS_UNSURE:
//             tap_code16(QK_MAGIC_UNSWAP_ALT_GUI);
//             break;
//     }

//     return true;
// }

// clang-format off
#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,    KC_B,    KC_Y,    KC_O,    KC_U,    KC_Z, XXXXXXX,    XXXXXXX,    KC_Q,    KC_L,    KC_D,    KC_W,    KC_V, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_C,    KC_I,    KC_E,    KC_A, KC_COMM, XXXXXXX,    XXXXXXX,  KC_DOT,    KC_H,    KC_T,    KC_S,    KC_N, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_G,    KC_X,    KC_J,    KC_K,KC_MINUS,                      KC_SLSH,    KC_R,    KC_M,    KC_F,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          TL_LOWR,  KC_SPC,   OS_CG,    KC_LALT, KC_RSFT, KC_LCTL
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3_ex2(
   //,--------------------------------------------------------------.  ,----------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,    FIND, XXXXXXX,    XXXXXXX,  KC_DOT,    KC_4,    KC_5,    KC_6,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    UNDO,     CUT,    COPY,   PASTE, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
#endif
// clang-format on
