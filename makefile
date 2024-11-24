# Compiler and flags
CC = g++
CFLAGS = -g -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Executable
TARGET = $(BIN_DIR)/test_shell.exe

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(OBJ_FILES) -o $@

# Compile each source file to an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create the bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up build and bin directories
clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/test_shell.exe
