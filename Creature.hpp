#ifndef CREATURE_H_
#define CREATURE_H_

#include "Trigger.hpp"

class Creature{
public:
    Creature() {};
    ~Creature() {};
    string name;
    string status;
    string description; 
    vector <string> vulnerability;
    Attack* attack;
    vector <class Trigger*> trig;

    void setName(string _name)   { name = _name;         }
    void setDescription(string desc)    { description = desc;   }
    void setStatus(string stat)  { status = stat;        }
    Attack* setAttack(xml_node<>* temp);
};

Attack* Creature :: setAttack(xml_node<>* temp)
{
    temp = temp -> first_node();
    Attack* att = new Attack();
    int condition = 0;
    while (temp != NULL)
    {
        if (! strcmp(temp -> name(), "condition"))
        { 
            temp = temp -> first_node();
            condition ++;
        }
        if (! strcmp(temp -> name(), "object"))
            att -> object = temp -> value();
        
        else if (! strcmp(temp -> name(), "status"))
            att -> status = temp -> value();
        
        else if (! strcmp(temp -> name(), "print"))
            att -> print = temp -> value();
        
        else if (! strcmp(temp -> name(), "action"))
            att -> actions.push_back(temp -> value());

        if (temp -> next_sibling() == NULL && condition)
        {
            condition = 0;
            temp = temp -> parent();
        }
        
        temp = temp -> next_sibling();
        
    } //while

    return att;
}

#endif