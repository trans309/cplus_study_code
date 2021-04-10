#pragma once

using namespace std;

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "administrator.h"
#include "teacher.h"
#include "student.h"
#include "computer_room.h"
#include "order.h"

enum re_menu
{
    EXIT,
    ADMINISTRATOR,
    TEACHER,
    STUDENT
};

enum system_menu
{
    RETURN,
    REGISTRATION,
    LOGIN
};

class ReservationSystem
{
public:

    vector<Administrator> AdminInfo;//管理员信息
    vector<Teacher> TeaInfo;//教师信息
    vector<Student> StuInfo;//学生信息

    map<ComputerRoom,vector<Order>,less_ComRoom> CRoomOrder;//机房预约信息



    //构造/析构
    ReservationSystem();
    ~ReservationSystem();



    //basic system

    //学生系统
    void StudentSystem();//vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //教师系统
    void TeacherSystem();//vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //管理员系统
    void AdministratorSystem();//vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //退出预约系统
    void Exit();



    //other system

    //登入菜单界面
    void menu();
    void menu_choice();

    //检测机房空状态
    void check_CRoom_empty(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);




    //读取 身份 文件
    //type1---管理员
    void read_AdminFile(vector<Administrator> &AdminInfo);
    //type2---教师
    void read_Teafile(vector<Teacher> &TeaInfo);
    //type3---学生
    void read_Stufile(vector<Student> &StuInfo);

    //读取 机房/预约记录 文件
    void read_CRO_File(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);
    //Administrator
    //初始化 管理员 读取文件
    void Init_Admin_ReadFile(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //Teacher
    //初始化 教师 读取文件
    void Init_Tea_ReadFile(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

    //Student
    //初始化 学生 读取文件
    void Init_Stu_ReadFile(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

};
