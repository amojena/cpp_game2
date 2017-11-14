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
};

Border Room :: setBorder(xml_node<>* temp)
{
    temp = temp -> first_node();
    Border b;
    while(temp != NULL)
    {
        if ( ! strcmp(temp -> name(), "direction") )
            b.direction = temp -> value();
        else if ( ! strcmp(temp -> name(), "name") )
            b.roomName = temp -> value();
    }
    return b;
}

#endif