#include "quantum.h"
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

void toggle_send_uk_codes() {
    send_uk_codes = !send_uk_codes;
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

bool tilde_action(bool activated, void *context) {
    if (send_uk_codes) {
        if (activated) {
            register_code(KC_NUHS);
        } else {
            unregister_code(KC_NUHS);
        }
    } else {
        if (activated) {
            register_code16(KC_TILD);
        } else {
            unregister_code16(KC_TILD);
        }
    }
    return false;
}

void ae_tap_code(uint16_t code) {
    if (!send_uk_codes) {
        tap_code16(code);
    } else {
        switch (code) {
            case KC_AT:
                uk_at_action(true, NULL);
                uk_at_action(false, NULL);
                break;
            case KC_BSLS:
                tap_code16(UK_BSLS);
                break;
            case KC_HASH:
                tap_code16(UK_HASH);
                break;
            case KC_DQUO:
                uk_dquo_action(true, NULL);
                uk_dquo_action(false, NULL);
                break;
            case KC_TILD:
                uk_tilde_action(true, NULL);
                uk_tilde_action(false, NULL);
                break;
            case KC_PIPE:
                uk_pipe_action(true, NULL);
                uk_pipe_action(false, NULL);
                break;
            default:
                tap_code16(code);
                break;
        }
    }
}

void ae_register_code(uint16_t code) {
    if (!send_uk_codes) {
        register_code16(code);
    } else {
        switch (code) {
            case KC_AT:
                uk_at_action(true, NULL);
                break;
            case KC_BSLS:
                register_code16(UK_BSLS);
                break;
            case KC_HASH:
                register_code16(UK_HASH);
                break;
            case KC_DQUO:
                uk_dquo_action(true, NULL);
                break;
            case KC_TILD:
                uk_tilde_action(true, NULL);
                break;
            case KC_PIPE:
                uk_pipe_action(true, NULL);
                break;
            default:
                register_code16(code);
                break;
        }
    }
}

void ae_unregister_code(uint16_t code) {
    if (!send_uk_codes) {
        unregister_code16(code);
    } else {
        switch (code) {
            case KC_AT:
                uk_at_action(false, NULL);
                break;
            case KC_BSLS:
                unregister_code16(UK_BSLS);
                break;
            case KC_HASH:
                unregister_code16(UK_HASH);
                break;
            case KC_DQUO:
                uk_dquo_action(false, NULL);
                break;
            case KC_TILD:
                uk_tilde_action(false, NULL);
                break;
            case KC_PIPE:
                uk_pipe_action(false, NULL);
                break;
            default:
                unregister_code16(code);
                break;
        }
    }
}

// Keys where the shifted version requires a different keycode on a UK keyboard.
const key_override_t uk_two_override   = uk_shifted_key_override(KC_2,     UK_AT);
const key_override_t uk_three_override = uk_shifted_key_override(KC_3,     UK_HASH);
const key_override_t uk_quote_override = uk_shifted_key_override(KC_QUOTE, UK_DQUO);
const key_override_t uk_grave_override = uk_shifted_key_override(KC_GRAVE, UK_TILD);

// Keys where the unshifted version requires a different keycode on a UK keyboard.
const key_override_t uk_hash_override  = uk_simple_key_override(KC_HASH, UK_HASH);
const key_override_t uk_bsls_override  = uk_simple_key_override(KC_BSLS, UK_BSLS);

// Keys where the shifted version appears in my keymaps, but that requires a
// different keycode on a UK keyboard. For these we use a macro to try to avoid
// problems with Microsoft Remote Desktop dropping modifiers.
const key_override_t uk_at_override    = uk_action_key_override(KC_AT,   &uk_at_action);
const key_override_t uk_dquo_override  = uk_action_key_override(KC_DQUO, &uk_dquo_action);
const key_override_t uk_tild_override  = uk_action_key_override(KC_TILD, &uk_tilde_action);
const key_override_t uk_pipe_override  = uk_action_key_override(KC_PIPE, &uk_pipe_action);

// Keys where I want a different result from the default on both US and UK keyboards
const key_override_t nine_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_GRAVE);
const key_override_t zero_override = {
    .trigger_mods           = MOD_MASK_SHIFT,
    .layers                 = ~0,
    .suppressed_mods        = 0,
    .options                = ko_option_activation_trigger_down |
                              ko_option_activation_required_mod_down |
                              ko_option_one_mod,
    .negative_mod_mask      = 0,
    .custom_action          = tilde_action,
    .context                = NULL,
    .trigger                = LT(_NAV, KC_0),
    .replacement            = KC_NO,
    .enabled                = NULL
};

const key_override_t *key_overrides[] = {
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

    &nine_override,
    &zero_override,
};
