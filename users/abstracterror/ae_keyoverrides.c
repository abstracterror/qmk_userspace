#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_uk.h"
#include "abstracterror.h"

static bool send_uk_codes = false;

#define uk_simple_key_override(trigger, replacement) \
    uk_key_override(0, trigger, replacement, NULL, NULL)

#define uk_shifted_key_override(trigger, replacement) \
    uk_key_override(MOD_MASK_SHIFT, trigger, replacement, NULL, NULL)

#define uk_action_key_override(trigger, action) \
    uk_key_override(0, trigger, KC_NO, action, NULL)

#define uk_key_override(trigger_mods_, trigger_, replacement_, action_, context_) \
    ((const key_override_t) {                                           \
        .trigger            = (trigger_),                               \
        .trigger_mods       = (trigger_mods_),                          \
        .layers             = ~0,                                       \
        .negative_mod_mask  = 0,                                        \
        .suppressed_mods    = (trigger_mods_),                          \
        .replacement        = (replacement_),                           \
        .options            = ko_options_default | ko_option_one_mod,   \
        .custom_action      = (action_),                                \
        .context            = (void *)(context_),                       \
        .enabled            = &send_uk_codes                            \
    })

void set_send_uk_codes(bool value) {
    send_uk_codes = value;
}

bool uk_at_action(bool activated, void *context) {
    if (activated) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_QUOT));
    } else {
        SEND_STRING(SS_UP(X_QUOT) SS_UP(X_LSFT));
    }
    return false;
}

bool uk_dquo_action(bool activated, void *context) {
    if (activated) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_2));
    } else {
        SEND_STRING(SS_UP(X_2) SS_UP(X_LSFT));
    }
    return false;
}

bool uk_tilde_action(bool activated, void *context) {
    if (activated) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_NUHS));
    } else {
        SEND_STRING(SS_UP(X_NUHS) SS_UP(X_LSFT));
    }
    return false;
}

bool uk_pipe_action(bool activated, void *context) {
    if (activated) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_NUBS));
    } else {
        SEND_STRING(SS_UP(X_NUBS) SS_UP(X_LSFT));
    }
    return false;
}

// Keys where the shifted version requires a different keycode on a UK keyboard.
const key_override_t uk_two_override   = uk_shifted_key_override(KC_2,     UK_AT);
const key_override_t uk_three_override = uk_shifted_key_override(KC_3,     UK_HASH);
const key_override_t uk_quote_override = uk_shifted_key_override(KC_QUOTE, UK_DQUO);
const key_override_t uk_grave_override = uk_shifted_key_override(KC_GRAVE, UK_TILD);

// Keys where the unshifted version requires a different keycode on a UK keyboard.
const key_override_t uk_hash_override  = uk_simple_key_override(KC_HASH, UK_HASH);
const key_override_t uk_bsls_override  = uk_simple_key_override(KC_BSLS, UK_BSLS);

/*
// Keys where the shifted version appears in my keymaps, but that requires a
// different keycode on a UK keyboard. For these we use a macro to try to avoid
// problems with Microsoft Remote Desktop dropping modifiers.
*/
const key_override_t uk_at_override    = uk_action_key_override(KC_AT,   &uk_at_action);
const key_override_t uk_dquo_override  = uk_action_key_override(KC_DQUO, &uk_dquo_action);
const key_override_t uk_tild_override  = uk_action_key_override(KC_TILD, &uk_tilde_action);
const key_override_t uk_pipe_override  = uk_action_key_override(KC_PIPE, &uk_pipe_action);


const key_override_t **key_overrides = (const key_override_t *[]){
    &uk_two_override,
    &uk_three_override,
    &uk_quote_override,
    &uk_grave_override,

    &uk_hash_override,
    &uk_bsls_override,

    &uk_at_override,
    &uk_dquo_override,
    &uk_tild_override,
    &uk_pipe_override,

    NULL,
};
