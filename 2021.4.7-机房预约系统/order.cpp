#include "order.h"

Order::Order()
{
    this->Week="0";
    this->time="0";
    this->OD_state="0";
}

string Order::get_week()
{
    if(this->Week=="1") return "����һ";
    if(this->Week=="2") return "���ڶ�";
    if(this->Week=="3") return "������";
    if(this->Week=="4") return "������";
    if(this->Week=="5") return "������";
    if(this->Week=="6") return "������";
    if(this->Week=="7") return "������";

    return "״̬����";
}

string Order::get_time()
{
    if(this->time=="1") return "����";
    if(this->time=="2") return "����";
    if(this->time=="3") return "����";

    return "״̬����";
}

bool Order::operator==(Order& odt)
{
    return (this->Week==odt.Week)&&(this->time==odt.time);
}
