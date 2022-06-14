CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic
LDXXFLAGS = -lncurses

OBJS = main.o gameboard.o

prog: $(OBJS) # Achtung: Einrücken mit Tabs, nicht mit Leerzeichen!
				$(CXX) $(CXXFLAGS) -o part05 $(OBJS) $(LDXXFLAGS)

%.o: %.cpp
				$(CXX) $(CXXFLAGS) -c $<

clean:
				rm -f prog *.o
