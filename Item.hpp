#ifndef ITEM_H_
#define ITEM_H_

#include "Trigger.hpp"

class Item{
public:
    Item() {};
    ~Item() {};
    string name;
    string status;
    string description; //writing in the xml file
    Turnon turn;
    vector <class Trigger*> trig;

    void setName(string _name) { name = _name; };
    void setStatus(string stat) { status = stat; };
    void setWriting(string _desc) { description = _desc; };
    void setTurnon(xml_node<>* node);
};

void Item :: setTurnon(xml_node<>* node)
{
    xml_node<>* temp = node -> first_node();
    while(temp != NULL)
    {
        if(! strcmp(temp -> name(), "print"))
        {
            turn.print = temp -> value();
        }
        else if(! strcmp(temp -> name(), "action"))
        {
            turn.action = temp -> value();
        }

        temp = temp -> next_sibling();
    }
}
#endif