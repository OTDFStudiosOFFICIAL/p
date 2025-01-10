# Toolchain
CC = powerpc-eabi-gcc
CFLAGS = -O2 -mcpu=750 -meabi -mhard-float -Wall -I$(PORTLIBS)/include
LDFLAGS = -L$(PORTLIBS)/lib -lwut -lm
BUILD_DIR = build
TARGET = $(BUILD_DIR)/P.elf

# Source and Object files
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Build rules
all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR)
