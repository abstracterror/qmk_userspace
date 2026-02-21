#include "quantum.h"
#include "abstracterror.h"

const uint32_t PROGMEM unicode_map[] = {
    [POUND_SIGN]                = 0x00A3,
    [EURO_SIGN]                 = 0x20AC,
#ifdef CADET_ALPHAS
    [LOGICAL_AND]               = 0x2227,
    [LOGICAL_OR]                = 0x2228,
    [INTERSECTION]              = 0x2229,
    [UNION]                     = 0x222A,
    [SUBSET_OF]                 = 0x2282,
    [SUPERSET_OF]               = 0x2283,
    [FOR_ALL]                   = 0x2200,
    [INFINITY_SYMBOL]           = 0x221E,
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
#ifdef PHOENICIAN_ENABLE
    [ALF]                       = 0x10900,
    [BET]                       = 0x10901,
    [GAML]                      = 0x10902,
    [DELT]                      = 0x10903,
    [HE]                        = 0x10904,
    [WAU]                       = 0x10905,
    [ZAI]                       = 0x10906,
    [HET]                       = 0x10907,
    [TET]                       = 0x10908,
    [YOD]                       = 0x10909,
    [KAF]                       = 0x1090A,
    [LAMD]                      = 0x1090B,
    [MEM]                       = 0x1090C,
    [NUN]                       = 0x1090D,
    [SEMK]                      = 0x1090E,
    [AIN]                       = 0x1090F,
    [PE]                        = 0x10910,
    [SADE]                      = 0x10911,
    [QOF]                       = 0x10912,
    [ROSH]                      = 0x10913,
    [SHIN]                      = 0x10914,
    [TAU]                       = 0x10915,

// The following is not from the Phoenician alphabet, but appears in
// KAT Iron's Phoenician alphas kit.
    [VAV]                       = 0x05D5,   // Hebrew

#endif
};
