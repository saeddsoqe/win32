# ###*B*###
# Erika Enterprise, version 3
# 
# Copyright (C) 2017 - 2018 Evidence s.r.l.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at
# your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License, version 2, for more details.
# 
# You should have received a copy of the GNU General Public License,
# version 2, along with this program; if not, see
# <https://www.gnu.org/licenses/old-licenses/gpl-2.0.html >.
# 
# This program is distributed to you subject to the following
# clarifications and special exceptions to the GNU General Public
# License, version 2.
# 
# THIRD PARTIES' MATERIALS
# 
# Certain materials included in this library are provided by third
# parties under licenses other than the GNU General Public License. You
# may only use, copy, link to, modify and redistribute this library
# following the terms of license indicated below for third parties'
# materials.
# 
# In case you make modified versions of this library which still include
# said third parties' materials, you are obligated to grant this special
# exception.
# 
# The complete list of Third party materials allowed with ERIKA
# Enterprise version 3, together with the terms and conditions of each
# license, is present in the file THIRDPARTY.TXT in the root of the
# project.
# ###*E*###

## \file	ee_arch_compiler_gcc.mk
## \brief	Architecture GCC Compiler.
##
## This makefile contains the list of GCC Compiler Rules for a specific
## Architecture in Erika Enterprise.
##
## \author	Ida Savino
## \date	2018

##
## Compiler related options
##

# BINDIR is the directory of assembler, linker, ... distributed with AVR Tools
#JAILHOUSE_X86_64_TOOLS ?= /usr
#BINDIR := $(call native_path,$(JAILHOUSE_X86_64_TOOLS))/bin

# MP: All GCC native compilers are available from PATH, BINDIR not needed
# MP: BINDIR variable, (if not empty), must end with separator
BINDIR :=

# ALLINCPATH is a colon separated list of directories for source file searching
# -I = adds directories to the source file search path (for both gcc and gas)
# we consider the ee pkg directory and the application dir
# we also consider the current directory because the app could be compiled
# from the config files generated from eclipse...
#ALLINCPATH += \
#$(foreach d,$(INCLUDE_PATH),$(addprefix -I,$(call native_path,$d)))

#modified x86_64-unknown-elf- removed 
Win32_GCCPREFIX ?= 

#@JAILHOUSE_SYSTEM_HEADERS ?= $(shell $(X86_64_GCCPREFIX)gcc -print-file-name=include) # /usr/lib/gcc/aarch64-linux-gnu/5/include

#ALLINCPATH += -isystem $(JAILHOUSE_SYSTEM_HEADERS)\
# $(foreach d,$(INCLUDE_PATH),$(addprefix -I,$d))

ALLINCPATH += $(foreach d,$(INCLUDE_PATH),$(addprefix -I,$d))


EE_OBJDUMP ?= $(BINDIR)$(Win32_GCCPREFIX)objdump

# GNUPro compilers
EE_LINK ?= $(BINDIR)$(Win32_GCCPREFIX)gcc

OS_EE_AS ?= $(BINDIR)$(Win32_GCCPREFIX)gcc

EE_CC ?= $(BINDIR)$(Win32_GCCPREFIX)gcc

EE_CXX ?= $(BINDIR)$(Win32_GCCPREFIX)g++

OS_EE_AR ?= $(BINDIR)$(Win32_GCCPREFIX)ar

EE_NM ?= $(BINDIR)$(Win32_GCCPREFIX)nm

EE_OBJCOPY ?= $(BINDIR)$(Win32_GCCPREFIX)objcopy

EE_SIZE ?= $(BINDIR)$(Win32_GCCPREFIX)size

## OPT_CC are the options for X86_64 C compiler invocation
# removed: -nostdinc -Werror, added -mno-red-zone 
#modified m64 to m32
OPT_CC += -c -m32 -fno-pie -Wall -Wstrict-prototypes -mno-red-zone             \
-Wtype-limits -Wmissing-declarations -Wmissing-prototypes -fno-strict-aliasing \
-fno-pic -fno-common -fno-stack-protector



ifeq ($(or	\
    $(and $(call iseeopt, OS_EE_BUILD), $(call iseeopt, OS_EE_BUILD_DEBUG)),	    \
    $(and $(call iseeopt, OS_EE_APP_BUILD), $(call iseeopt, OS_EE_APP_BUILD_DEBUG)) \
), yes)
OPT_CC += -g3 -save-temps=obj
else
OPT_CC += -fomit-frame-pointer
endif

# Specific option from the application makefile
OPT_CC += $(CFLAGS)

## OPT_CXX are the options for X86_64 C++ compiler invocation
# removed: -nostdinc -Werror -Wstrict-prototypes -Wmissing-prototypes,m64
# added -mno-red-zone -fno-exceptions
OPT_CXX += -c -m64 -fno-pie -Wall -mno-red-zone    \
-Wtype-limits -Wmissing-declarations -fno-strict-aliasing \
-fno-pic -fno-common -fno-stack-protector -fno-exceptions
ifeq ($(or	\
    $(and $(call iseeopt, OS_EE_BUILD), $(call iseeopt, OS_EE_BUILD_DEBUG)),	    \
    $(and $(call iseeopt, OS_EE_APP_BUILD), $(call iseeopt, OS_EE_APP_BUILD_DEBUG)) \
), yes)
OPT_CXX += -g3 -save-temps=obj
else
OPT_CXX += -fomit-frame-pointer
endif
# Specific option from the application makefile
OPT_CXX += $(CFLAGS) $(CXXFLAGS)

