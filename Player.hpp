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

    void setRoom(Room* curr) { currentRoom = curr; };
    void setItem(Item* item) { inventory.push_back(item); };    
    bool leaveRoom(string input);
};

bool Player :: leaveRoom(string input)
{
    if (currentRoom -> trig.size() == 0)
        return true;

    for(int i = 0; i < currentRoom -> trig.size(); i++)
    {
        Trigger* temp = currentRoom -> trig[i];
        if (input == temp -> command)
        {
            for(int j = 0; j < inventory.size(); j++)
            {
                if(temp -> object == inventory[i] -> name)
                {
                    if(temp -> has == "no")
                        return true;
                }
            }
            cout << temp -> print << endl;
            return false;
        }
    }

    return false;
}


#endif