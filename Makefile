# Makefile 

ifeq ($(MAKE_SCRIPTS_DIR),)
  MAKE_SCRIPTS_DIR = build
endif

-include $(MAKE_SCRIPTS_DIR)/settings.mk
-include $(MAKE_SCRIPTS_DIR)/common.mk


# ===========================================================================

system = $(shell uname -sr)
date = $(shell date '+%d %b %Y')

pack_cflags =  -D_DATE_=\"'$(date)'\" -D_OS_FULLNAME_=\"'$(system)'\"

cflags = $(pack_cflags) -Wall -Wextra -Wno-unused-parameter

std_debug_cflags = 			$(cflags) -g -ggdb
std_release_cflags =  	$(cflags) -fPIC -O3


# ===========================================================================


# Target: Library  libAxStdC
libAxStdC_src = \
		$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
		$(patsubst src/%,%,$(wildcard src/string/*.c)) \
		$(patsubst src/%,%,$(wildcard src/format/*.c)) 
libAxStdC_inc = include/
libAxStdC_cflags =  $(std_$(mode)_cflags) -nostdinc -D__C99
libAxStdC_lflags = -nostdlib
$(eval $(call LIBRARY,libAxStdC))



# Target: Library  libAxRaw
libAxRaw_src = \
		$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
		$(patsubst src/%,%,$(wildcard src/string/*.c)) \
		$(patsubst src/%,%,$(wildcard src/format/*.c)) 
libAxRaw_inc = include/
libAxRaw_cflags =  $(std_$(mode)_cflags) -nostdinc -D__EX
libAxRaw_lflags = -nostdlib
$(eval $(call LIBRARY,libAxRaw))



# Target: Program  format
format_src =  $(patsubst src/%,%,$(wildcard src/format/*.c)) tests/format.c
format_inc = include/
format_cflags =  $(std_$(mode)_cflags) -D__C99
$(eval $(call PROGRAM,format))


alloc_src =  $(patsubst src/%,%,$(wildcard src/alloc/*.c)) tests/alloc.c
alloc_inc = include/
alloc_cflags =  $(std_$(mode)_cflags) -D__C99
$(eval $(call PROGRAM,alloc))

# ===========================================================================

-include $(MAKE_SCRIPTS_DIR)/utils.mk

