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

cflags = $(pack_cflags) 
cflags += -Wall -Wextra -Wpointer-arith -Wshadow -Wcast-align -Winline -Wimplicit 
# cflags += -fPIC

std_debug_cflags = 			$(cflags) -g -ggdb 
std_release_cflags =  	$(cflags) -fPIC -O3


# ===========================================================================

glue_f: libaxc
	@objdump $(lib_dir)/libaxc.so -x | grep '*UND*' | \
	 awk '{ print $4 } ' | sort | uniq


# Target: Library  libAxStdC
libaxc_src = \
		$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
		$(patsubst src/%,%,$(wildcard src/crypto/*.c)) \
		$(patsubst src/%,%,$(wildcard src/format/*.c)) \
		$(patsubst src/%,%,$(wildcard src/stdio/*.c)) \
		$(patsubst src/%,%,$(wildcard src/stdlib/*.c)) \
		$(patsubst src/%,%,$(wildcard src/time/*.c)) \
		$(patsubst src/%,%,$(wildcard src/string/*.c)) 
libaxc_inc = include/ internal/
libaxc_cflags =  $(std_$(mode)_cflags) -nostdinc -D__C99
libaxc_lflags = -nostdlib
$(eval $(call LIBRARY,libaxc))



# Target: Library  libAxRaw
libAxRaw_src = \
		$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
		$(patsubst src/%,%,$(wildcard src/string/*.c)) \
		$(patsubst src/%,%,$(wildcard src/format/*.c)) \
		$(patsubst src/%,%,$(wildcard src/time/*.c)) \
		tests/error.c
libAxRaw_inc = include/ internal/
libAxRaw_cflags =  $(std_$(mode)_cflags) -nostdinc -D__EX
libAxRaw_lflags = -nostdlib
$(eval $(call LIBRARY,libAxRaw))



# Target: Program  format
#format_src =  $(patsubst src/%,%,$(wildcard src/format/*.c)) tests/format.c tests/error.c
format_src =  tests/format.c
format_inc = include/ internal/
format_cflags =  $(std_$(mode)_cflags) -D__C99 -Wno-format
$(eval $(call PROGRAM,format))


# Target: Program  format
files_src =  tests/files.c tests/error.c
files_inc = include/ internal/
files_cflags =  $(std_$(mode)_cflags) -D__C99 -Wno-format
$(eval $(call PROGRAM,files))


alloc_src =  $(patsubst src/%,%,$(wildcard src/alloc/*.c)) tests/alloc.c tests/error.c
alloc_inc = include/ internal/
alloc_cflags =  $(std_$(mode)_cflags) -D__C99
$(eval $(call PROGRAM,alloc))


# Target: Program  format
unix_src = tools/unix_tables.c
unix_inc = 
unix_cflags =  $(std_$(mode)_cflags) 
$(eval $(call PROGRAM,unix))


# ===========================================================================

-include $(MAKE_SCRIPTS_DIR)/utils.mk

