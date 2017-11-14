#ifndef SMALLER_H_
#define SMALLER_H_

#include <string>
#include <vector>
#include "rapidxml.hpp"
using namespace rapidxml;
using namespace std;


struct Border
{
    string roomName;
    string direction;
};

struct Turnon
{
    string print;
    string action;
};

struct Attack
{
    string object;
    string status;
    string print;
    vector <string> actions;
};

#endif