#include QMK_KEYBOARD_H

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _MOUSE,
  _FUNCTIONS,
};

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
};

extern rgb_config_t rgb_matrix_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl |Layer4| GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_planck_grid(
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,
    KC_LCTL,        MO(4),          KC_LGUI,        KC_LALT,        LOWER,          KC_SPACE,       KC_NO,          RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |   ^  |   /  |   *  |   +  |   -  |      | Left | Down |  Up  |Right |      |  Ins |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   ?  |   %  |   _  |   =  |      |      |      |   <  |   >  |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | Home | PgDn | PgUp |  End |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_DELETE,
    KC_CIRC,        KC_SLASH,       KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_INSERT,
    KC_TRANSPARENT, KC_QUES,        KC_PERC,        KC_UNDS,        KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   $  |      |      |      |   [  |   ]  |      |      |  Del |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   \  |   #  |   &  |      |      |      |   (  |   )  |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   |  |      |      |      |      |      |   {  |   }  |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | Home | PgDn | PgUp |  End |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,
    KC_TRANSPARENT, KC_BSLS,        KC_HASH,        KC_AMPR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, KC_COLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PIPE,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END
  ),

  /* Mouse
  * ,-----------------------------------------------------------------------------------------------.
  * |       |Left C |   Up  |Right C|       |       |       |Accel 0|Accel 1|Accel 2|       |       |
  * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
  * |       | Left  | Down  | Right |       |       |Wheel L|Wheel D|Wheel U|Wheel R|       |       |
  * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
  * |       |       |Midd C |       |       |       |       |       |       |       |       |       |
  * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
  * |       | Reset |       |       |       |       |       |       |       |       |       |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  /* Functions
  * ,-----------------------------------------------------------------------------------.
  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_FUNCTIONS] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = { {169,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {0,255,255}, {169,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {139,255,255}, {13,255,255}, {169,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {169,255,255}, {169,255,255}, {210,255,255}, {169,255,255}, {169,255,255}, {210,255,255}, {0,0,0}, {210,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },
    [_LOWER] = { {13,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {68,255,255}, {0,255,255}, {13,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {41,255,255}, {0,0,0}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },
    [_RAISE] = { {13,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {139,255,255}, {0,0,0}, {139,255,255}, {0,0,0}, {0,0,0}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },
    [_MOUSE] = { {0,0,0}, {210,255,255}, {210,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {210,255,255}, {210,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [_FUNCTIONS] = { {0,0,0}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {13,255,255}, {0,0,0}, {0,0,0}, {13,255,255}, {13,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _MOUSE);
}
