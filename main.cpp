#include "rapidxml.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Container.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include "Trigger.hpp"
#include "Main.hpp"
#include "Player.hpp"

using namespace std;
using namespace rapidxml;

int main ()
{
    xml_document<> doc;    // character type defaults to char
    xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile ("sample.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    
	// Parse the buffer using the xml file parsing library into doc 
    doc.parse<0>(&buffer[0]);
    
    // Find our root node
    root_node = doc.first_node("map");

    // Iterate over the nodes
    xml_node<>* node = root_node->first_node("room");
    xml_node<>* temp_node;
     
    vector <Container*> containers;
    vector <Item*> items;
    vector <Room*> rooms;
    vector <Creature*> creatures;

    while (node != NULL)
    {
        temp_node = node -> first_node();
        
        if ( ! strcmp(node -> name(), "container")  ) {
            containers.push_back(setContainer(node));
        }
        
        else if ( ! strcmp(node -> name(), "item")  )
            items.push_back(setItem(node));
        
        else if ( ! strcmp(node -> name(), "room")  )
            rooms.push_back(setRoom(node));
        
        else if ( ! strcmp(node -> name(), "creature")  )
            creatures.push_back(setCreature(node));
                
        node = node -> next_sibling();
    }

    for(int i = 0; i < rooms.size(); i++) {
        setRoomVectors(rooms[i], items, containers, creatures, rooms);
    }

    //start game
    Player* player = new Player();
    player -> setRoom(searchRoom("Entrance", rooms));
    cout << player ->  currentRoom -> description << endl;
    bool gameOver = false;
    string input;

    while (!gameOver)
    {
        getline(cin, input);
        gameOver = findTrigger(input, player, items, creatures);
    }

    return 0;
}

