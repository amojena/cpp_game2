#include "Container.hpp"

Container* setContainer(xml_node<>* highNode);

Container* setContainer(xml_node<>* highNode){ //high_node -> name = container
    Container* tempC = new Container();
    xml_node<>* tempNode = highNode -> first_node();

    while (tempNode != NULL)
    {
        if (strcmp(tempNode -> name(), "name"))
            tempC -> setName(tempNode->value()); 


        else if (strcmp(tempNode -> name(), "description"))
            tempC -> setDescription(tempNode->value());
        

        else if (strcmp(tempNode -> name(), "item"))
            tempC -> setItem(tempNode->value());
        

        else if (strcmp(tempNode -> name(), "status"))
            tempC -> setStatus(tempNode->value());
        

        else if (strcmp(tempNode -> name(), "accept"))
            tempC -> setAccept(tempNode->value());
        

        /*else if (strcmp(tempNode -> name(), "trigger")){
            tempC -> setTrigger(tempNode); //in trigger class
        }*/

        tempNode = tempNode -> next_sibling();

    } //while

    return tempC;
}


// if container
    //set container
    //add to vector