CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: stacker

stacker: main.o stacker.o
	$(CXX) $(CXXFLAGS) main.o stacker.o -o stacker

main.o: main.cpp stacker.h
	$(CXX) $(CXXFLAGS) -c main.cpp

stacker.o: stacker.cpp stacker.h
	$(CXX) $(CXXFLAGS) -c stacker.cpp

clean:
	rm -f *.o stacker