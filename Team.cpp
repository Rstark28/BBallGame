#include "Team.h"
#include "PlayerArch.cpp"

Team::Team() {

    std::string position = "Point Guard";
    for (int i = 0; i < 3; i++) {
        Player* newPlayer = new Player(positions[0]);
        players.push_back(newPlayer);
    }
    for (int i = 0; i < 3; i++) {
        Player* newPlayer = new Player(positions[1]);
        players.push_back(newPlayer);
    }
    for (int i = 0; i < 3; i++) {
        Player* newPlayer = new Player(positions[2]);
        players.push_back(newPlayer);
    }
    for (int i = 0; i < 3; i++) {
        Player* newPlayer = new Player(positions[3]);
        players.push_back(newPlayer);
    }
    for (int i = 0; i < 3; i++) {
        Player* newPlayer = new Player(positions[4]);
        players.push_back(newPlayer);
    }

    for (const auto& player : players) {
        player->printPlayer();
    }
}

Team::~Team() {

    for (auto player : players) {
        delete player;
    }
}
