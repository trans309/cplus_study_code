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
#include "order.h"

class Administrator:public Identity
{
public:

    //1、读取文件
    //ReservationSystem::AdministratorSystem以进行读取

    //2.1、注册界面
    void Registration_menu(vector<Administrator> &AdminInfo);

        //2.1.1、保存新注册管理员
        void save_Adminfile(vector<Administrator> &AdminInfo);

    //2.2、登录界面
    void Login_menu(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //3、进入管理员界面
    void Administrator_main(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

        //3.1、管理员菜单
        void Administrator_menu();

        //3.2、读取文件
        void read_ad_file(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

            //3.2.1、添加/删除教师账号
            void teacher_modify(vector<Teacher> &TeaInfo);

                //3.2.1.1保存教师账号
                void save_Teacher(vector<Teacher> &TeaInfo);

            //3.2.2、添加/删除学生账号
            void student_modify(vector<Student> &StuInfo);

                //3.2.1.1保存学生账号
                void save_Student(vector<Student> &StuInfo);

            //3.2.3、查看所有教师/学生账号
            void TS_veiw(vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

            //3.2.4、清除所有预约
            void clear_all_order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.4.1、保存机房文件
                //void save_ComRoom(map<int,ComputerRoom> &ComRoomInfo);

            //3.2.5、修改/打印机房信息
            void computerroom_modify_main(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.5.1获得OD状态
                string get_OD_state(string od_state);

                //3.2.5.1、修改机房信息
                void computerroom_modify(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                    //3.2.5.1.1、保存机房预约文件
                    void save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

};
