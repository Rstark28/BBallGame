#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vectors>

class Team {
    
public:

    // Constructors
    Team();
    
    // Destructor
    ~Team();

private:
    
    // Characteristics
    std::string name;
    std::sting location;

    // Players
    std::vector players;

};

#endif // TEAM_H