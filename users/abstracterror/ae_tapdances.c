#include "quantum.h"
#include "abstracterror.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD
} td_state_t;

static td_state_t td_layer_tap_state = TD_NONE;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return TD_SINGLE_TAP;
        }
        return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) {
            return TD_SINGLE_TAP;
        }
        return TD_DOUBLE_HOLD;
    }
    return TD_UNKNOWN;
}

void ae_tap_dance_layer_tap_finished(tap_dance_state_t *state, void *user_data) {
    ae_tap_dance_layer_tap_t *pair = (ae_tap_dance_layer_tap_t *)user_data;

    td_layer_tap_state = cur_dance(state);
    switch (td_layer_tap_state) {
        case TD_SINGLE_TAP:
            ae_tap_code(pair->kc);
            break;
        case TD_SINGLE_HOLD:
            layer_on(pair->layer);
            break;
        case TD_DOUBLE_HOLD:
            ae_register_code(pair->kc);
            break;
        default:
            break;
    }
}

void ae_tap_dance_layer_tap_reset(tap_dance_state_t *state, void *user_data) {
    ae_tap_dance_layer_tap_t *pair = (ae_tap_dance_layer_tap_t *)user_data;

    switch (td_layer_tap_state) {
        case TD_SINGLE_HOLD:
            layer_off(pair->layer);
            break;
        case TD_DOUBLE_HOLD:
            ae_unregister_code(pair->kc);
            break;
        default:
            break;
    }

    td_layer_tap_state = TD_NONE;
}
