CXX=g++
CXXFLAGS=-std=c++11 -Wall -Werror -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: main.o Base.o Unit.o Playground.o Warrior.o Archer.o Trebuchet.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	make clean

.PHONY: run clean

run: main
	./$<

clean:
	rm -f *.o *~ core