## OS_EE_AS_OPT are the options for X86_64 assembler invocation
#modified m64 replaced by m32
OS_EE_AS_OPT = -c -m64 -Werror -nostdinc -fno-pie -Wall -Wstrict-prototypes    \
-Wtype-limits -Wmissing-declarations -Wmissing-prototypes -fno-strict-aliasing \
-fno-pic -fno-common -fno-stack-protector -mno-red-zone
ifeq ($(or	\
    $(and $(call iseeopt, OS_EE_BUILD), $(call iseeopt, OS_EE_BUILD_DEBUG)),	    \
    $(and $(call iseeopt, OS_EE_APP_BUILD), $(call iseeopt, OS_EE_APP_BUILD_DEBUG)) \
), yes)
OS_EE_AS_OPT += -g3 -save-temps=obj
else
OS_EE_AS_OPT += -fomit-frame-pointer
endif
OS_EE_AS_OPT += $(ASFLAGS)

# OS_EE_AR_OPT represents the options for avr linker invocation
ifeq	($(call iseeopt, OS_EE_VERBOSE), yes)
OS_EE_AR_OPT = $(subst $(OS_EE_SPACE),,csv $(subst v,,$(ARFLAGS)))
else	# OS_EE_VERBOSE
OS_EE_AR_OPT = $(subst v,,$(subst $(OS_EE_SPACE),,cs $(ARFLAGS)))
endif	# OS_EE_VERBOSE
#removed we don't have linker 
#OSEE_LINKER_SCRIPT ?= $(OS_EE_MK_BASE_DIR)/ee_x86_64_linker.lds


# OPT_LINK represents the options for avr linker invocation
#OPT_LINK += -Wl,-Map=$(TARGET_NAME).map -Os -Wl,--gc-sections -Wl,-zmax-page-size=0x1000 -Wl,--build-id=none -static -nostdlib -T $(OSEE_LINKER_SCRIPT)
#modified linker part is removed and -no-pie ,--no-dynamic-linker are added
OPT_LINK += -Wl,-Map=$(TARGET_NAME).map -Os -Wl,--gc-sections -Wl,-n -no-pie -Wl,--build-id=none -static -nostartfiles,--no-dynamic-linker 
ifeq	($(call iseeopt, OS_EE_VERBOSE), yes)
OPT_LINK += -Wl,--verbose
endif
OPT_LINK += $(LDFLAGS)

ifeq ($(call iseeopt, OS_EE_BUILD), yes)
OS_EE_DEFS_AS	+= -DOS_EE_BUILD
OS_EE_DEFS_CC	+= -DOS_EE_BUILD
OS_EE_DEFS_CXX	+= -DOS_EE_BUILD
endif

# Automatic dependency generation
ifeq ($(call iseeopt, OS_EE_NO_DEPS), yes)
OS_EE_DEP_OPT =
OS_EE_MK_DEPS =
else	# OS_EE_NO_DEPS
# Create dependency for all headers, and add a target for each header
OS_EE_DEP_OPT = -MP -MMD -MF $(call native_path,$(subst .o,.d_tmp,$(@)))
ifeq ($(call iseeopt, OS_EE_RTD_BUILD_ENV_CYGWIN), yes)
# Dependencies on Windows need path translation and quote remotion
OS_EE_MK_DEPS = sed -e 's_\\\(.\)_/\1_g' \
	-e 's_\<\([a-zA-Z]\):/_/cygdrive/\l\1/_g' < $1_tmp > $1 && rm $1_tmp
else	# OS_EE_RTD_BUILD_ENV_CYGWIN
OS_EE_MK_DEPS = mv $1_tmp $1
endif	# OS_EE_RTD_BUILD_ENV_CYGWIN
endif	# OS_EE_NO_DEPS

# Erika Library.
ERIKALIB = $(ERIKALIB_NAME).a

## OPT_LIBS is used to link additional libraries (e.g., for C++ support)
# the EE library is built in the current directory
ifeq ($(call iseeopt, OS_EE_BUILD), yes)
OPT_LIBS += -l$(EELIB) -L .
LIBDEP += lib/$(ERIKALIB)
else	# OS_EE_BUILD
OPT_LIBS += -L $(call short_native_path,$(abspath $(OS_EE_LIB_BASE_DIR)))
OPT_LIBS += -Wl,--start-group -l$(EELIB) -lc $(LIBS) -Wl,--end-group
LIBDEP += $(OS_EE_LIB_BASE_DIR)/lib$(EELIB).a 
endif	# OS_EE_BUILD

# Define the TARGET
#modfied replaced erika by erika_Win32
TARGET_NAME ?= erika_Win32

# Add application file to dependencies
ifneq ($(call iseeopt, OS_EE_BUILD), yes)
#modified replaced (TARGET_NAME).bin by (TARGET_NAME).exe
export APP_TARGETS := 	$(TARGET_NAME).exe $(TARGET_NAME).dump
$(info APP_TARGETS=$(APP_TARGETS))
endif	# !OS_EE_BUILD
