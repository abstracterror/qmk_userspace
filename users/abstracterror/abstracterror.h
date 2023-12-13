#pragma once

// custom keycodes
enum userspace_keycodes {
    UNDO = SAFE_RANGE,
    REDO,

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
    // characters for which a UK keyboard has different codes
    COMMERCIAL_AT,
    NUMBER_SIGN,
    QUOTATION_MARK,
    TILDE,
    REVERSE_SOLIDUS,
    VERTICAL_LINE,

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
};

// names for the corresponding keycodes
#define UM_AT   UM(COMMERCIAL_AT)
#define UM_HASH UM(NUMBER_SIGN)
#define UM_DQUO UM(QUOTATION_MARK)
#define UM_TILD UM(TILDE)
#define UM_BSLS UM(REVERSE_SOLIDUS)
#define UM_PIPE UM(VERTICAL_BAR)

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

// Enables/disables the overrides that send keycodes for a UK keyboard.
extern void set_send_uk_codes(bool value);
