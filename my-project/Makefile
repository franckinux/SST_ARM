PROJECT = sst
BUILD_DIR = bin

SHARED_DIR = ../my-common-code ../sst
CFILES = main.c mytask.c interrupts.c sst_user.c
CFILES += api.c
CFILES += sst.c sst_port.c
AFILES += api-asm.S

CFLAGS += -DRCC_LED1=RCC_GPIOC -DPORT_LED1=GPIOC -DPIN_LED1=GPIO13
LDFLAGS += -Wl,-Map,$(PROJECT).map

# TODO - you will need to edit these two lines!
DEVICE=stm32f103c8t6
OOCD_FILE = board/stm32f1x_stlink.cfg

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
