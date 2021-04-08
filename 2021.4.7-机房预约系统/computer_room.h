#pragma once

using namespace std;

#include <iostream>

#include <string>

class ComputerRoom
{
public:

//    int index;//索引值

    int capacity;//容量

    /*
    0--闲置/可预约
    1--已预约
    2--已取消/可预约
     */
    int state;//状态

    int Week;//星期

    /*
    1--上午
    2--下午
    3--晚上
     */
    int time;//一天中时间段

    ComputerRoom();

    string get_week();
    string get_time();

};
