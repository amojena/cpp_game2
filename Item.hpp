#ifndef ITEM_H_
#define ITEM_H_

#include "Trigger.hpp"

class Item{
public:
    Item();
    ~Item();
    string name;
    string status;
    string description; //writing in the xml file
    Turnon turn;
    vector <class Trigger> trig;
};

#endif