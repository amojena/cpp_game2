#ifndef MAIN_H_
#define MAIN_H_

#include "Container.hpp"
#include "Trigger.hpp"
#include "Room.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

Container* setContainer(xml_node<>* highNode);
Trigger* setTrigger(xml_node<>* highNode);
Item* setItem(xml_node<>* highNode);

Container* setContainer(xml_node<>* highNode) //high_node -> name = container
{ 
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

Trigger* setTrigger(xml_node<>* highNode) //high_node -> name = trigger
{
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

Item* setItem(xml_node<>* highNode) //high_node -> name = item
{
    Item* tempI = new Item();
    xml_node<>* tempNode = highNode -> first_node();

    while(tempNode != NULL) {
        if(!strcmp(tempNode -> name(), "name")){
            tempI -> setName(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "writing")){
            tempI -> setWriting(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "status")){
            tempI -> setStatus(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "turnon")){
            tempI -> setTurnon(tempNode);
        }

        else if(!strcmp(tempNode -> name(), "trigger")){
            tempI -> trig.push_back(setTrigger(tempNode));
        }

        tempNode = tempNode -> next_sibling();
    }
    return tempI;
}

Room* setRoom(xml_node<>* highNode) //high_node -> name = room
{
    Room* tempR = new Room();
    xml_node<>* tempNode = highNode -> first_node();

    while (tempNode != NULL)
    {
        if(!strcmp(tempNode -> name(), "name")){
            tempR -> setName(tempNode -> value());
        }
        
        else if(!strcmp(tempNode -> name(), "description")){
            tempR -> setDesc(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "type")){
            tempR -> setType(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "status")){
            tempR -> setStatus(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "item")){
            tempR -> itemArray.push_back( tempNode -> value() );
        }

        else if(!strcmp(tempNode -> name(), "container")){
            tempR -> containerArray.push_back( tempNode -> value() );
        }

        else if(!strcmp(tempNode -> name(), "creature")){
            tempR -> creatureArray.push_back( tempNode -> value() );
        }

        else if(!strcmp(tempNode -> name(), "trigger")){
            tempR -> trig.push_back(setTrigger(tempNode));
        }

        else if(!strcmp(tempNode -> name(), "border")){
            tempR -> borders.push_back(tempR -> setBorder(tempNode));
        }

        tempNode = tempNode -> next_sibling();
    } //while

    return tempR;
}

Creature* setCreature(xml_node<>* highNode)
{
    Creature* tempC = new Creature();
    xml_node<>* tempNode = highNode -> first_node();

    while (tempNode != NULL)
    {
        if(!strcmp(tempNode -> name(), "name")){
            tempC -> setName(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "description")){
            tempC -> setDescription(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "status")){
            tempC -> setStatus(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "vulnerability")){
            tempC -> vulnerability.push_back(tempNode -> value());
        }

        else if(!strcmp(tempNode -> name(), "trigger")){
            tempC -> trig.push_back(setTrigger(tempNode));
        }

        else if(!strcmp(tempNode -> name(), "attack")){
            tempC -> attack = (tempC -> setAttack(tempNode));
        }

        tempNode = tempNode -> next_sibling();
    }//while

    return tempC;
}

Room* searchRoom(string name, vector <Room*> rooms) {
    for(int i = 0; i < rooms.size(); i++) {
        if (name == rooms[i]->name) {
            return rooms[i];
        }
    }
    return NULL;
}

Container* searchContainer(string name, vector <Container*> conts) {
    for(int i = 0; i < conts.size(); i++) {
        if (name == conts[i]->name) {
            return conts[i];
        }
    }
    return NULL;
}

Item* searchItem(string name, vector <Item*> items) {
    for(int i = 0; i < items.size(); i++) {
        if (name == items[i]->name) {
            return items[i];
        }
    }
    return NULL;
}

int searchItemIndex(Item* item, vector <Item*> items) {
    for(int i = 0; i < items.size(); i++) {
        if (item == items[i]) {
            return i;
        }
    }
    return -1;
}

Creature* searchCreature(string name, vector <Creature*> creatures) {
    for(int i = 0; i < creatures.size(); i++) {
        if (name == creatures[i]->name) {
            return creatures[i];
        }
    }
    return NULL;
}

void setRoomVectors(Room* room, vector <Item*> items, vector <Container*> conts, vector <Creature*> creatures, vector <Room*> rooms) {
    for(int i = 0; i < room->itemArray.size(); i++) {
        room->items.push_back(searchItem(room->itemArray[i], items));
    }
    for(int i = 0; i < room->containerArray.size(); i++) {
        room->cont.push_back(searchContainer(room->containerArray[i], conts));
        for(int j = 0; j < room->cont[i]->itemArray.size(); j++) {
            room->cont[i]->items.push_back(searchItem(room->cont[i]->itemArray[j], items));
        }
    }
    for(int i = 0; i < room->creatureArray.size(); i++) {
        room->creatures.push_back(searchCreature(room->creatureArray[i], creatures));
    }
    for(int i = 0; i < room -> borders.size(); i++) {
        string dir = room -> borders[i].direction;
        if (dir == "north")
            room -> north = searchRoom(room -> borders[i].roomName, rooms);
        if (dir == "south")
            room -> south = searchRoom(room -> borders[i].roomName, rooms);
        if (dir == "east")
            room -> east = searchRoom(room -> borders[i].roomName, rooms);
        if (dir == "west")
            room -> west = searchRoom(room -> borders[i].roomName, rooms);
    }
}

bool findTrigger(string input, Player* player, vector<Item*> itemsVec, vector<Creature*> creatureVec)
{
    int len = input.length();
    if (len == 1)
    {
        int inp = (int)input[0];
        switch(inp)
        {
            case 110:
                if (player -> currentRoom -> searchBorder("north") && player -> leaveRoom(input))
                {
                    //check triggers
                    player -> currentRoom = player -> currentRoom -> north;
                    cout << player -> currentRoom -> description << endl;
                }
                else if (!(player -> currentRoom -> searchBorder("north")))
                    cout << "Can't go that way." << endl;
                break;
            case 115:
                if (player -> currentRoom -> searchBorder("south"))
                {
                    player -> currentRoom = player -> currentRoom -> south;
                    cout << player -> currentRoom -> description << endl;
                }
                else if (!(player -> currentRoom -> searchBorder("south")))
                    cout << "Can't go that way." << endl;
                 break;
            case 101:
                if (player -> currentRoom -> searchBorder("east"))
                {
                    player -> currentRoom = player -> currentRoom -> east;
                    cout << player -> currentRoom -> description << endl;
                }
                else if (!(player -> currentRoom -> searchBorder("east")))
                    cout << "Can't go that way." << endl;
                break;
            case 119:
                if (player -> currentRoom -> searchBorder("west"))
                {
                    player -> currentRoom = player -> currentRoom -> west;
                    cout << player -> currentRoom -> description << endl;
                }
                else if (!(player -> currentRoom -> searchBorder("west")))
                    cout << "Can't go that way." << endl;
                break;
            case 105:
                cout << "Inventory: ";
                if (player -> inventory.size() == 0)
                {
                    cout << "empty" << endl;
                }
                else
                {
                    for(int i=0; i < player -> inventory.size(); i++)
                    {
                        cout << player -> inventory[i] -> name;
                        if (i+1 < player -> inventory.size())
                            cout << ", ";
                        else
                            cout << endl;
                    }
                }
                break;
            default:
                cout << "Error" << endl;
                break;
        }
    }
    
    else if(input.find("take") != -1)
    {   
        if (len < 5)
        {
            cout << "Error" << endl;
            return false;
        }

        Item* inR = searchItem(input.substr(5), player -> currentRoom -> items);
        Item* inC = NULL;
        int index1;
        int index2;
        for(int i = 0; i < player -> currentRoom -> cont.size(); i++)
        {
            inC = searchItem(input.substr(5), player -> currentRoom -> cont[i] -> items);
            index2 = searchItemIndex(inC, player -> currentRoom -> cont[i] -> items);
            if (inC != NULL)
            {
                index1 = i;
                break;
            }
                
        }

        if (inR != NULL)
        {
            player -> inventory.push_back(inR);
            player -> currentRoom -> items.erase(player -> currentRoom -> items.begin() + searchItemIndex(inR, player -> currentRoom -> items));
            cout << "Item " << inR -> name << " added to inventory." << endl;
            inR = NULL;
        }
        else if(inC != NULL)
        {
            player -> inventory.push_back(inC);
            player -> currentRoom -> cont[index1] -> items.erase(player -> currentRoom -> cont[index1] -> items.begin() + index2);
            cout << "Item " << inC -> name << " added to inventory." << endl;
            inC = NULL;
        }
        else
            cout << "Error" << endl;
        
        return false;
    }

    else if(input.find("read") != -1)
    {
        if (len < 5)
        {
            cout << "Error" << endl;
            return false;
        }
        Item* item = searchItem(input.substr(5), player -> inventory);

        if(item != NULL)
            cout << item -> description << endl;
        else
            cout << "Error" << endl;
    }

    else if(input.find("turn on") != -1)
    {
        if (len < 8)
        {
            cout << "Error" << endl;
            return false;
        }
        Item* item = searchItem(input.substr(8), player -> inventory);

        if (item != NULL)
        {
            cout << "You activate the " << item -> name << '.' << endl;
            cout << item -> turn.print << endl;
            int index = item -> turn.action.find("to ");
            item -> setStatus(item -> turn.action.substr(index + 3));
        }
    }

    else if(input.find("open") != -1)
    {
        if (len < 5)
        {
            cout << "Error" << endl;
            return false;
        }

        Container* con = searchContainer(input.substr(5), player -> currentRoom -> cont);

        if(con != NULL)
        {
            if (con -> items.size() == 0)
                cout << con -> name << " is empty." << endl;
            else
            {
                cout << con -> name << " contains ";
                for(int i=0; i < con -> items.size(); i++)
                {
                    cout << con -> items[i] -> name;
                    if (i+1 < con -> items.size())
                        cout << ", ";
                    else
                        cout << '.' << endl;
                }
            }
        }
        else
            cout << "Error" << endl;
    }

    else if(input.find("attack") != -1)
    {
        int index = input.find("with");
        if(index == -1 || len < 11)
        {
            cout << "Error" << endl;
            return false;
        }

        Creature* tempC = searchCreature(input.substr(7, index-2 - 6), player -> currentRoom -> creatures);
        Item* weapon = searchItem(input.substr(index + 5), player -> inventory);

        if(tempC == NULL || weapon == NULL)
        {
            cout << "Error" << endl;
            return false;
        }

        for(int j = 0; j < tempC -> vulnerability.size(); j++)
        {
            if (weapon -> name == tempC -> vulnerability[j])
            {
                if(weapon -> status == tempC -> attack ->status)
                {
                    cout << tempC -> attack->print << endl;
                    for (int i = 0; i < tempC -> attack ->actions.size(); i++)
                    {
                        string act = tempC -> attack->actions[i];
                        if (act.find("Add") != -1)
                        {
                            index = act.find("to ");
                            Item* add = searchItem(act.substr(4, index - 2 - 3), itemsVec);
                            cout << add -> name << endl;
                            
                            
                            string room = act.substr(index + 3);
                            cout << room << endl;
                            if (room == player -> currentRoom -> name)
                                player -> currentRoom -> items.push_back(add);
                            else
                            {
                                Container* tempC = searchContainer(room, player -> currentRoom -> cont);
                                tempC -> items.push_back(add);
                            }

                        }
                    }
                }
                else
                    cout << "Error" << endl;
            }
        }

    }

    else
    {
        cout << "Error" << endl;
        return false;
    }

    for(int i = 0; i < player -> currentRoom -> creatures.size(); i++)
    {
        Creature* tempC = player -> currentRoom -> creatures[i];
        for(int j = 0; j < tempC -> trig.size(); j++)
        {
            Trigger* tempT = tempC -> trig[j];
            if(tempT -> type == "single" && tempT -> singleOn)
                break;
            Item* object;

            if (tempT -> owner.size() != 0 && tempT -> owner != "inventory")
            {
                Container* con = searchContainer(tempT -> owner, player -> currentRoom -> cont);
                object = searchItem(tempT -> object, con -> items);
            }
            else
                object = searchItem(tempT -> object, player -> inventory);

            if (tempT -> status.length() != 0)
            {
                if(tempT -> status == object -> status)
                {   
                    cout << tempT -> print << endl;
                    tempT -> singleOn = true;
                    break;
                }
            }
        }
    }

    return false;
}
#endif