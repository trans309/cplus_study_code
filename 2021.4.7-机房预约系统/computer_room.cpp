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
    if(this->Week==1) return "星期一";
    if(this->Week==2) return "星期二";
    if(this->Week==3) return "星期三";
    if(this->Week==4) return "星期四";
    if(this->Week==5) return "星期五";
    if(this->Week==6) return "星期六";
    if(this->Week==7) return "星期日";

    return "状态错误";
}

string ComputerRoom::get_time()
{
    if(this->time==1) return "上午";
    if(this->time==2) return "下午";
    if(this->time==3) return "晚上";

    return "状态错误";
}
