# Makefile for C project with Bison and Flex

# Directories
SRC_DIR = src
GEN_DIR = $(SRC_DIR)/__generated
OBJ_DIR = obj

# Sources and Objects
C_SRC = $(wildcard $(SRC_DIR)/*.c)
C_OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SRC))

BISON_SRC = $(wildcard $(SRC_DIR)/*.y)
BISON_GEN = $(patsubst $(SRC_DIR)/%.y, $(GEN_DIR)/%.tab.c, $(BISON_SRC))

FLEX_SRC = $(wildcard $(SRC_DIR)/*.l)
FLEX_GEN = $(patsubst $(SRC_DIR)/%.l, $(GEN_DIR)/%.yy.c, $(FLEX_SRC))

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
YACC = bison
LEX = flex
YFLAGS = -d
LFLAGS = -l

# Create directories
$(shell mkdir -p $(GEN_DIR) $(OBJ_DIR))

# Default target
all: coal

# Rule for generating Bison files
$(GEN_DIR)/%.tab.c: $(SRC_DIR)/%.y
	$(YACC) $(YFLAGS) -o $@ $<

# Rule for generating Flex files
$(GEN_DIR)/%.yy.c: $(SRC_DIR)/%.l
	$(LEX) $(LFLAGS) -o $@ $<

# Rule to compile C source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking the object files to create the final executable
coal: $(C_OBJ) $(BISON_GEN) $(FLEX_GEN)
	$(CC) $(CFLAGS) -o $@ $^

# Cleanup generated and object files
clean:
	rm -rf $(OBJ_DIR)/*.o $(GEN_DIR)/*.c my_project

# Phony targets
.PHONY: all clean
