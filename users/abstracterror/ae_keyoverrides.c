#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_uk.h"
#include "ae_unicodemap.h"
#include "ae_keyoverrides.h"

static bool send_uk_codes = false;

#define uk_simple_key_override(trigger, replacement) \
    uk_key_override(0, trigger, replacement, NULL, NULL)

#define uk_shifted_key_override(trigger, replacement) \
    uk_key_override(MOD_MASK_SHIFT, trigger, replacement, NULL, NULL)

#define uk_unicode_key_override(trigger, replacement) \
    uk_key_override(0, trigger, KC_NO, &unicode_override, &(unicode_map[replacement]))

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

bool unicode_override(bool activated, void *context) {
    if (!activated) {
        return true;
    }

    register_unicode(*((uint32_t *)context));
    return false;
}

// Keys where the shifted version requires a different keycode on a UK keyboard.
const key_override_t uk_two_override   = uk_shifted_key_override(KC_2, UK_AT);
const key_override_t uk_three_override = uk_shifted_key_override(KC_3, UK_HASH);
const key_override_t uk_quote_override = uk_shifted_key_override(KC_QUOTE, UK_DQUO);
const key_override_t uk_grave_override = uk_shifted_key_override(KC_GRAVE, UK_TILD);

// Keys where the unshifted version requires a different keycode on a UK keyboard.
const key_override_t uk_hash_override  = uk_simple_key_override(KC_HASH, UK_HASH);
const key_override_t uk_bsls_override  = uk_simple_key_override(KC_BSLS, UK_BSLS);

// Keys where the shifted version appears in my keymaps, but that requires a
// different keycode on a UK keyboard. For these we use Unicode to try to avoid
// problems with Microsoft Remote Desktop dropping modifiers; this is not ideal -
// we lose auto-repeat, for example.
const key_override_t uk_at_override    = uk_unicode_key_override(KC_AT,   COMMERCIAL_AT);
const key_override_t uk_dquo_override  = uk_unicode_key_override(KC_DQUO, QUOTATION_MARK);
const key_override_t uk_tild_override  = uk_unicode_key_override(KC_TILD, TILDE);
const key_override_t uk_pipe_override  = uk_unicode_key_override(KC_PIPE, VERTICAL_LINE);


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
