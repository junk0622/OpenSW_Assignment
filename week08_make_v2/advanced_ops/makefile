INC_DIR = ../include
LIB_DIR = ../lib
OBJ_DIR = obj
SRC_DIR = src

CC = gcc
CFLAGS = -I$(INC_DIR)
AR = ar
ARFLAGS = rcs

TARGET_LIB = $(LIB_DIR)/libmyadvanced.a

OBJS = $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o

.PHONY: all clean

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^
	@ehco "Created advanced_ops library: $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*.o
	@echo "Cleaned advanced_ops objects."

