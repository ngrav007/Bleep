CXX=g++
CXXFLAGS=-g -Wall -Wextra -Werror -std=c++14
LDFLAGS=-g
SRCDIR=src/


bleep: bleep.o main.o
	$(CXX) $(LDFLAGS) $^ -o $@

main.o: $(SRCDIR)main.cpp $(SRCDIR)bleep.hpp
	$(CXX) -c $<

bleep.o: $(SRCDIR)bleep.cpp
	$(CXX) -c $<

clean:
	rm -f *.o *.out bleep
