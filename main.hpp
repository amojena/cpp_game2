#include "Container.hpp"

Container* setContainer(xml_node<>* highNode);
Trigger* setTrigger(xml_node<>* highNode);

Container* setContainer(xml_node<>* highNode){ //high_node -> name = container
    Container* tempC = new Container();
    xml_node<>* tempNode = highNode -> first_node();

    while (tempNode != NULL)
    {
        if (!strcmp(tempNode -> name(), "name")){
            tempC -> setName(tempNode->value());
        }


        else if (!strcmp(tempNode -> name(), "description"))
            tempC -> setDescription(tempNode->value());
        

        else if (!strcmp(tempNode -> name(), "item"))
            tempC -> setItem(tempNode->value());
        

        else if (!strcmp(tempNode -> name(), "status"))
            tempC -> setStatus(tempNode->value());
        

        else if (!strcmp(tempNode -> name(), "accept"))
            tempC -> setAccept(tempNode->value());
        

        else if (!strcmp(tempNode -> name(), "trigger")){
            tempC -> trig.push_back(setTrigger(tempNode));
        }
    
        tempNode = tempNode -> next_sibling();

    } //while

    return tempC;
}

Trigger* setTrigger(xml_node<>* highNode){
    Trigger* tempT = new Trigger();
    xml_node<>* tempNode = highNode -> first_node();
    int condition = 0;

    while(tempNode != NULL) {
        if(!strcmp(tempNode -> name(), "condition")){
            tempNode = tempNode -> first_node();
            condition = 1;
        }

        if (!strcmp(tempNode -> name(), "command"))
            tempT -> setCommand(tempNode->value());
        
        else if (!strcmp(tempNode -> name(), "type"))
            tempT -> setType(tempNode->value());

        else if (!strcmp(tempNode -> name(), "has")){
            tempT -> setHas(tempNode->value());
        }

        else if (!strcmp(tempNode -> name(), "object"))
            tempT -> setObject(tempNode->value());

        else if (!strcmp(tempNode -> name(), "status"))
            tempT -> setStatus(tempNode->value());

        else if (!strcmp(tempNode -> name(), "owner"))
            tempT -> setOwner(tempNode->value());

        else if (!strcmp(tempNode -> name(), "print")){
            tempT -> setPrint(tempNode->value());
        }

        else if (!strcmp(tempNode -> name(), "action"))
            tempT -> actions.push_back(tempNode -> value());

        if(tempNode -> next_sibling() == NULL && condition)
        {
            tempNode = tempNode -> parent();
            condition = 0;
        }

        tempNode = tempNode -> next_sibling();

        
    }//while

    return tempT;
}