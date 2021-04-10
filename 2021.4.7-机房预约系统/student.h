#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cstdlib>

#include "Identity.h"
#include "computer_room.h"
#include "order.h"

class Student:public Identity
{
public:

//    string S_Name;//姓名
//    string S_Password;//密码
    string StuNum;//学号


    //1、读取文件
//    ReservationSystem::StudentSystem以进行读取

    //2.1、注册界面
    void Registration_menu(vector<Student> &StuInfo);

        //2.1.1、保存新注册学生
        void save_Stufile(vector<Student> &StuInfo);

    //2.2、登录界面
    void Login_menu(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

    //3、进入学生界面
    void Student_main(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

        //3.1、学生菜单
        void Student_menu();

        //3.2、读取文件
        void read_stu_file(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.1、申请预约
            void ApplyFor_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.1.1保存 机房/预约 信息
                void save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.2、取消预约
            void CancelFor_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.3、查看我的预约
            void Veiw_My_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.4、查看所有预约
            void Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.3/4.1、获得状态
                string get_odstate(string od_state);

};
