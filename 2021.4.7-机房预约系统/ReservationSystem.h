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

enum re_menu
{
    EXIT,
    ADMINISTRATOR,
    TEACHER,
    STUDENT
};

enum ad_menu
{
    AD_RETURN,
    REGISTRATION,
    LOGIN
};
class Administrator;

class ReservationSystem
{
public:

    bool ad_empty;
    bool tea_empty;
    bool stu_empty;

    vector<Administrator> AdminInfo;//管理员信息
    vector<Teacher> TeaInfo;//教师信息
    vector<Student> StuInfo;//学生信息

    map<int,ComputerRoom> A_ComInfo;//机房信息




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

    //读取文件
    //type1---管理员
    //type2---教师
    //type3---学生
    void read_IentityFile(int type,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //初始化读取文件
    void init_readfile(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);


};
