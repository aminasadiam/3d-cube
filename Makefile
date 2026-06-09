BUILD_NAME = 3d-cube
BUILD_PATH = build

CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/main.c src/input.c

.PHONY: build run clean

build:
	@mkdir -p $(BUILD_PATH)
	@$(CC) $(CFLAGS) -o $(BUILD_PATH)/$(BUILD_NAME) $(SRC) -lraylib

run:
	@./$(BUILD_PATH)/$(BUILD_NAME)

clean:
	@rm -rf $(BUILD_PATH)