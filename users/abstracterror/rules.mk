COMBO_ENABLE = yes
UNICODEMAP_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
OS_DETECTION_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
TAP_DANCE_ENABLE = yes

VPATH += keyboards/gboards
SRC += ae_unicodemap.c ae_keyoverrides.c ae_osdetection.c ae_process.c ae_tapdances.c
