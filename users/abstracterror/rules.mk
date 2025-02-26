COMBO_ENABLE = yes
UNICODEMAP_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes

ifeq ($(strip $(PHOENICIAN_ENABLE)), yes)
	OPT_DEFS += -DPHOENICIAN_ENABLE
endif

SRC += ae_unicodemap.c ae_osdetection.c ae_process.c
