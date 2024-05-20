#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include <iostream>
#include "Player.h"

extern std::vector<std::string> positions;
extern std::map<std::string, std::map<std::string, std::map<std::string, std::pair<int, int>>>> archetypes;

class Team {
    
public:

    // Constructors
    Team();
    
    // Destructor
    ~Team();

private:

    // Characteristics
    std::string name;
    std::string location;

    // Players
    std::vector<Player*> players;

};

#endif // TEAM_H