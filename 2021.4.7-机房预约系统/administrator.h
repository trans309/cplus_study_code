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

//    string A_Name;//����
//    string A_Password;//����

    map<int,ComputerRoom> A_ComInfo;//������Ϣ


    //1��ȡ�ļ�
//    void read_Adminfile(int type);

    //2.1��ע�����
    void Registration_menu();

    //2.2����¼����
    void Login_menu();

    void Administrator_menu();

    void save_Adminfile();



};
