#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT, KC_LGUI, KC_LALT, KC_LCTL, MO(1), KC_SPC, KC_ENT, MO(2), KC_RCTL, KC_RALT, KC_RGUI),
	[1] = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, MO(3), _______, _______, _______),
	[2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, C(KC_LEFT), KC_UP, C(KC_RGHT), C(KC_BSPC), KC_BSPC, _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC, _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END, XXXXXXX, _______, _______, _______, _______, MO(3), _______, _______, _______, _______, _______, _______),
	[3] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
  rgb_matrix_sethsv(191, 255, 255);
}

// Sets all letter keys to red when caps lock is on
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

  if (get_highest_layer(layer_state) > 0) {
    uint8_t layer = get_highest_layer(layer_state);
    // TODO: Set the layer keys depending on layer & dim all non-configured keys
    // TODO: Set the number keys to a different color depending on the layer number
    uint8_t KEY_1_LED = 10;
    uint8_t KEY_2_LED = 9;
    uint8_t KEY_3_LED = 8;
    uint8_t KEY_RAISE_LED = 66;
    uint8_t KEY_LOWER_LED = 31;
    if (layer == 1) {
      rgb_matrix_set_color(KEY_1_LED, RGB_BLUE);
      rgb_matrix_set_color(KEY_LOWER_LED, RGB_BLUE);
    } else if (layer == 2) {
      rgb_matrix_set_color(KEY_2_LED, RGB_BLUE);
      rgb_matrix_set_color(KEY_RAISE_LED, RGB_BLUE);
    } else if (layer == 3) {
      rgb_matrix_set_color(KEY_3_LED, RGB_BLUE);
      rgb_matrix_set_color(KEY_RAISE_LED, RGB_BLUE);
      rgb_matrix_set_color(KEY_LOWER_LED, RGB_BLUE);
    }
    // Turn off non-configured keys... need to get a matrix for LED index to keycode
    // for (uint8_t i = led_min; i < led_max; i++) {
    //     if (g_led_config.flags[i] & LED_FLAG_NONE) {
    //         rgb_matrix_set_color(i, 0, 0, 0);
    //     }
    // }
  }
    // ---OVERRIDE INDICATORS---

    // CAPS WORD indicator override
    uint8_t LEFT_SHIFT_LED = 29;
    if (is_caps_word_on()) {
      rgb_matrix_set_color(LEFT_SHIFT_LED, RGB_GREEN);
    }

  // CAPS LOCK Override: If CAPS LOCK is on, all letter keys will be red if on Layer 0
    if (host_keyboard_led_state().caps_lock) {
      uint8_t layer = get_highest_layer(layer_state);
      if (layer == 0){
        for (uint8_t i = led_min; i < led_max; i++) {
        // Check if key is a letter key, if so: set it to red
          if (
              (i >= 12 && i <= 16) || (i >= 18 && i <= 22)
          || (i >= 24 && i <= 28) || (i >= 47 && i <= 51)
          || (i >= 53 && i <= 56) || (i >= 59 && i <= 60)
          ) {
            rgb_matrix_set_color(i, RGB_RED);
          }
        }
      }else if (layer == 2) {
        // If the layer is 2, get the CAPS_LOCK key to RED as well to indicate that CAPS_LOCK is on
        rgb_matrix_set_color(18, RGB_RED);
      }
  }
  return false;
}

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (!encoder_update_user(index, clockwise)) {
//         return false;
//     }
//     // 0 is left-half encoder,
//     // 1 is right-half encoder
//     if (index == 0) {
//         // Volume control
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
//     } else if (index == 1) {
//         // Page up/Page down
//         if (clockwise) {
//             tap_code(KC_MS_WH_DOWN);
//         } else {
//             tap_code(KC_MS_WH_UP);
//         }
//     }
//     return false;
// }
// #endif

// void caps_word_set_user(bool active) {
//     if (active) {
//         writePinLow(24);
//     } else {
//         writePinHigh(24);
//     }
// }
