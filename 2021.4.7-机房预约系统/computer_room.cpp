#include <iostream>

using namespace std;

#include "computer_room.h"

ComputerRoom::ComputerRoom()
{
    this->capacity="0";
    this->init_state();
}

void ComputerRoom::init_state()
{
    this->CR_state="0";
}

//bool ComputerRoom::operator==(char ch) const
//{
//    return this->CR_index==ch;
//}
