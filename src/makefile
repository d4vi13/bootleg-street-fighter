
# Compiler
CC = gcc

# Directories
SRC_DIR = .
ADDONS_DIR = ./addons
FONT_DIR = ./addons/font
CONFIG_DIR = ./config

# Source files
SRCS = $(SRC_DIR)/core.c $(SRC_DIR)/eventHandler.c $(SRC_DIR)/init.c $(SRC_DIR)/main.c \
       $(FONT_DIR)/font.c

# Object files
OBJS = $(SRC_DIR)/core.o $(SRC_DIR)/eventHandler.o $(SRC_DIR)/init.o $(SRC_DIR)/main.o \
       $(FONT_DIR)/font.o

# Output executable
TARGET = game

# Allegro flags
ALLEGRO_FLAGS = $(shell pkg-config --cflags --libs allegro-5 allegro_font-5 allegro_ttf-5 allegro_image-5 allegro_primitives-5)

# Compiler flags
CFLAGS = -Wall -I$(SRC_DIR) -I$(ADDONS_DIR) -I$(FONT_DIR)

# Linker flags
LDFLAGS = $(ALLEGRO_FLAGS)

# Build rules
all: $(TARGET)

$(SRC_DIR)/core.o: $(SRC_DIR)/core.c $(SRC_DIR)/core.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/eventHandler.o: $(SRC_DIR)/eventHandler.c $(SRC_DIR)/eventHandler.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/init.o: $(SRC_DIR)/init.c $(SRC_DIR)/init.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/mainHeader.h
	$(CC) $(CFLAGS) -c $< -o $@ 


$(FONT_DIR)/font.o: $(FONT_DIR)/font.c $(FONT_DIR)/font.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

