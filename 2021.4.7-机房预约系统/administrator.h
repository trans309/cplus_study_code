#pragma once

using namespace std;

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

#include "computer_room.h"
#include "teacher.h"
#include "student.h"
#include "Identity.h"

class Administrator:public Identity
{
public:

//    string A_Name;//姓名
//    string A_Password;//密码

    map<int,ComputerRoom> A_ComInfo;//机房信息


    //1读取文件
//    void read_Adminfile(int type);

    //2.1、注册界面
    void Registration_menu();

    //2.2、登录界面
    void Login_menu();

    void Administrator_menu();

    void save_Adminfile();



};
