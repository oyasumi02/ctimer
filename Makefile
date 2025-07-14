# Makefile (C)
CC = gcc

CFLAGS = -Wall -Iincludes -std=c17

# Search for all .cpp files in src
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Convert .cpp files into object files
OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Output exec
TARGET = ctimer

# Build program
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

# Compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object dir if does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
