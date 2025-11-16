# 매크로 정의
CC = gcc
CFLAGS = -fPIC -Iinclude
LDFLAGS = -L$(shell pwd)/lib
LDLIBS = -lmyops -lm

# 디렉토리 정의
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# 소스 및 오브젝트 파일 정의
OPS_SRCS = $(wildcard $(SRC_DIR)/my*.c)
OPS_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/myapp.c, $(OPS_SRCS)))
APP_SRC = $(SRC_DIR)/myapp.c
APP_OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(APP_SRC))

# 라이브러리 및 실행 파일 타겟 정의
LIB_TARGET = $(LIB_DIR)/libmyops.so.1.0
TARGET = $(BIN_DIR)/myapp

.PHONY: all clean

# 기본 타겟 (all)
all: $(TARGET)

# 최종 실행 파일 생성 규칙
$(TARGET): $(APP_OBJ) $(LIB_TARGET)
	$(CC) $(APP_OBJ) -o $(TARGET) -Wl,-rpath=$(LDFLAGS) $(LDFLAGS) $(LDLIBS)

# 공유 라이브러리 생성 규칙
$(LIB_TARGET): $(OPS_OBJS)
	$(CC) -shared -Wl,-soname,libmyops.so.1 -o $(LIB_TARGET) $(OPS_OBJS)
	ln -sf libmyops.so.1.0 $(LIB_DIR)/libmyops.so.1
	ln -sf libmyops.so.1 $(LIB_DIR)/libmyops.so

# 오브젝트 파일 생성 규칙
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean 규칙
clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/libmyops.so* $(BIN_DIR)/$(TARGET)