#ifndef CREATURE_H_
#define CREATURE_H_

#include "Trigger.hpp"

class Creature{
public:
    Creature();
    ~Creature();
    string name;
    string status;
    string description; 
    vector <string> vulnerability;
    class Attack attack;
    vector <class Trigger> trig;
};

#endif