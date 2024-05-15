#include "Player.h"

std::vector<std::string> positions = {
    "Point Guard",
    "Shooting Guard",
    "Small Forward",
    "Power Forward",
    "Center"
};

// Define archetypes and their weight distributions
std::map<std::string, std::map<std::string, std::map<std::string, std::pair<int, int>>>> archetypes = {
    {"Point Guard", {
        {"Floor General", {
            {"dunk", {30, 70}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {60, 99}},
            {"dribbling", {60, 99}},
            {"interiorDefense", {30, 70}},
            {"perimeterDefense", {50, 90}},
            {"steal", {40, 80}},
            {"block", {30, 70}},
            {"rebounding", {30, 70}},
        }},
        {"Scoring Guard", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {60, 99}},
            {"threePointShot", {60, 99}},
            {"freeThrow", {60, 99}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {30, 70}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {30, 70}},
            {"rebounding", {30, 70}},
        }},
        {"Lockdown Guard", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {40, 80}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {40, 80}},
            {"passing", {40, 80}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {60, 99}},
            {"steal", {60, 99}},
            {"block", {40, 80}},
            {"rebounding", {30, 70}},
        }},
        {"Pass-First Playmaker", {
            {"dunk", {30, 70}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {40, 80}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {50, 90}},
            {"passing", {60, 99}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {30, 70}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {30, 70}},
            {"rebounding", {30, 70}},
        }},
        {"Combo Guard", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {50, 90}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {50, 90}},
            {"steal", {40, 80}},
            {"block", {30, 70}},
            {"rebounding", {40, 80}},
        }},
    }},
    {"Shooting Guard", {
        {"Sharpshooter", {
            {"dunk", {40, 80}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {60, 99}},
            {"threePointShot", {60, 99}},
            {"freeThrow", {60, 99}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {30, 70}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {30, 70}},
            {"rebounding", {30, 70}},
        }},
        {"Slasher", {
            {"dunk", {60, 99}},
            {"insideShot", {60, 99}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {40, 80}},
            {"rebounding", {40, 80}},
        }},
        {"Two-Way Guard", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {60, 99}},
            {"steal", {50, 90}},
            {"block", {40, 80}},
            {"rebounding", {40, 80}},
        }},
        {"Mid-Range Specialist", {
            {"dunk", {40, 80}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {60, 99}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {30, 70}},
            {"rebounding", {40, 80}},
        }},
        {"Glue Guy", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {50, 90}},
            {"block", {30, 70}},
            {"rebounding", {40, 80}},
        }},
    }},
    {"Small Forward", {
        {"Versatile Wing", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {50, 90}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {50, 90}},
            {"steal", {50, 90}},
            {"block", {40, 80}},
            {"rebounding", {50, 90}},
        }},
        {"Defensive Stopper", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {40, 80}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {40, 80}},
            {"passing", {40, 80}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {60, 99}},
            {"steal", {50, 90}},
            {"block", {40, 80}},
            {"rebounding", {40, 80}},
        }},
        {"Scoring Forward", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {40, 80}},
            {"rebounding", {40, 80}},
        }},
        {"3-and-D", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {40, 80}},
            {"threePointShot", {60, 99}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {60, 99}},
            {"steal", {50, 90}},
            {"block", {40, 80}},
            {"rebounding", {40, 80}},
        }},
        {"Point Forward", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {50, 90}},
            {"freeThrow", {50, 90}},
            {"passing", {60, 99}},
            {"dribbling", {60, 99}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {50, 90}},
            {"steal", {50, 90}},
            {"block", {40, 80}},
            {"rebounding", {50, 90}},
        }},
    }},
    {"Power Forward", {
        {"Stretch Four", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {60, 99}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {40, 80}},
            {"rebounding", {50, 90}},
        }},
        {"Post-Up Specialist", {
            {"dunk", {50, 90}},
            {"insideShot", {60, 99}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {30, 70}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {30, 70}},
            {"steal", {30, 70}},
            {"block", {50, 90}},
            {"rebounding", {60, 99}},
        }},
        {"Defensive Anchor", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {30, 70}},
            {"threePointShot", {30, 70}},
            {"freeThrow", {30, 70}},
            {"passing", {40, 80}},
            {"dribbling", {30, 70}},
            {"interiorDefense", {60, 99}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {60, 99}},
            {"rebounding", {60, 99}},
        }},
        {"Face-Up Forward", {
            {"dunk", {50, 90}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {60, 99}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {50, 90}},
            {"passing", {40, 80}},
            {"dribbling", {50, 90}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {40, 80}},
            {"rebounding", {50, 90}},
        }},
        {"Grit General", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {40, 80}},
            {"threePointShot", {30, 70}},
            {"freeThrow", {30, 70}},
            {"passing", {30, 70}},
            {"dribbling", {30, 70}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {40, 80}},
            {"steal", {50, 90}},
            {"block", {50, 90}},
            {"rebounding", {60, 99}},
        }},
    }},
    {"Center", {
        {"Traditional Big Man", {
            {"dunk", {60, 99}},
            {"insideShot", {60, 99}},
            {"midRangeShot", {40, 80}},
            {"threePointShot", {30, 70}},
            {"freeThrow", {40, 80}},
            {"passing", {40, 80}},
            {"dribbling", {30, 70}},
            {"interiorDefense", {60, 99}},
            {"perimeterDefense", {30, 70}},
            {"steal", {30, 70}},
            {"block", {60, 99}},
            {"rebounding", {60, 99}},
        }},
        {"Stretch Five", {
            {"dunk", {40, 80}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {60, 99}},
            {"freeThrow", {50, 90}},
            {"passing", {50, 90}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {50, 90}},
            {"rebounding", {50, 90}},
        }},
        {"Rim Protector", {
            {"dunk", {40, 80}},
            {"insideShot", {40, 80}},
            {"midRangeShot", {30, 70}},
            {"threePointShot", {30, 70}},
            {"freeThrow", {30, 70}},
            {"passing", {30, 70}},
            {"dribbling", {30, 70}},
            {"interiorDefense", {60, 99}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {60, 99}},
            {"rebounding", {60, 99}},
        }},
        {"Athletic Big", {
            {"dunk", {60, 99}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {30, 70}},
            {"threePointShot", {30, 70}},
            {"freeThrow", {40, 80}},
            {"passing", {30, 70}},
            {"dribbling", {30, 70}},
            {"interiorDefense", {50, 90}},
            {"perimeterDefense", {30, 70}},
            {"steal", {40, 80}},
            {"block", {50, 90}},
            {"rebounding", {50, 90}},
        }},
        {"Playmaking Five", {
            {"dunk", {40, 80}},
            {"insideShot", {50, 90}},
            {"midRangeShot", {50, 90}},
            {"threePointShot", {40, 80}},
            {"freeThrow", {50, 90}},
            {"passing", {60, 99}},
            {"dribbling", {40, 80}},
            {"interiorDefense", {40, 80}},
            {"perimeterDefense", {40, 80}},
            {"steal", {40, 80}},
            {"block", {40, 80}},
            {"rebounding", {50, 90}},
        }},
    }}
};

// Constructors
Player::Player() {

    position = positions[generateRandomStat(0, 4)];
}

Player::Player(std::string position) {

    this->position = position;
}

// Destructor
Player::~Player() {

}


// Function to generate a random integer in a given range
int Player::generateRandomStat(int low, int high) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    return dis(gen);
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

    overall = sum * 100 / 480;
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
