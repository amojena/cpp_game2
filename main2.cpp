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
    xml_node<>* temp_node = room_node -> first_node(); 
    Container* temp;
    int subtree = 0;

    while (room_node != NULL)
    {
        temp_node = room_node -> first_node(); 
        cout << "ROOM NAME: " << room_node -> name() << endl;
        
        while (temp_node != NULL)
        {
            cout << temp_node -> name() << ": " << temp_node-> value() << endl;
            if (! strcmp(temp_node -> value(), "") )
            {
                temp_node = temp_node -> first_node();
                subtree++;
            }
            
            else 
            {
                if(temp_node -> next_sibling() == NULL)
                {
                    while (subtree != 0 && temp_node -> next_sibling() == NULL)
                    {
                        subtree--;
                        temp_node = temp_node -> parent();
                    }   
                }

                temp_node = temp_node -> next_sibling();
            }
        
        }
    
        room_node = room_node -> next_sibling();
        cout << endl << endl;
        subtree = 0;
    }
 
    return 0;
}