.PHONY: all basic_ops advanced_ops clean #

CC = gcc
INC_DIR = include
LIB_DIR = lib
BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

CFLAGS = -I$(INC_DIR)

LDFLAGS = -L$(LIB_DIR) -lmybasic -lmybasic -lmyadvanced -lm

TARGET = $(BIN_DIR)/myapp

STATIC_LIB = $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

all: basic_ops advanced_ops $(TARGET) #

$(TARGET): $(SRC_DIR)/myapp.c $(STATIC_liBS)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(SRC_DIR)/myapp.c -o $(OBJ_DIR)/myapp.o $(CFLAGS)
	$(CC) $(OBJ_DIR)/myapp.o -o $@ $(LDFLAGS)
	@echo "Build comlete: $(TARGET)"

basic_ops: #
	$(MAKE) -C basic_ops

advanced_ops: #
	$(MAKE) -C advanced_ops

clean: #
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/* $(LIB_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
	@echo "Full project clean complete."


