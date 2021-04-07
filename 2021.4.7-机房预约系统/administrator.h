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

    //1读取文件


    //2.1、注册界面
    void Registration_menu(vector<Administrator> &AdminInfo);

        //2.1.1、保存新注册管理员
        void save_Adminfile(vector<Administrator> &AdminInfo);

    //2.2、登录界面
    void Login_menu(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //3、进入管理员界面
    void Administrator_main(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

        //3.1、管理员菜单
        void Administrator_menu();

        //3.2、读取文件
        void read_file(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

            //3.2.1、添加/删除教师账号
            void teacher_modify();

            //3.2.2、添加/删除学生账号
            void student_modify();

            //3.2.3、查看所有教师/学生账号
            void TS_veiw();

            //3.2.4、修改机房信息
            void computerroom_modify(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);







};
