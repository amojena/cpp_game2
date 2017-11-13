#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item.hpp"
#include "Trigger.hpp"


class Container{
public:
    Container() {};
    ~Container() {};
    string name;
    string status;
    string description;
    vector <string> accept;
    vector <string> itemArray;
    vector <class Item*> items;
    vector <class Trigger*> trig;

    //Functions
    void setName(string _name) { name = _name; };
    void setStatus(string stat) { status = stat; };
    void setDescription(string _desc) { description = _desc; };
    void setItem(string item) { itemArray.push_back(item); };
    void setAccept(string _accept) { accept.push_back(_accept); };
};


#endif