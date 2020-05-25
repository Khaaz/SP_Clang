CC=gcc
CFLAGS= -Wall -Wextra -g

EXEC=prog

BUILD_DIR ?= ./build
SRC_DIR ?= ./src

SRCS=$(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: zip
zip:
	zip $(EXEC).zip src/*.c src/*.h

MKDIR_P ?= mkdir -p
