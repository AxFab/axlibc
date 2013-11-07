# Project: Sample
# ===============================================
BUILD = $(value $MAKE_SCRIPTS_DIR)
ifeq ($(BUILD),)
BUILD = build
endif
 -include $(BUILD)/cproject.mk
# -----------------------------------------------
store =

# PACK / TARGETS --------------------------------
all: 			basics

# DEFINE DELIVERY -------------------------------
basics_fragments	= string alloc
basics_lflags		=
$(eval $(call LIBRARY,basics))


# FLAGS -----------------------------------------
ld_check_ 		= 
libs_check 		= -lcheck
CFLAGS 			+= -D__BSC -nostdinc
LFLAGS 			+= -nostdlib
