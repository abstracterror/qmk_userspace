#define EE_HANDS

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT

// Redefine encoder resolutions to prevent knobs sending double presses.

// Redefine encoder pins to get directions that I expect.
#undef ENCODER_A_PINS
#undef ENCODER_B_PINS
#define ENCODER_A_PINS { B5, B3 }
#define ENCODER_B_PINS { B4, B2 }

// Flip encoder directions for the right-hand side.
#define ENCODER_A_PINS_RIGHT { B4, B2 }
#define ENCODER_B_PINS_RIGHT { B5, B3 }
