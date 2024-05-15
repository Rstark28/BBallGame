#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

class Game {
    
public:

    // Constructors
    Game();
    
    // Destructor
    ~Game();

    void playGame();
    void playPeriod();
    void playPossession();

private:
    
    int numPeriods;
    int periodTime;
    
    int score;
};

#endif // GAME_H
