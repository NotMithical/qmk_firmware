/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

#include QMK_KEYBOARD_H
#include "features/socd_cleaner.h"
#include "features/custom_shift_keys.h"

socd_cleaner_t socd_v = {{KC_W, KC_S}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

const custom_shift_key_t custom_shift_keys[] = {
	{KC_F13, KC_F15},
	{KC_F14, KC_F16},
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

int FL_KEYS[] = {0, 7, 8, 9, 10, 11, 12, 16, 17, 59};
int side1[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
int side2[] = {110, 111, 112, 113, 114, 115, 116, 117, 118, 119};

enum custom_layers {
    _BL,
	_LGAME,
    _LCHL,
    _FL,
};

// Tap dance enums
enum {
    QUICK_F4,
    DOUBLESHIFT,
	DOUBLECTL,
	DOUBLEALT,
    CAPSWORD,
};

// Declaration of the tapdance reference below the layouts
//td_state_t cur_dance(tap_dance_state_t *state);

//Key combos
const uint16_t PROGMEM doubleshift[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM doublectl[] = {KC_LCTL, KC_RCTL, COMBO_END};
const uint16_t PROGMEM doublealt[] = {KC_LALT, KC_RALT, COMBO_END};
const uint16_t PROGMEM lch[] = {KC_L, KC_C, KC_H, COMBO_END};
combo_t key_combos[] = {
    COMBO(doubleshift, TD(DOUBLESHIFT)),
    COMBO(doublectl, TD(DOUBLECTL)),
    COMBO(doublealt, TD(DOUBLEALT)),
    COMBO(lch, TG(_LCHL)),
};

//Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Keymap _BL: Base Layer (Default Layer)
[_BL] = LAYOUT(
  KC_ESC,        KC_F1,    KC_F2,    KC_F3,    TD(QUICK_F4),    KC_F5,    KC_F6,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_F13,    KC_F14,    KC_PSCR,   KC_DEL,   KC_HOME,   KC_PGDN,   KC_PGUP,
  KC_GRV,        KC_1,     KC_2,     KC_3,     KC_4,            KC_5,     KC_6,     KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,   KC_EQL,    KC_BSPC,   KC_NUM,   KC_PSLS,   KC_PAST,   KC_PMNS,
  KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,            KC_T,     KC_Y,     KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_P7,    KC_P8,     KC_P9,     KC_PPLS,
  TD(CAPSWORD),  KC_A,     KC_S,     KC_D,     KC_F,            KC_G,     KC_H,     KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,              KC_ENT,    KC_P4,    KC_P5,     KC_P6,
  KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,            KC_B,     KC_N,     KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,              KC_UP,     KC_P1,    KC_P2,     KC_P3,     KC_PENT,
  KC_LCTL,       KC_LGUI,  KC_LALT,                             KC_SPC,                                     KC_RALT,    MO(_FL),    KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT,  KC_P0,     KC_PDOT),
  
  // For enabling SOCD
[_LGAME] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,
  _______,  _______,   _______,                      _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______),
  
    // Keymap _LCHL: Lighting Control Layer
[_LCHL] = LAYOUT(
  _______,  RGB_VAD,  _______,  _______,  RGB_VAI,  RGB_SAD,  _______,  _______,  RGB_SAI,  RGB_HUD,  _______,  _______,  RGB_HUI,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,
  _______,  _______,   _______,                      _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______),

  // Keymap _FL: Function Layer
[_FL] = LAYOUT(
  QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  TG(_LGAME),  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,
  _______,  _______,   _______,                      _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______)
};

// Tapdance states summary:
// state->count is how many times it has been pressed within the dance
// state->pressed is whether the key is held down currently
// state->interrupted occurs when another key has been pressed within the tapping term

// quick f4
void quick_f4_each(tap_dance_state_t *state, void *user_data) {
	register_code(KC_F4);
	
	if (state->count == 2) {
		unregister_code(KC_F4);
		register_code(KC_LALT);
		tap_code(KC_F4);
		unregister_code(KC_LALT);
		reset_tap_dance(state);
	}
}

void quick_f4_each_release(tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		unregister_code(KC_F4);
	}
}

// doubleshift
void doubleshift_each(tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: register_code(KC_LSFT); tap_code(KC_9); tap_code(KC_0); unregister_code(KC_LSFT); tap_code(KC_LEFT); break;
		case 2: tap_code(KC_BSPC); tap_code(KC_DEL); register_code(KC_LSFT); tap_code(KC_LEFT_BRACKET); tap_code(KC_RIGHT_BRACKET); unregister_code(KC_LSFT); tap_code(KC_LEFT); break;
		//case 3: tap_code(KC_BSPC); tap_code(KC_DEL); tap_code(KC_LEFT_BRACKET); tap_code(KC_RIGHT_BRACKET); tap_code(KC_LEFT); break;
		default: break;
	}
}

// doublectl
void doublectl_each(tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: tap_code(KC_LBRC); tap_code(KC_RBRC); tap_code(KC_LEFT); break;
		case 2: tap_code(KC_BSPC); tap_code(KC_DEL); register_code(KC_LSFT); tap_code(KC_COMM); tap_code(KC_DOT); unregister_code(KC_LSFT); tap_code(KC_LEFT); break;
		default: break;
	}
}

// doublealt
void doublealt_each(tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: register_code(KC_LSFT); tap_code(KC_8); tap_code(KC_8); unregister_code(KC_LSFT); tap_code(KC_LEFT); break;
		case 2: tap_code(KC_BSPC); tap_code(KC_DEL); register_code(KC_LSFT); tap_code(KC_QUOT); tap_code(KC_QUOT); unregister_code(KC_LSFT); tap_code(KC_LEFT); break;
		default: break;
	}
}

