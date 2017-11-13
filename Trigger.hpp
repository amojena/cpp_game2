#ifndef TRIGGER_H_
#define TRIGGER_H_

#include "smaller.hpp"

class Trigger{
public:
    Trigger() {};
    ~Trigger() {};
    string command;
    string type;
    string has;
    string object;
    string status;
    string owner;
    string print;
    vector <string> actions; //action

    void setCommand(string comm) { command = comm; }
    void setType(string _type)   { type = _type;   }
    void setHas(string _has)     { has = _has;     }
    void setObject(string obj)   { object = obj;   }
    void setStatus(string stat)  { status = stat;  }
    void setOwner(string own)    { owner = own;    }
    void setPrint(string pr)     { print = pr;     }
};

#endif