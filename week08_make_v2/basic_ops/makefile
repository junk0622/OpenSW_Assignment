INC_DIR = ../include
LIB_DIR = ../lib
OBJ_DIR = obj
SRC_DIR = src

CC = gcc
CFLAGS = -I$(INC_DIR)
AR = ar
ARFLAGS = rcs

TARGET_LIB = $(LIB_DIR)/libmybasic.a

OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o

.PHONY: all clean

$(TARGET_LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^
	@echo "Created basic_ops library: $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*.o
	@echo "Cleaned basic_ops objects."

