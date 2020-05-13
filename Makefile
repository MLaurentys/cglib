CC = g++

OP1  = -std=c++17 
OP5 = -Wall -Wextra -Wpedantic -Wshadow -pedantic 
OP4 = -Wno-unused-result -Wno-unused-function -Wsequence-point
OP3 = -g -O0

#You can change
CFLAGS  = $(OP1) $(OP2) $(OP3)
#Should NOT change
CFLAGS_ALL = $(CFLAGS)

#auxiliary variables
MKDIR = mkdir -p
OUT_DIR = out
EXEC_NAME = $(OUT_DIR)/game_numbers

#include files
INC_DIR = include
LIB_DIR = ../lib
LIB_OBJ_DIR = ../lib/bin
INC_OBJ_DIR = bin
INCLUDE_T = $(INC_DIR) $(LIB_DIR)
INCLUDE = $(foreach dir, $(INCLUDE_T) $(INC_OBJ_DIR), -I$(dir))
SRC_DIR = src

#objects
INC_OBJ_T = \
game_number_copy.o

LIB_OBJ_T = \


INC_OBJ = $(addprefix $(INC_OBJ_DIR)/, $(INC_OBJ_T))
LIB_OBJ = $(addprefix $(LIB_OBJ_DIR)/, $(LIB_OBJ_T))
default: lib
	$(MKDIR) $(OUT_DIR)
	$(CC) $(CFLAGS_ALL) $(INCLUDE) $(INC_OBJ) $(LIB_OBJ) src/main.cpp -o $(EXEC_NAME)

#compile the library
lib: $(INC_OBJ)

#compile library c files
$(INC_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR) $(INC_OBJ_DIR)
	$(CC) $(CFLAGS_ALL) $(INCLUDE) -c $< -o $@

print-%: ; @echo $* = $($*)

clean:
	rm -rf $(OUT_DIR) 
	rm -rf $(INC_OBJ_DIR) 