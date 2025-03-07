#pragma once

enum layer_names {
    _BASE,

#ifdef PHOENICIAN_ENABLE
    _PHOENICIAN,
#endif

    _NUM,
    _FUN,
    _LSYM,

#ifdef MULTIPLE_KEYS_PER_THUMB
    _TSYM,
#endif

    _NAV, // must come after _NUM and _FUN

#ifdef POINTING_DEVICE_ENABLE
    _MOUSE,
#endif
};

// Use in keymaps to get the effect of MT(MOD_LSFT, QK_CAPS_WORD_TOGGLE), if
// mod-tap supported non-basic keycodes. This relies on code in this user
// space's `process_record_user` to implement the tap action.
#define MT_LSFT_CAPS_WORD_TOGGLE MT(MOD_LSFT, KC_CAPS)

// Short keycode aliases
#define PREVTAB LCTL(LSFT(KC_TAB))
#define NEXTTAB LCTL(KC_TAB)
#define CTL_BRK LCTL(KC_BRK)
#define RGB_RMD RGB_MODE_REVERSE

// not the usual MEH, but I swap Command and Option in macOS
#define AE_MEH S(C(KC_LGUI))

#if defined(QWERTY_KEYMAP) || defined(QAZ_KEYMAP)
    // layer taps
#   define LT_E     LT(_FUN,     KC_E)
#   define LT_R     LT(_NUM,     KC_R)
#   define LT_U     LT(_LSYM,    KC_U)
    // home-row mods
#   define MT_A     MT(MOD_LCTL, KC_A)
#   define MT_S     MT(MOD_LSFT, KC_S)
#   define MT_D     MT(MOD_LGUI, KC_D)
#   define MT_F     MT(MOD_LALT, KC_F)

#   define MT_J     MT(MOD_LALT, KC_J)
#   define MT_K     MT(MOD_LGUI, KC_K)
#   define MT_L     MT(MOD_RSFT, KC_L)
#   define MT_SCLN  MT(MOD_LCTL, KC_SCLN)

    // mod-taps for conventional shift position on QAZ-like layouts
#   define MT_Z     MT(MOD_LSFT, KC_Z)
#   if defined(QWERTY_KEYMAP)
        // for things like Vault 35, with 10 keys in R4
#       define MT_SLSH  MT(MOD_RSFT, KC_SLSH)
#   else
        // true QAZ layout
#       define MT_SLSH  MT(MOD_LCTL, KC_SLSH)
#       define MT_DOT   MT(MOD_RSFT, KC_DOT)
#   endif
#else
    // layer taps
#   define LT_F     LT(_FUN,     KC_F)
#   define LT_P     LT(_NUM,     KC_P)
#   define LT_L     LT(_LSYM,    KC_L)
    // home-row mods
#   define MT_A     MT(MOD_LCTL, KC_A)
#   define MT_R     MT(MOD_LSFT, KC_R)
#   define MT_S     MT(MOD_LGUI, KC_S)
#   define MT_T     MT(MOD_LALT, KC_T)

#   define MT_N     MT(MOD_LALT, KC_N)
#   define MT_E     MT(MOD_LGUI, KC_E)
#   define MT_I     MT(MOD_RSFT, KC_I)
#   define MT_O     MT(MOD_LCTL, KC_O)
#endif

#ifdef POINTING_DEVICE_ENABLE
#   define LT_Z     LT(_MOUSE,   KC_Z)
#endif

// right-hand thumb layer tap
#define LT_SPC  LT(_NAV,   KC_SPC)
#define LT_0    LT(_NAV,   KC_0)
#define LT_F10  LT(_NAV,   KC_F10)

// left-hand thumb mod tap
#define MT_TAB  MT(MOD_LSFT, KC_TAB)
#define MT_CWT  MT_LSFT_CAPS_WORD_TOGGLE

// extra thumb keys
#if defined(MULTIPLE_KEYS_PER_THUMB)
#   define  LT_TAB      LT(_NUM, KC_TAB)
#   define  MO_NUM      MO(_NUM)
#   define  MO_LSYM     MO(_LSYM)
#   define  MO_TSYM     MO(_TSYM)
#endif


// custom keycodes
enum userspace_keycodes {
    UNDO = SAFE_RANGE,
    REDO,
    CUT,
    COPY,
    PASTE,
    SEL_ALL,
    UK_TOGG,

#ifdef TASK_SWITCHING
    NEXT_TASK,
    PREVIOUS_TASK,
    NEXT_WINDOW,
    PREVIOUS_WINDOW,
#endif

    KEYMAP_SAFE_RANGE
};

