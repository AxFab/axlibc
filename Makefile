# Makefile

# ifeq ($(MAKE_SCRIPTS_DIR),)
  MAKE_SCRIPTS_DIR = tools
# endif

-include $(MAKE_SCRIPTS_DIR)/settings.mk
-include $(MAKE_SCRIPTS_DIR)/common.mk


# ===========================================================================

system = $(shell uname -sr)
date = $(shell date '+%d %b %Y')

pack_cflags =  -D_DATE_=\"'$(date)'\" -D_OS_FULLNAME_=\"'$(system)'\"

cov_cflags =  --coverage -fprofile-arcs -ftest-coverage
cov_lflags =  -fprofile-arcs

warn_cflags = -Wall -Wextra -Wpointer-arith -Wshadow -Wcast-align -Winline -Wimplicit
# cflags += -fPIC


std_debug_cflags = 			$(pack_cflags) $(warn_cflags) -g -ggdb
std_release_cflags =  	$(pack_cflags) $(warn_cflags) -fPIC -O3

std_debug_cflags = 			-g -ggdb
std_release_cflags =  	-s


# ===========================================================================

glue_f: libaxc
	@objdump $(lib_dir)/libaxc.so -x | grep '*UND*' | \
	 awk '{ print $4 } ' | sort | uniq

check: libaxc libAxRaw format files alloc
	@$(bin_dir)/format
	@$(bin_dir)/files
	@$(bin_dir)/alloc

# Target: Library  libAxStdC
libaxc_src = \
		$(patsubst src/%,%,$(wildcard src/core/*.c)) \
		$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
		$(patsubst src/%,%,$(wildcard src/crypto/*.c)) \
		$(patsubst src/%,%,$(wildcard src/stdio/*.c)) \
		$(patsubst src/%,%,$(wildcard src/format/*.c)) \
		$(patsubst src/%,%,$(wildcard src/stdlib/*.c)) \
		$(patsubst src/%,%,$(wildcard src/time/*.c)) \
		$(patsubst src/%,%,$(wildcard src/string/*.c))
libaxc_inc = include/ internal/
libaxc_cflags = $(std_$(mode)_cflags) -nostdinc -D__C99
libaxc_lflags = -nostdlib -fPIC
$(eval $(call LIBRARY,libaxc))



# Target: Library  libAxRaw
libAxRaw_src = \
		$(patsubst src/%,%,$(wildcard src/core/*.c)) \
		$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
		$(patsubst src/%,%,$(wildcard src/string/*.c)) \
		$(patsubst src/%,%,$(wildcard src/format/*.c)) \
		$(patsubst src/%,%,$(wildcard src/time/*.c)) \
		stdlib/numbers.c \
		tests/error.c
libAxRaw_inc = include/ internal/
libAxRaw_cflags = $(std_$(mode)_cflags) -nostdinc -D__EX
libAxRaw_lflags = -nostdlib
$(eval $(call LIBRARY,libAxRaw))



# Target: Program  format
#format_src =  $(patsubst src/%,%,$(wildcard src/format/*.c)) tests/format.c tests/error.c
format_src =  tests/format.c tests/error.c \
							$(patsubst src/%,%,$(wildcard src/core/*.c)) \
							$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
							$(patsubst src/%,%,$(wildcard src/crypto/*.c)) \
							$(patsubst src/%,%,$(wildcard src/stdio/*.c)) \
							$(patsubst src/%,%,$(wildcard src/format/*.c)) \
							$(patsubst src/%,%,$(wildcard src/string/*.c))
format_inc = include/ internal/
format_cflags = $(std_$(mode)_cflags) -D__C99 -Wno-format
format_lflags = $(std_$(mode)_lflags)
$(eval $(call PROGRAM,format))


# Target: Program  format
files_src =   tests/files.c tests/error.c \
							$(patsubst src/%,%,$(wildcard src/core/*.c)) \
							$(patsubst src/%,%,$(wildcard src/alloc/*.c)) \
							$(patsubst src/%,%,$(wildcard src/crypto/*.c)) \
							$(patsubst src/%,%,$(wildcard src/format/*.c)) \
							$(patsubst src/%,%,$(wildcard src/string/*.c))
files_inc = include/ internal/
files_cflags = $(std_$(mode)_cflags) $(cov_cflags) -D__C99
files_lflags = $(std_$(mode)_lflags) $(cov_lflags) $(lib_dir)/libaxc.a
$(eval $(call PROGRAM,files))


alloc_src =  $(patsubst src/%,%,$(wildcard src/alloc/*.c)) tests/alloc.c tests/error.c
alloc_inc = include/ internal/
alloc_cflags = $(std_$(mode)_cflags) $(cov_cflags) -D__C99
alloc_lflags = $(std_$(mode)_lflags) $(cov_lflags)
$(eval $(call PROGRAM,alloc))


# Target: Program  format
unix_src = tools/unix_tables.c
unix_inc =
unix_cflags =  $(std_$(mode)_cflags)
$(eval $(call PROGRAM,unix))

# Target: Program  format
unixf_src = tools/unix_tables_func.c
unixf_inc =
unixf_cflags =  $(std_$(mode)_cflags)
$(eval $(call PROGRAM,unixf))


# ===========================================================================

-include $(MAKE_SCRIPTS_DIR)/utils.mk

