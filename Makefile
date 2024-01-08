# Makefile by Dylan

# Compiler
CC = arm-none-eabi-gcc

# Compiler flags
CFLAGS = -mthumb -mcpu=cortex-m3 -std=c99 -Wall -Wextra -g
CFLAGS += -mlittle-endian -mthumb-interwork
CFLAGS += -mfloat-abi=soft
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -Iinc      # Include directory

# Linker flags
LDFLAGS		+= --static -nostartfiles
LDFLAGS		+= -T stm32f103_linker.ld
LDFLAGS		+= -mthumb -mcpu=cortex-m3 -ggdb3
LDFLAGS		+= -Wl,-Map=mappy.map -Wl,--cref
LDFLAGS		+= -Wl,--gc-sections

# Source files
SRCS = $(wildcard src/*.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Output binary

TARGET = firmware.elf
MAPFILE = mappy.map

# OpenOCD settings
OPENOCD_INTERFACE = stlink
OPENOCD_TARGET = stm32f1x

# Flash command
FLASH_CMD = openocd -f interface/$(OPENOCD_INTERFACE).cfg -f target/$(OPENOCD_TARGET).cfg -c "program $(TARGET) verify reset exit"
DBUG_CMD = openocd -f interface/$(OPENOCD_INTERFACE).cfg -f target/$(OPENOCD_TARGET).cfg
GDB_CMD = gdb-multiarch -q -x tools/gdb_init.gdb build/firmware.elf

.PHONY: all clean flash debug gdb

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	mv $(TARGET) $(MAPFILE) build/
	

clean:
	rm -f $(OBJS) build/$(TARGET) build/$(MAPFILE)

flash: $(TARGET)
	$(FLASH_CMD)

debug: $(TARGET)
	$(DBUG_CMD)

gdb: $(TARGET)
	$(GDB_CMD)