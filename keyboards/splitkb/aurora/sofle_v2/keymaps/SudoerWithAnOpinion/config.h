/* Copyright 2023 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define RGB_MATRIX_SLEEP
// #define ENCODER_ENABLE
// #define RGB_MATRIX_KEYPRESSES
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_HUE_BREATHING // Single hue brightness cycling animation

// #define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL // Sets the default LED flags, if none has been set
#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set

// Reset Vars
#undef RGB_MATRIX_DEFAULT_MODE
#undef RGB_MATRIX_DEFAULT_HUE
#undef RGB_MATRIX_DEFAULT_SAT
#undef RGB_MATRIX_DEFAULT_VAL
#undef RGB_MATRIX_DEFAULT_SPD

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_HUE_BREATHING
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_HUE_BREATHING
#define RGB_MATRIX_DEFAULT_HUE 175
#define RGB_MATRIX_DEFAULT_SAT 100
#define RGB_MATRIX_DEFAULT_VAL 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define RGB_MATRIX_DEFAULT_SPD 127
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// https://www.reddit.com/r/olkb/comments/sbvefp/has_anyone_gotten_qmk_rgb_matrix_effects_working/
