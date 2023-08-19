include sources.mk

# Platform Overrides
platform=HOST
pf=../include/common/platform.h

# General Flags for all platforms
GEN_FLAGS = \
			-Wall \
			-Werror \
			-g \
			-O0 \
			-std=c99

TARGET = c1m2

# Platform Dependant Variables
ifeq ($(platform),MSP432)
	# MSP432 dependant build options
	CPU = cortex-m4
	ARCH = armv7e-m

	SOURCES+= 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES+= 	-I ../include/CMSIS/ \
				-I ../include/msp432/

	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# Linker Flags
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
	# Compiler Flags
	CFLAGS = 	$(GEN_FLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)


else
	# @echo Host platform detected
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size

endif

PREP = $(SOURCES:.c=.i)	# Preprocessor Files
DEPS = $(SOURCES:.c=.d)	# Dependancy Files
ASMS = $(SOURCES:.c=.asm)	# Assembly Files
OBJS = $(SOURCES:.c=.o)	# Object files

.PHONY: compile-all build clean

# Compile all object files and link into a final executable.
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	
# Generate Preprocesed output of all c-program implementation files (use the -E flag)
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
%.asm: %.c
	$(CC) -S $<  $(CFLAGS) $(CPPFLAGS) 

# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $<  $(CFLAGS) $(pf) $(CPPFLAGS)  

# Generate Dependancy files for each Source File
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) 

# Compile all object files, but DO NOT link.
compile-all: $(OBJS)

clean:
	# This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
	@echo Removing all built files
	rm -f *.out *.map *.o *.asm *.i