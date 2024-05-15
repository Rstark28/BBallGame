CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3

# game: main.o
#		$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# main.o: main.cpp
# 		$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.cpp Game.h
		$(CXX) $(CXXFLAGS) -c Game.cpp

Player.o: Player.cpp Player.h
		$(CXX) $(CXXFLAGS) -c Player.cpp

unit_test: unit_test_driver.o Game.o Player.o
		$(CXX) $(CXXFLAGS) $^

clean:
		rm *.o *~ a.out