// names for indexes into the Unicode map
enum unicode_names {
    POUND_SIGN,
    EURO_SIGN,

#ifdef CADET_ALPHAS
    // symbols from the Space Cadet keyboard
    LOGICAL_AND,
    LOGICAL_OR,
    INTERSECTION,
    UNION,
    SUBSET_OF,
    SUPERSET_OF,
    FOR_ALL,
    INFINITY,
    THERE_EXISTS,
    PARTIAL_DIFFERENTIAL,
    UP_TACK,
    DOWN_TACK,
    RIGHT_TACK,
    LEFT_TACK,
    UPWARDS_ARROW,
    DOWNWARDS_ARROW,
    LEFTWARDS_ARROW,
    RIGHTWARDS_ARROW,
    LEFT_RIGHT_ARROW,
    LEFT_FLOOR,
    LEFT_CEILING,
    NOT_EQUAL_TO,
    ASYMPTOTICALLY_EQUAL_TO,
    IDENTICAL_TO,
    LESS_THAN_OR_EQUAL_TO,
    GREATER_THAN_OR_EQUAL_TO,
#endif

#ifdef PHOENICIAN_ENABLE
    ALF,
    BET,
    GAML,
    DELT,
    HE,
    WAU,
    ZAI,
    HET,
    TET,
    YOD,
    KAF,
    LAMD,
    MEM,
    NUN,
    SEMK,
    AIN,
    PE,
    SADE,
    QOF,
    ROSH,
    SHIN,
    TAU,

// The following is not from the Phoenician alphabet, but appears in
// KAT Iron's Phoenician alphas kit.
    VAV,
#endif
};

// names for the corresponding keycodes
#define UM_GBP  UM(POUND_SIGN)
#define UM_EURO UM(EURO_SIGN)

#ifdef CADET_ALPHAS
#define UM_AND  UM(LOGICAL_AND)
#define UM_OR   UM(LOGICAL OR)
#define UM_INTS UM(INTERSECTION)
#define UM_UNIO UM(UNION)
#define UM_SUBS UM(SUBSET_OF)
#define UM_SUPS UM(SUPERSET_OF)
#define UM_FALL UM(FOR_ALL)
#define UM_INF  UM(INFINITY)
#define UM_EXST UM(THERE_EXISTS)
#define UM_PDIF UM(PARTIAL_DIFFERENTIAL)
#define UM_BTTM UM(UP_TACK)
#define UM_TOP  UM(DOWN_TACK)
#define UM_RTAC UM(RIGHT_TACK)
#define UM_LTAC UM(LEFT_TACK)
#define UM_UP   UM(UPWARDS_ARROW)
#define UM_DOWN UM(DOWNWARDS_ARROW)
#define UM_LEFT UM(LEFTWARDS_ARROW)
#define UM_RGHT UM(RIGHTWARDS_ARROW)
#define UM_LR   UM(LEFT_RIGHT_ARROW)
#define UM_LFLR UM(LEFT_FLOOR)
#define UM_LCEI UM(LEFT_CEILING)
#define UM_NEQL UM(NOT_EQUAL_TO)
#define UM_AEQL UM(ASYMPTOTICALLY_EQUAL_TO)
#define UM_IDEN UM(IDENTICAL_TO)
#define UM_LEQL UM(LESS_THAN_OR_EQUAL_TO)
#define UM_GEQL UM(GREATER_THAN_OR_EQUAL_TO)
#endif

#ifdef PHOENICIAN_ENABLE
#define UM_ALF  UM(ALF)
#define UM_BET  UM(BET)
#define UM_GAML UM(GAML)
#define UM_DELT UM(DELT)
#define UM_HE   UM(HE)
#define UM_WAU  UM(WAU)
#define UM_ZAI  UM(ZAI)
#define UM_HET  UM(HET)
#define UM_TET  UM(TET)
#define UM_YOD  UM(YOD)
#define UM_KAF  UM(KAF)
#define UM_LAMD UM(LAMD)
#define UM_MEM  UM(MEM)
#define UM_NUN  UM(NUN)
#define UM_SEMK UM(SEMK)
#define UM_AIN  UM(AIN)
#define UM_PE   UM(PE)
#define UM_SADE UM(SADE)
#define UM_QOF  UM(QOF)
#define UM_ROSH UM(ROSH)
#define UM_SHIN UM(SHIN)
#define UM_TAU  UM(TAU)

// The following is not from the Phoenician alphabet, but appears in
// KAT Iron's Phoenician alphas kit.
#define UM_VAV  UM(VAV)
#endif

// Enables/disables the overrides that send keycodes for a UK keyboard.
extern void set_send_uk_codes(bool value);
extern void toggle_send_uk_codes(void);

extern void ae_tap_code(uint16_t code);
extern void ae_register_code(uint16_t code);
extern void ae_unregister_code(uint16_t code);
