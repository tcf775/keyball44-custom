// Keyball44 カスタム設定
// 6レイヤー対応

#pragma once

// ========================================
// VIA/Remap レイヤー数設定
// ========================================
// デフォルトは4レイヤーだが、6レイヤーに拡張
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// ========================================
// 元のvia設定を維持
// ========================================
#ifdef RGBLIGHT_ENABLE
//# define RGBLIGHT_EFFECT_BREATHING
//# define RGBLIGHT_EFFECT_RAINBOW_MOOD
//# define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//# define RGBLIGHT_EFFECT_SNAKE
//# define RGBLIGHT_EFFECT_KNIGHT
//# define RGBLIGHT_EFFECT_CHRISTMAS
# define RGBLIGHT_EFFECT_STATIC_GRADIENT
//# define RGBLIGHT_EFFECT_RGB_TEST
//# define RGBLIGHT_EFFECT_ALTERNATING
//# define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

// 自動マウスレイヤー設定
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1
