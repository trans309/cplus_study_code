#include "class_circle.h"

//����Բ��
void circle::set_center(point c1)
{
    center.set_x(c1.get_x());
    center.set_y(c1.get_y());
}
int circle::get_center_x()
{
    return center.get_x();
}
int circle::get_center_y()
{
    return center.get_y();
}
//���ð뾶
void circle::set_radius(int set_r)
{
    radius=set_r;
}
int circle::get_radius()
{
    return radius;
}


void circle::judge_des(point p)
{
    if((get_center_x()-p.get_x())*(get_center_x()-p.get_x())+(get_center_y()-p.get_y())*(get_center_y()-p.get_y())
       > get_radius()*get_radius())
    {
        cout<<"����Բ��"<<endl;
    }
    else if((get_center_x()-p.get_x())*(get_center_x()-p.get_x())+(get_center_y()-p.get_y())*(get_center_y()-p.get_y())
       < get_radius()*get_radius())
    {
        cout<<"����Բ��"<<endl;
    }
    else
    {
        cout<<"����Բ��"<<endl;
    }
}
