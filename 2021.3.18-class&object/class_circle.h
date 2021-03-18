#pragma once
#include <iostream>
#include "class_point.h"

class circle
{
private:
    int radius;//°ë¾¶
    point center;//Ô²ĞÄ

public:
    //ÉèÖÃÔ²ĞÄ
    void set_center(point c1);

    int get_center_x();
    int get_center_y();

    //ÉèÖÃ°ë¾¶
    void set_radius(int set_r);
    int get_radius();


    void judge_des(point p);
};
