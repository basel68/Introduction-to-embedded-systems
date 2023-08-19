#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
Platform = MSP432
BASENAME = c1m2
# Architectures Specific Flags
ifeq ($(Platform),MSP432)
	LINKER_FILE = ../msp432p401r.lds 
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
else

	CPU = x86_64
	ARCH = $(shell arch)
endif



# Compiler Flags and Defines
ifeq ($(Platform),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(BASENAME).map $(LINKER_FILE) 
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -O0 -g -std=c99
	CPPFLAGs = -M -MF test.d
	DEFINEFLAG = -DPLATFORM=$(Platform)
else	
	CC = gcc
# 	LD = 
	LDFLAGS = -Wl,-Map=$(BASENAME).map
	CFLAGS = -Wall -Werror -O0 -g -std=c99
	CPPFLAGs = -M -MF test2.d
	DEFINEFLAG = -DPLATFORM=$(Platform)
endif

OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.s)
PPS:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
OUTS:= $(SOURCES:.c=.out)


%.i:%.c
	$(CC) $(DEFINEFLAG) $(CPPFLAGs) $(INCLUDES) -E $< -o $@ 

%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGs) $(INCLUDES) -S $<  -o $@ 

%.o:%.c
	$(CC) $(DEFINEFLAG) $(CFLAGs) -c $(INCLUDES) $< -o $@  


.PHONY: compile-all
compile-all: $(SOURCES)

	$(CC) $(DEFINEFLAG) $(CFLAGS) $(INCLUDES) -c $(SOURCES) -o $(OBJS)

.PHONY: build
build: $(OUTS)
$(OUTS):$(SOURCES)					
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o c1m2.out $^
	size c1m2.out


.PHONY: clean
clean:

	rm -f *.i *.d *.map *.s *.out *.o
