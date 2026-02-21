COMBO_ENABLE = yes

UNICODE_ENABLE = no
UNICODEMAP_ENABLE = yes
UCIS_ENABLE = no

KEY_OVERRIDE_ENABLE = yes
OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes

ifeq ($(strip $(PHOENICIAN_ENABLE)), yes)
	OPT_DEFS += -DPHOENICIAN_ENABLE
endif

ifeq ($(strip $(CADET_ALPHAS)), yes)
	OPT_DEFS += -DCADET_ALPHAS
endif

SRC += ae_unicodemap.c ae_osdetection.c ae_process.c
