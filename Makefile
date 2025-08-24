# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source and object files
SRC = src/SudokuBoard.cpp \
      src/SudokuGame.cpp \
      src/SudokuGenerator.cpp \
      src/SudokuSolver.cpp \
      main.cpp

OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET = SudokuProject

# Default target
all: $(TARGET)

# Link objects into final executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET) 