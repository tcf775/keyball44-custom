// Keyball44 カスタムキーマップ
// 6レイヤー対応版

#include QMK_KEYBOARD_H
#include "quantum.h"

// ========================================
// レイヤー定義
// ========================================

enum layer_number {
    _BASE = 0,   // 基本レイヤー（QWERTY）
    _NUM,        // 数字・マウスレイヤー
    _SYM,        // 記号レイヤー
    _FN,         // ファンクション・RGBレイヤー
    _EXTRA1,     // 追加レイヤー1（Remapで設定してね）
    _EXTRA2      // 追加レイヤー2（Remapで設定してね）
};

// ========================================
// キーマップ
// ========================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base（QWERTY）
    [_BASE] = LAYOUT_universal(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_FN),
                 MO(_NUM),KC_ESC,  KC_LGUI, KC_LALT, KC_SPC,                              KC_ENT,  KC_BSPC, MO(_SYM),KC_DEL,  MO(_FN)
    ),

    // Layer 1: Numbers / Mouse
    [_NUM] = LAYOUT_universal(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_PGDN,
        _______, _______, _______, _______, _______, _______,                             KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______,
                 _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______
    ),

    // Layer 2: Symbols
    [_SYM] = LAYOUT_universal(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
        _______, _______, _______, _______, _______, _______,                             KC_PIPE, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PLUS,
        _______, _______, _______, _______, _______, _______,                             KC_LABK, KC_RABK, KC_QUES, _______, KC_EQL,  _______,
                 _______, _______, _______, _______, _______,                             _______, KC_DEL,  _______, _______, _______
    ),

    // Layer 3: Function / RGB / System
    [_FN] = LAYOUT_universal(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,                             KC_F12,  _______, _______, _______, _______, _______,
        _______, QK_BOOT, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,                             _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______
    ),

    // Layer 4: Extra1（空レイヤー - Remapで自由に設定してね）
    [_EXTRA1] = LAYOUT_universal(
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______
    ),

    // Layer 5: Extra2（空レイヤー - Remapで自由に設定してね）
    [_EXTRA2] = LAYOUT_universal(
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______
    )
};

// ========================================
// レイヤー切り替え時の処理
// ========================================
// レイヤー3（_FN）に切り替えるとトラックボールがスクロールモードになる
layer_state_t layer_state_set_user(layer_state_t state) {
    // レイヤー3のときスクロールモードを有効化
    keyball_set_scroll_mode(get_highest_layer(state) == _FN);
    return state;
}

// ========================================
// OLED表示設定
// ========================================
// Keyball公式のoledkitライブラリを使用
#ifdef OLED_ENABLE
#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    // 押しているキー情報を表示
    keyball_oled_render_keyinfo();
    // トラックボール情報（CPI等）を表示
    keyball_oled_render_ballinfo();
    // 現在のレイヤー情報を表示
    keyball_oled_render_layerinfo();
}
#endif
