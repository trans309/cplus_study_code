#include <iostream>

using namespace std;

#include "computer_room.h"

ComputerRoom::ComputerRoom()
{
//    this->index=0;
    this->capacity=0;
    this->state=0;
    this->Week=0;
    this->time=0;
}

string ComputerRoom::get_week()
{
    if(this->Week==1) return "����һ";
    if(this->Week==2) return "���ڶ�";
    if(this->Week==3) return "������";
    if(this->Week==4) return "������";
    if(this->Week==5) return "������";
    if(this->Week==6) return "������";
    if(this->Week==7) return "������";

    return "״̬����";
}

string ComputerRoom::get_time()
{
    if(this->time==1) return "����";
    if(this->time==2) return "����";
    if(this->time==3) return "����";

    return "״̬����";
}
