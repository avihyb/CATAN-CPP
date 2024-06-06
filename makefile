# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Source files
SRCS := board.cpp catan.cpp edge.cpp vertex.cpp player.cpp demo.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable
EXE := demo

# Default target
all: $(EXE)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into executable
$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXE)