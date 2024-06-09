CXX=g++
CXXFLAGS=-std=c++11 -Werror

SOURCESDEMO= board.cpp catan.cpp tile.cpp player.cpp vertex.cpp edge.cpp demo.cpp

all: demo
	./demo

demo: $(SOURCESDEMO:.cpp=.o)
	$(CXX) $(CXXFLAGS) $^ -o demo

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo
