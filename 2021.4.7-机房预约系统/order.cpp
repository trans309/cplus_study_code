#include "order.h"

Order::Order()
{
    this->Week="0";
    this->time="0";
    this->OD_state="0";
}

string Order::get_week()
{
    if(this->Week=="1") return "星期一";
    if(this->Week=="2") return "星期二";
    if(this->Week=="3") return "星期三";
    if(this->Week=="4") return "星期四";
    if(this->Week=="5") return "星期五";
    if(this->Week=="6") return "星期六";
    if(this->Week=="7") return "星期日";

    return "状态错误";
}

string Order::get_time()
{
    if(this->time=="1") return "上午";
    if(this->time=="2") return "下午";
    if(this->time=="3") return "晚上";

    return "状态错误";
}

bool Order::operator==(Order& odt)
{
    return (this->Week==odt.Week)&&(this->time==odt.time);
}
