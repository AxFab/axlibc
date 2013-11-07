# Makefile - C Projects rules
#       @author         F.Bavent <fabien.bavent@gmail.com>
#       @repository     https://github.com/AxFab/unixtools.git
# 		@license        zlib License
# ---------------------------------------------------------------------------
# ---------------------------------------------------------------------------
# Copyright (c) 2013 <Fabien Bavent>
# 
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
# 
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
# 
#    1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
# 
#    2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 
#    3. This notice may not be removed or altered from any source
#    distribution.
# ---------------------------------------------------------------------------
# This makefile is design to work using the following project hierarchie:
#
#     ./src/[FRAGMENT]/*.c          - c source files
#     ./src/[FRAGMENT]/*.h    	    - local headers
#     ./include/*.h    			    - API headers (allow sub-folders)
#     ./units/[TEST].c    		    - unit test source file (1 per exec)
#
# NOTE: 
#    I advise one unit-test per fragment.
#    Program take extention '.xe' and unit-tests '.ut' to allow using glob.
#    Use the mode to separate your compilation mode='debug|coverage|cross_x64'
#    Install make a copy ./bin and ./lib to $preffix/{bin,lib}
#      set preffix first!
#
#  This makefile can be used to compile many different projects, until your
#  project follow the correct hierachie. It's not recursive and 
# ---------------------------------------------------------------------------

# ===========================================================================
# Helper Message --------------------------------
help:
	@ echo 'Usage: make <target> [options]'
	@ echo ''
	@ echo 'Targets:'
	@ echo '   make <fragment> 	Compile a fragment and launch unit-tests'
	@ echo '   make check      	Build all unit-tests and run them'
	@ echo ''
	@ echo '   make clean      	Remove temporary files'
	@ echo '   make mrproper   	Remove generated files'
	@ echo '   make destroy       	Remove generated files and auto-makefiles'
	@ echo ''
	@ echo '   make api        	Move header files'
	@ echo '   make install    	Move binary files'
	@ echo '   make install-dev	Move binary and header files'
	@ echo ''
#	@ echo '   make rpm        	Create rpm package'
	@ echo '   make help       	Display this help'
	@ echo ''
	@ echo '   make brick       	Generate all intermediate makefile rules'
	@ echo ''
	@ echo 'Options:'
	@ echo '   variable   value   purpose'
	@ echo '   preffix    .       move the directories: bin, obj, lib...'
	@ echo '   mode       .       split 'obj' to recompile when changing FLAGS'
# ===========================================================================
	
# ===========================================================================
# Common Variables ------------------------------

# Directories
arch = $(shell uname -p)
preffix = .
mode = .
bino = $(preffix)/bin
objo = $(preffix)/$(mode)/obj
libo = $(preffix)/lib
varo = $(preffix)/var
inco = $(preffix)/include

# Verbose
V=@
VV=@
VVV=@

# Default Programs
CC=gcc
LD=gcc
AR=ar rc

CFLAGS = -g -ggdb3  -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable
CFLAGS += -I$(inco)
LFLAGS = 
LFLAGS += -L$(libo)

# Add store(s)
CFLAGS += $(foreach st, $(store), -I$(st)/include)
LFLAGS += $(foreach st, $(store), -L$(st)/lib)

dirs_all 	= $(wildcard src/*)
units_all	= $(wildcard units/*.c:units/%.c=$(varo)/%.ut)

# ===========================================================================

# ===========================================================================
# Common Rules ----------------------------------
# TODO - custom CFLAGS (by fragment)!!

$(objo)/%.o: %.c $(objo)/%.d
	$(VVV) mkdir -p $(dir $@)
	$(V) $(CC) -c -o $@ $< $(CFLAGS)

$(objo)/%.d: %.c
	$(VVV) mkdir -p $(dir $@)
	$(V) $(CC) -M -o $@ $< $(CFLAGS)


$(libo)/%.so: 
	$(VVV) mkdir -p $(dir $@)
	$(V) $(LD) -shared -o $@ $^ $(LFLAGS) \
		$($(patsubst lib%.so,%, $(notdir $@))_lflags)
	$(V) $(AR) $(@:%.so=%.a) $^	

$(bino)/%.xe: 
	$(VVV) mkdir -p $(dir $@)
	$(V) $(LD) -o $@ $^ $(LFLAGS) \
		$($(patsubst %.xe,%, $(notdir $@))_lflags)

$(varo)/%.ut: $(objo)/units/%.o
	$(VVV) mkdir -p $(dir $@)
	$(V) $(LD) -o $@ $^ $(LFLAGS) $(ld_check) $(libs_check) \
		$($(patsubst %.ut,%, $(notdir $@))_lflags)

# ===========================================================================

# ===========================================================================
# Cleaning Rules --------------------------------
clean:
	$(VV) rm -rf $(objo)
	
mrproper: clean
	$(VV) rm -rf $(bino)
	$(VV) rm -rf $(libo)
	
destroy: mrproper
	$(VV) rm -rf $(varo)
	
# Delivery Rules --------------------------------
api:
	$(VVV) mkdir -p $(inco)
	$(VV) cp -r include/* $(inco)
	
install: all
	$(VVV) mkdir -p $(bino)
	$(VVV) mkdir -p $(libo)
	$(VV) cp -r bin/* $(bino)
	$(VV) cp -r lib/* $(libo)

install-dev: install api
	
# Quality Rules ---------------------------------

check: $(units_all)
	$(V) : $(foreach ut, $^, $(shell ut))

web: Doxyfile
	$(VV) lcov -c -d . -o coverage.lcov
	$(VV) pmccabe src/*/* > complexity.mccabe
	$(VV) doxygen
	$(VV) python build/code.py > lib.js
	$(VV) cp lib.js ../libweb/frag.min.js

Doxyfile:
# TODO generate the doxygene config file

# ===========================================================================

# ===========================================================================
# Dependancies check ----------------------------

src_all     = $(foreach dir,$(dirs_all),$(wildcard $(dir)/*.c)) \
                $(wildcard units/*.c)
dep_all	    = $(src_all:%.c=$(objo)/%.d)

 -include $(dep_all)

# ===========================================================================

# ===========================================================================
# Template --------------------------------------
define LIBRARY
$(libo)/lib$(1).so: $(patsubst %.c, $(objo)/%.o, \
	$(foreach dir, $($(1)_fragments:%=src/%), \
		$(wildcard $(dir)/*.c)))
$(1):$(libo)/lib$(1).so
endef

define PROGRAM
$(bino)/$(1).ex: $(patsubst %.c, $(objo)/%.o, \
	$(foreach dir, $($(1)_fragments:%=src/%), \
		$(wildcard $(dir)/*.c)))
$(1):$(bino)/$(1).ex
endef

define UNITTEST
$(varo)/$(1).ut: $(patsubst %.c, $(objo)/%.o, \
	$(foreach dir, $($(1)_fragments:%=src/%), \
		$(wildcard $(dir)/*.c)))
$(1):$(varo)/$(1).ut
endef

# ===========================================================================

# EOF --
