# Makefile to build the S OS

# Directories
BOOT_DIR = boot
KERNEL_DIR = kernel
BUILD_DIR = build

# Tools
CC = gcc
LD = ld
AS = nasm

# Flags
CFLAGS = -m32 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector
LDFLAGS = -m elf_i386

# Files
BOOT_SRC = $(BOOT_DIR)/boot.s
KERNEL_SRC = $(KERNEL_DIR)/kernel.c
KERNEL_BIN = $(KERNEL_DIR)/kernel.bin
KERNEL_ELF = $(BUILD_DIR)/kernel.elf
ISO = $(BUILD_DIR)/sos.iso

all: $(ISO)

$(ISO): $(KERNEL_BIN)
    @mkdir -p $(BUILD_DIR)
    grub-mkrescue -o $(ISO) $(BOOT_DIR)

$(KERNEL_BIN): $(KERNEL_ELF)
    @mkdir -p $(KERNEL_DIR)
    objcopy -O binary $(KERNEL_ELF) $(KERNEL_BIN)

$(KERNEL_ELF): $(KERNEL_SRC)
    @mkdir -p $(BUILD_DIR)
    $(CC) $(CFLAGS) -c $(KERNEL_SRC) -o $(BUILD_DIR)/kernel.o
    $(LD) $(LDFLAGS) -T $(KERNEL_DIR)/linker.ld -o $(KERNEL_ELF) $(BUILD_DIR)/kernel.o

clean:
    rm -rf $(BUILD_DIR) $(KERNEL_BIN)

.PHONY: all clean
