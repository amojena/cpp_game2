#include "rapidxml.hpp"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace rapidxml;


int main ()
{
    //cout << "Hello, World" << endl;

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
    xml_node<> * room_node = root_node->first_node("room");
    xml_node<>* temp_node = room_node;
    while (temp_node != NULL)
    {
        cout << temp_node -> first_node("name")->value() << endl;
        cout << temp_node -> first_node("description")->value() << endl;
        
        temp_node = temp_node -> next_sibling("room");
    }
    
    
    return 0;
}