#ifndef ROOM_H_
#define ROOM_H_

#include "Container.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Trigger.hpp"

class Room{
public:
    Room() {};
    ~Room() {};
    string name;
    string description;
    string type; //will be exit or null
    string status;
    vector <string> containerArray;
    vector <string> creatureArray;
    vector <string> itemArray;

    vector <Border> borders;
    vector <class Item*> items;
    vector <class Container*> cont;
    vector <class Trigger*> trig;
    vector <class Creature*> creatures;
    Room* north;
    Room* south;
    Room* east;
    Room* west;  

    void setName(string _name)   { name = _name;         }
    void setDesc(string desc)    { description = desc;   }
    void setType(string _type)   { type = _type;         }
    void setStatus(string stat)  { status = stat;        } 
    Border setBorder(xml_node<>* temp); 
    bool searchBorder(string name);
};

Border Room :: setBorder(xml_node<>* temp)
{
    xml_node<>* temp2 = temp -> first_node();
    Border b;
    while(temp2 != NULL)
    {
        if ( ! strcmp(temp2 -> name(), "direction") )
            b.direction = temp2 -> value();
        else if ( ! strcmp(temp2 -> name(), "name") )
            b.roomName = temp2 -> value();
        temp2 = temp2 -> next_sibling();
    }
    return b;
}

bool Room :: searchBorder(string name) {
    for(int i= 0; i < borders.size(); i++) {
        if(borders[i].direction == name) {
            return true;
        }
    }
    return false;
}

#endif