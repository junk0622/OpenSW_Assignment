CC = gcc
INC_DIR = include
LIB_DIR = lib
BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

CFLAGS = -I$(INC_DIR)

LDFLAGS = -L$(LIB_DIR) -lmybasic

TARGET = $(BIN_DIR)/myapp

STATIC_LIB = $(LIB_DIR)/libmybasic.a

BASIC_OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o

APP_OBJ = $(OBJ_DIR)/myapp.o

.PHONY: all basic clean

all: $(TARGET)

basic: $(STATIC_LIB)

$(TARGET): $(APP_OBJ) $(STATIC_LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $(APP_OBJ) -o $@ $(LDFLAGS)
	@echo "Executable 'bin/myapp' created."

$(STATIC_LIB): $(BASIC_OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^
	@echo "Static library 'lib/libmybasic.a' created."

$(APP_OBJ): $(SRC_DIR)/myapp.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/* $(LIB_DIR)/* $(BIN_DIR)/*
	@echo "Cleaning up..."

