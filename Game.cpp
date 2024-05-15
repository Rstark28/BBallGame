#include "Game.h"

Game::Game() {

    srand(static_cast<unsigned int>(time(nullptr)));

    numPeriods = 4;
    periodTime = 7200;
    score = 0;
}

Game::~Game() {

}

void Game::playGame() {

    while (numPeriods > 0)
        playPeriod();
    
    std::cout << score << std::endl;
}

void Game::playPeriod() {

    while (periodTime > 0)
        playPossession();

    numPeriods--;
}

void Game::playPossession() {

    periodTime -= rand() % 24; 
    score += 2;

}