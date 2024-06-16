CXX=g++
CXXFLAGS=-std=c++11 -Werror

SOURCESDEMO= board.cpp catan.cpp tile.cpp player.cpp vertex.cpp edge.cpp demo.cpp
SOURCETEST= test.cpp testCounter.cpp board.cpp catan.cpp tile.cpp player.cpp vertex.cpp edge.cpp

all: demo test
	./demo

demo: $(SOURCESDEMO:.cpp=.o)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: $(SOURCETEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

%.o: %.cpp test.cpp testCounter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test
