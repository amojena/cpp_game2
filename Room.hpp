#ifndef ROOM_H_
#define ROOM_H_

#include "Container.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Trigger.hpp"

class Room{
public:
    Room();
    ~Room();
    string name;
    string description;
    string type; //will be exit or null
    string status;

    vector <Border> borders;
    vector <class Item> items;
    vector <class Container> cont;
    vector <class Trigger> trig;
    vector <class Creature> creatures;
};

#endif