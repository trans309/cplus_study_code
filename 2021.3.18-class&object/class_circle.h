#pragma once
#include <iostream>
#include "class_point.h"

class circle
{
private:
    int radius;//�뾶
    point center;//Բ��

public:
    //����Բ��
    void set_center(point c1);

    int get_center_x();
    int get_center_y();

    //���ð뾶
    void set_radius(int set_r);
    int get_radius();


    void judge_des(point p);
};
