#include "Player.h"

// Constructors
Player::Player() {

    position = positions[generateRandomStat(0, 4)];
    generatePlayerStats();
}

Player::Player(std::string position) {

    this->position = position;
    generatePlayerStats();
}

// Destructor
Player::~Player() {

}


// Function to generate a random integer in a given range
int Player::generateRandomStat(int low, int high) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Calculate parameters for log-normal distribution
    double logMean = std::log((low + high) / 2.0);
    double logStdDev = (std::log(high) - std::log(low)) / 3.5; // A rough estimate

    std::lognormal_distribution<> dis(logMean, logStdDev);

    int value = std::round(dis(gen));

    // Ensure the value is within the desired range
    if (value < low) value = low;
    if (value > high) value = high;

    return value;
}

// Function to generate a random player
void Player::generatePlayerStats() {
     
    // Get the list of archetypes for the player's position
    const auto& positionArchetypes = archetypes.at(position);

    // Randomly select an archetype
    std::vector<std::string> archetypesList;
    for (const auto& arch : positionArchetypes) {
        archetypesList.push_back(arch.first);
    }
    archetype = archetypesList[generateRandomStat(0, archetypesList.size() - 1)];

    // Generate stats based on the selected archetype
    for (const auto& stat : positionArchetypes.at(archetype)) {
        int value = generateRandomStat(stat.second.first, stat.second.second);
        if (stat.first == "dunk") dunk = value;
        else if (stat.first == "insideShot") insideShot = value;
        else if (stat.first == "midRangeShot") midRangeShot = value;
        else if (stat.first == "threePointShot") threePointShot = value;
        else if (stat.first == "freeThrow") freeThrow = value;
        else if (stat.first == "passing") passing = value;
        else if (stat.first == "dribbling") dribbling = value;
        else if (stat.first == "interiorDefense") interiorDefense = value;
        else if (stat.first == "perimeterDefense") perimeterDefense = value;
        else if (stat.first == "steal") steal = value;
        else if (stat.first == "block") block = value;
        else if (stat.first == "rebounding") rebounding = value;
    }

    computeOverallRating();
}

// Shit
void Player::computeOverallRating() {

    const auto& stat = archetypes.at(position).at(archetype);
    int sum = (dunk - stat.at("dunk").first) +
              (insideShot - stat.at("insideShot").first) +
              (midRangeShot - stat.at("midRangeShot").first) +
              (threePointShot - stat.at("threePointShot").first) +
              (freeThrow - stat.at("freeThrow").first) +
              (passing - stat.at("passing").first) +
              (dribbling - stat.at("dribbling").first) +
              (interiorDefense - stat.at("interiorDefense").first) +
              (perimeterDefense - stat.at("perimeterDefense").first) +
              (steal - stat.at("steal").first) +
              (block - stat.at("block").first) +
              (rebounding - stat.at("rebounding").first);

    overall = sum * 100 / 12 / 40;
}

// Function to print player's details
void Player::printPlayer() {

    std::cout << "Position: " << position << std::endl;
    std::cout << "Archetype: " << archetype << std::endl;
    std::cout << "Overall: " << overall << std::endl;
    std::cout << "Stats:" << std::endl;
    std::cout << "  Dunk: " << dunk << std::endl;
    std::cout << "  Inside Shot: " << insideShot << std::endl;
    std::cout << "  Mid Range Shot: " << midRangeShot << std::endl;
    std::cout << "  Three Point Shot: " << threePointShot << std::endl;
    std::cout << "  Free Throw: " << freeThrow << std::endl;
    std::cout << "  Passing: " << passing << std::endl;
    std::cout << "  Dribbling: " << dribbling << std::endl;
    std::cout << "  Interior Defense: " << interiorDefense << std::endl;
    std::cout << "  Perimeter Defense: " << perimeterDefense << std::endl;
    std::cout << "  Steal: " << steal << std::endl;
    std::cout << "  Block: " << block << std::endl;
    std::cout << "  Rebounding: " << rebounding << std::endl;
}
