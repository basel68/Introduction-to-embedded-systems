#------------------------------------------------------------------------------
# This fie is the Makefile based on the C1M2 & C1M1 module in embedded software course in
# Coursera. It performs the build process management
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 1. %.i
# 2. %.asm
# 3. %.o
# 4. compile-all
# 5. build_stats_o
# 6. clean
#
# Platform Overrides:
#      MSP432, HOST
#------------------------------------------------------------------------------

include sources.mk

TEST_CASE1 = test_1
BASENAME = c1m4
TARGET = $(BASENAME).out
RM = rm -rf
CC = gcc
LD = ld

CFLAGS   = -Wall -Werror -g -O0 -std=c99 -MD
LDFLAGS  = -Wl,-Map=$(BASENAME).map 	
OBJDUMP  = objdump
SIZE     = size

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
FLOAT_ABI = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	DUMP = objdump
	SIZE = size
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -MD
	# etc
else
	CC = arm-none-eabi-gcc
	DUMP = arm-none-eabi-objdump
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 -MD
	# etc
endif

OBJS = $(SOURCES:.c=.o)

%.o: %.c 
	@echo 'objects created'
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -D$(PLATFORM) -D$(COURSE) -DVERBOSE 
	
%.i : %.c 
	@echo 'preprocessors created'
	$(CC) $(CFLAGS) $(INCLUDES) -E $< -o $@ -D$(PLATFORM) -D$(COURSE) -DVERBOSE 

%.asm : %.c 
	@echo 'asm created'
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@ -D$(PLATFORM) -D$(COURSE) -DVERBOSE

%.s : %.out 
	@echo 's created'
	$(DUMP) -S -D $< -D$(PLATFORM) -D$(COURSE)

# do not link
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: all
all: $(TARGET)

# link with dump
$(TARGET): compile-all
	@echo 'compile all'
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ -D$(PLATFORM) -D$(COURSE) -DVERBOSE
	$(SIZE) $@

#test 
.PHONY: build_stats_o
build_stats_o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_FOLDER)/stats.c -o $(SRC_FOLDER)/stats.o


.PHONY: clean
clean: 
	$(RM) $(SRC_FOLDER)/*.o $(SRC_FOLDER)/*.d $(SRC_FOLDER)/*.out *.map *.exe *.out

.PHONY: run
run:
	$(TARGET_FOLDER)/$(TARGET)
