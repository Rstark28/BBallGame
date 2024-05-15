
#include <cassert>
#include "Player.h"

void test() {

    for (int i = 0; i < 3; i++) {
        Player newPlayer("Point Guard");
        newPlayer.generatePlayerStats();
        newPlayer.printPlayer();
    }
    for (int i = 0; i < 3; i++) {
        Player newPlayer("Shooting Guard");
        newPlayer.generatePlayerStats();
        newPlayer.printPlayer();
    }
    for (int i = 0; i < 3; i++) {
        Player newPlayer("Small Forward");
        newPlayer.generatePlayerStats();
        newPlayer.printPlayer();
    }
    for (int i = 0; i < 3; i++) {
        Player newPlayer("Power Forward");
        newPlayer.generatePlayerStats();
        newPlayer.printPlayer();
    }
    for (int i = 0; i < 3; i++) {
        Player newPlayer("Center");
        newPlayer.generatePlayerStats();
        newPlayer.printPlayer();
    }
}