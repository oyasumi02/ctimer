# Makefile (C)
CC = gcc
CFLAGS = -Wall -Iincludes -std=c17

# { FOR WINDOWS COMPILER }
WIN_CC = x86_64-w64-mingw32-gcc
WIN_CFLAGS = -Wall -Iincludes -std=c17

# Directory vars
SRC_DIR = src
OBJ_DIR = obj
OBJ_DIR_WIN = obj_win

# Srcs
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Create object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_WIN =  $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR_WIN)/%.o, $(SRCS))

# Executable Names
TARGET = ctimer
TARGET_WIN = ctimer.exe

# Build program
all: $(TARGET)

# :: BUILD LINUX EXECUTABLE ::
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# :: BUILD WINDOWS EXECUTABLE ::
windows: $(TARGET_WIN)

$(TARGET_WIN): $(OBJS_WIN)
	$(WIN_CC) -static -static-libgcc -static-libstdc++ $(OBJS_WIN) -o $(TARGET_WIN)

$(OBJ_DIR_WIN)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR_WIN)
	$(WIN_CC) $(WIN_CFLAGS) -c $< -o $@

$(OBJ_DIR_WIN):
	mkdir -p $(OBJ_DIR_WIN)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_WIN) $(TARGET) $(TARGET_WIN)