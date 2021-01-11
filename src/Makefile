CC = g++
CFLAG = -coverage -pthread -Wwrite-strings
CFLAG += -Wall -g

TARGET_DIR = $(CURDIR)

TARGET_SRC = $(TARGET_DIR)/src
TARGET_OBJ = main.o

TARGET_INC  = -I$(TARGET_DIR)/inc/linkedList.h
TARGET_INC += -I$(TARGET_DIR)/inc/printLog.h
TARGET_INC += -I$(TARGET_DIR)/inc/sort.h
TARGET_INC += -I$(TARGET_DIR)/inc/fileHandler.h

PROJ_SRC  = $(TARGET_SRC)/main.cpp
PROJ_SRC += $(TARGET_SRC)/linkedList.cpp
PROJ_SRC += $(TARGET_SRC)/printLog.cpp
PROJ_SRC += $(TARGET_SRC)/sort.cpp
PROJ_SRC += $(TARGET_SRC)/fileHandler.cpp

PROJ_OBJ = main.o

OBJS = $(TARGET_OBJ)

#################
all: $(PROJ_OBJ)

$(PROJ_OBJ): $(PROJ_SRC)
	$(CC) $(CFLAG) $(TARGET_INC) $^ -o $@

clean:
	rm -f *.o *.gcda *.gcno