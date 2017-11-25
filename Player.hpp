#ifndef PLAYER_H_
#define PLAYER_H_

#include "Item.hpp"
#include "Room.hpp"

class Player{
    public:
    Player() {};
    ~Player() {};
    Room* currentRoom;
    vector<class Item*> inventory;
};

void setRoom(Room* curr) { currentRoom = curr; };
void setItem(Item* item) { inventory.push_back(item); };



#endif