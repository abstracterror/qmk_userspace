#include QMK_KEYBOARD_H
#include "abstracterror.h"

const uint32_t PROGMEM unicode_map[] = {
#ifdef CADET_ALPHAS
    [LOGICAL_AND]               = 0x2227,
    [LOGICAL_OR]                = 0x2228,
    [INTERSECTION]              = 0x2229,
    [UNION]                     = 0x222A,
    [SUBSET_OF]                 = 0x2282,
    [SUPERSET_OF]               = 0x2283,
    [FOR_ALL]                   = 0x2200,
    [INFINITY]                  = 0x221E,
    [THERE_EXISTS]              = 0x2203,
    [PARTIAL_DIFFERENTIAL]      = 0x2202,
    [UP_TACK]                   = 0x22A5,
    [DOWN_TACK]                 = 0x22A4,
    [RIGHT_TACK]                = 0x22A2,
    [LEFT_TACK]                 = 0x22A3,
    [UPWARDS_ARROW]             = 0x2191,
    [DOWNWARDS_ARROW]           = 0x2193,
    [LEFTWARDS_ARROW]           = 0x2190,
    [RIGHTWARDS_ARROW]          = 0x2192,
    [LEFT_RIGHT_ARROW]          = 0x2194,
    [LEFT_FLOOR]                = 0x230A,
    [LEFT_CEILING]              = 0x2308,
    [NOT_EQUAL_TO]              = 0x2260,
    [ASYMPTOTICALLY_EQUAL_TO]   = 0x2243,
    [IDENTICAL_TO]              = 0x2261,
    [LESS_THAN_OR_EQUAL_TO]     = 0x2264,
    [GREATER_THAN_OR_EQUAL_TO]  = 0x2265,
#endif
};
