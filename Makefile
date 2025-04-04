CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS =

# Build the main executable.
all: main

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o $(LDFLAGS)

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o main
