#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

class Player {
public:
    // Constructors
    Player();
    Player(std::string position);

    // Destructor
    ~Player();

    void generatePlayerStats();
    void printPlayer();

private:

    int generateRandomStat(int low, int high);
    void computeOverallRating();

    std::vector<std::string> positions = {
        "Point Guard",
        "Shooting Guard",
        "Small Forward",
        "Power Forward",
        "Center"
    };

    // Characteristics
    std::string name;
    std::string position;
    std::string archetype;
    int overall;
    int height;
    int weight;
    int age;

    // Shooting
    int dunk;
    int insideShot;
    int midRangeShot;
    int threePointShot;
    int freeThrow;

    // Playmaking
    int passing;
    int dribbling;

    // Defending
    int interiorDefense;
    int perimeterDefense;
    int steal;
    int block;
    int rebounding;

};

#endif // PLAYER_H
