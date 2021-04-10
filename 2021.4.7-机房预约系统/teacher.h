#pragma once

using namespace std;

#include <iostream>
#include <string>

#include "Identity.h"
#include "computer_room.h"
#include "order.h"

class Teacher:public Identity
{
public:

//    string T_Name;//姓名
//    string T_Password;//密码
    string TeaNum;//职工号

        //1、读取文件
//    ReservationSystem::StudentSystem以进行读取

    //2.1、注册界面
    void Registration_menu(vector<Teacher> &TeaInfo);

        //2.1.1、保存新注册教师
        void save_Teafile(vector<Teacher> &TeaInfo);

    //2.2、登录界面
    void Login_menu(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

    //3、进入教师界面
    void Teacher_main(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

        //3.1、教师菜单
        void Teacher_menu();

        //3.2、读取文件
        void read_tea_file(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);


            //3.2.1、查看所有预约
            void Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.2、审核预约
            void Audit_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.2.1保存 机房/预约 信息
                void save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.2.2、获得状态学生
                string get_odstate_stu(string od_state);

                //3.2.2.3、获得状态教师
                string get_odstate_tea(string od_state);

};
