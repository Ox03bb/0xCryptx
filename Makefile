CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./includes
LDFLAGS = 
TARGET = 0xCryptx
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRCS = $(wildcard $(SRC_DIR)/cuda/*.cpp) \
       $(wildcard $(SRC_DIR)/encryption/*.cpp) \
       $(wildcard $(SRC_DIR)/hashing/*.cpp) \
       $(wildcard $(SRC_DIR)/utils/*.cpp) \
       $(SRC_DIR)/main.cpp

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Create directories
$(shell mkdir -p $(OBJ_DIR)/cuda $(OBJ_DIR)/encryption $(OBJ_DIR)/hashing $(OBJ_DIR)/utils)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean

# Run
run: $(TARGET)
	./$(TARGET)
