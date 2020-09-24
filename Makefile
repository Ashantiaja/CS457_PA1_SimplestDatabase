# Author   @Ash Yveth Cudiamat
# Date Due 09 24 2020

TARGET = PA1
SRC_PATH = srcs/
BUILD_PATH = build/
HEADERS = database.h table.h column.h
SRCS = database.cpp table.cpp column.cpp main.cpp
OBJECTS := $(patsubst %.cpp, %.o, $(SRCS))

# Generate final paths for headers, srcs, objects
H := $(addprefix $(SRC_PATH), $(HEADERS))
S := $(addprefix $(SRC_PATH), $(SRCS))
O := $(addprefix $(BUILD_PATH), $(OBJECTS))
T := $(addprefix $(BUILD_PATH), $(TARGET))

CC = g++
CC_FLAGS = -std=c++11

.PHONY: default all clean

# Rule to defer make all to TARGET rule below
all: $(T)

# Rule to compile object files
build/%.o: srcs/%.cpp $(H)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(T): $(O)
	@echo "================"
	@echo "Linking files."
	$(CC) $(CC_FLAGS) $(O) -o $@
	@echo "================"
	@echo $(TARGET) " is available in " $(BUILD_PATH)

clean:
	-rm -f $(O)
	-rm -f $(T)

# DEBUG rule to output variables
debugVar:
	@echo "Headers: " $(H)
	@echo "Sources: " $(S)
	@echo "Objects: " $(O)
	@echo "Target: "  $(T)
