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

    // Iterate over the rooms
    xml_node<>* room_node = root_node->first_node("room");
    xml_node<>* temp_node;
     
    vector <Container*> containers;
    vector <Item*> items;
    vector <Room*> rooms;
    vector <Creature*> creatures;

    while (room_node != NULL)
    {
        temp_node = room_node -> first_node(); 
        cout << "ROOM NAME: " << room_node -> name() << endl;
        
        if ( ! strcmp(room_node -> name(), "container")  )
            containers.push_back(setContainer(room_node));
        
        else if ( ! strcmp(room_node -> name(), "item")  )
            items.push_back(setItem(room_node));
        
        else if ( ! strcmp(room_node -> name(), "room")  )
            rooms.push_back(setRoom(room_node));
        
        else if ( ! strcmp(room_node -> name(), "creature")  )
            creatures.push_back(setCreature(room_node));
                
        room_node = room_node -> next_sibling();
        cout << endl;
    }

    cout << "rooms: " << rooms.size() << endl;
    cout << "items: " << items.size() << endl;
    cout << "conts: " << containers.size() << endl;
    cout << "creat: " << creatures.size() << endl;



    return 0;
}