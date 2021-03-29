#pragma once

#include <iostream>

using namespace std;

#include <cstdlib>
#include "worker.h"

class menu_system
{
public:
    //基本系统
    void menu();
    void add_worker();
    void show_worker();

    int worker_num;
    worker** worker_arr;

    menu_system()
    {
        worker_num=0;
        worker_arr=NULL;
    }
};
