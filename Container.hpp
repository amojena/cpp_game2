#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item.hpp"
#include "Trigger.hpp"


class Container{
public:
    Container();
    ~Container();
    string name;
    string status;
    string description;
    vector <string> accept;
    vector <class Item> items;
    vector <class Trigger> trig;
};

#endif