// capsword
void capsword_each(tap_dance_state_t *state, void *user_data) {
	register_code(KC_CAPS);
	
	if (state->count == 2) {
		unregister_code(KC_CAPS);
		caps_word_on();
		reset_tap_dance(state);
	}
}

void capsword_each_release(tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		unregister_code(KC_CAPS);
	}
}

// Tap dances
tap_dance_action_t tap_dance_actions[] = {
    [QUICK_F4] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(quick_f4_each, quick_f4_each_release, NULL, NULL),
    [DOUBLESHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(doubleshift_each, NULL, NULL),
    [DOUBLECTL] = ACTION_TAP_DANCE_FN_ADVANCED(doublectl_each, NULL, NULL),
    [DOUBLEALT] = ACTION_TAP_DANCE_FN_ADVANCED(doublealt_each, NULL, NULL),
	[CAPSWORD] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(capsword_each, capsword_each_release, NULL, NULL),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (!process_socd_cleaner(keycode, record, &socd_v)) { return false; }
	if (!process_socd_cleaner(keycode, record, &socd_h)) { return false; }
	
	if (!process_custom_shift_keys(keycode, record)) { return false; }
	return true;
}

// Toggle things depending on active layer
layer_state_t layer_state_set_user(layer_state_t state) {
	socd_cleaner_enabled = IS_LAYER_ON_STATE(state, _LGAME);
	
	if (IS_LAYER_ON_STATE(state, _LGAME)) {
		autocorrect_disable();
		combo_disable();
	}
	else {
		autocorrect_enable();
		combo_enable();
	}
	return state;
}

// RGB LED layout for GMMK 2 96%
// By Skitzo2000
// led number, function of the key

//  0, Esc     1, F1      2, F2    3, F3       4, F4      5, F5      6, F6    7, F7       8, F8      9, F9      10, F10  11, F11     12, F12    13, Prnscr      14, Del     15, Ins     16, PgUp      17, PgDo
//  18, `      19, 1      20, 2    21, 3       22, 4      23, 5      24, 6    25, 7       26, 8      27, 9      28, 0    29, -       30, =      31, Bkspc       32, NmLk    33, /       34, *         35, -
//  36, Tab    37, Q      38, W    39, E       40, R      41, T      42, Y    43, U       44, I      45, O      46, P    47, [       48, ]      49, "\""        50, 7       51, 8       52, 9         53, +
//  54, CpsLk  55, A      56, S    57, D       58, F      59, G      60, H    61, J       62, K      63, L      64, ;    65, '       66, Enter                  67, 4       68, 5       69, 6
//  70, ShftL  71, Z      72, X    73, C       74, V      75, B      76, N    77, M       78, ,      79, .      80, /    81, ShftR              82, Up          83, 1       84, 2       85, 3         86, EntrR
//  87, CtlL   88, WinL   89, AltL                                   90, Space                                  91, AltR 92, FN      93, CtrlR  94, Left        95, Down    96, Right   97, 0         98, Num .

// Left Side
//  101, LED 1
//  102, LED 2
//  103, LED 3
//  104, LED 4
//  105, LED 5
//  106, LED 6
//  107, LED 7
//  108, LED 8
//  109, LED 9

//Right Side
//  110, LED 10
//  111, LED 11
//  112, LED 12
//  113, LED 13
//  114, LED 14
//  115, LED 15
//  116, LED 16
//  117, LED 17
//  118, LED 18
//  119, LED 19
//  120, LED 20

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(54, 255, 0, 0); //capslock red
	}
	
    if (host_keyboard_led_state().num_lock == false) {
		RGB_MATRIX_INDICATOR_SET_COLOR(32, 255, 0, 0); //numlock red
	}
	
	if (layer_state_is(_LGAME)) {
											 rgb_matrix_set_color(38, 0, 255, 0);
		rgb_matrix_set_color(55, 0, 255, 0); rgb_matrix_set_color(56, 0, 255, 0); rgb_matrix_set_color(57, 0, 255, 0);
	}
	
	if (layer_state_is(_LCHL)) {
		rgb_matrix_set_color(1, 0, 32, 0);      rgb_matrix_set_color(2, 0, 64, 0);     rgb_matrix_set_color(3, 0, 128, 0);    rgb_matrix_set_color(4, 0, 255, 0);
		rgb_matrix_set_color(5, 192, 192, 255); rgb_matrix_set_color(6, 64, 64, 255);  rgb_matrix_set_color(7, 32, 32, 255);  rgb_matrix_set_color(8, 0, 0, 255);
		rgb_matrix_set_color(9, 255, 0, 0);     rgb_matrix_set_color(10, 255, 128, 0); rgb_matrix_set_color(11, 255, 255, 0); rgb_matrix_set_color(12, 128, 255, 0);
	}
	
	if (layer_state_is(_FL)) {
		for (int i = 0; i < 10; i++) {
			rgb_matrix_set_color(FL_KEYS[i], 255, 0, 0);
		}
	}

	//blink capslock key orange when capsword is enabled
	bool isCapswordLedOn = true;
	static uint16_t key_timer;
	
	if (is_caps_word_on()) {
		if (timer_elapsed(key_timer) > 400) {
			isCapswordLedOn = !isCapswordLedOn;
			key_timer = timer_read();
		} else if (timer_elapsed(key_timer) > 200) {
			isCapswordLedOn = !isCapswordLedOn;
		}
		
		if (isCapswordLedOn) {
			RGB_MATRIX_INDICATOR_SET_COLOR(54, 255, 128, 0); //caps(lock||word) orange
		}
	}
	
    return true;
}

void keyboard_post_init_user(void) {
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
	rgblight_sethsv_noeeprom(186, 255, 255);
}