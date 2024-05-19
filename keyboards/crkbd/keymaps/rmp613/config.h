#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 7

#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS_PER_SIDE (MATRIX_COLS / 2)

#define VIAL_KEYBOARD_UID {0x89, 0x36, 0x2A, 0xC7, 0xFA, 0xD8, 0x89, 0x45}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
// #define PERMISSIVE_HOLD
#define TAPPING_TERM 175

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 100
#define TAP_CODE_DELAY 10
// Prevent short hold periods being interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD
// Time (in ms) for combo processing
#define COMBO_TERM 20
// Don't allow macro calls in macros
#define DYNAMIC_MACRO_NO_NESTING

// Enable fast tapping (100ms) when typing fast.
#define ACHORDION_STREAK
#define LEADER_TIMEOUT 350
#define LEADER_PER_KEY_TIMING
#define LEADER_KEY_STRICT_KEY_PROCESSING

