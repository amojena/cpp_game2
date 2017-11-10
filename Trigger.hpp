#ifndef TRIGGER_H_
#define TRIGGER_H_

#include "smaller.hpp"

class Trigger{
public:
    Trigger() {};
    ~Trigger() {};
    string command;
    string type;
    string has;
    string object;
    string status;
    string owner;
    string print;
    vector <Attack> att;
};

#endif