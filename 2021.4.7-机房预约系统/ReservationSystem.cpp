#include <iostream>

using namespace std;

#include "ReservationSystem.h"
#include "administrator.h"
#include "student.h"
#include "teacher.h"
#include "computer_room.h"
#include "order.h"
#include "Identity.h"

#define filename_ad "./file/管理员信息.txt"
#define filename_tea "./file/教师信息.txt"
#define filename_stu "./file/学生信息.txt"
#define filename_CRO "./file/机房-预约记录.txt"

ReservationSystem::ReservationSystem()
{
    this->Init_Admin_ReadFile(this->CRoomOrder,this->AdminInfo,this->TeaInfo,this->StuInfo);
    this->Init_Tea_ReadFile(this->TeaInfo,this->CRoomOrder);
    this->Init_Stu_ReadFile(this->StuInfo,this->CRoomOrder);
}

ReservationSystem::~ReservationSystem()
{

}



//basic system

void ReservationSystem::AdministratorSystem()
{
    system("cls");

    this->Init_Admin_ReadFile(this->CRoomOrder,this->AdminInfo,this->TeaInfo,this->StuInfo);
//    this->check_CRoom_empty(this->CRoomOrder);

    Administrator ad;

    while(1)
    {
        this->menu_choice();

        cout<<"请选择操作：";
        int ad_choice;
        cin>>ad_choice;

        switch(ad_choice)
        {
        case RETURN:
            return;
        case REGISTRATION:
            ad.Registration_menu(this->AdminInfo);
            break;
        case LOGIN:
            ad.Login_menu(this->CRoomOrder,this->AdminInfo,this->TeaInfo,this->StuInfo);
            return;
        default:
            cout<<"错误输入，请重新输入！"<<endl;
            break;
        }

        system("pause");
        system("cls");
    }

}

void ReservationSystem::TeacherSystem()
{
    system("cls");

    this->Init_Tea_ReadFile(this->TeaInfo,this->CRoomOrder);
//    this->check_CRoom_empty(this->CRoomOrder);

    Teacher tea;

    while(1)
    {
        this->menu_choice();

        cout<<"请选择操作：";
        int tea_choice;
        cin>>tea_choice;

        switch(tea_choice)
        {
        case RETURN:
            return;
        case REGISTRATION:
            tea.Registration_menu(this->TeaInfo);
            break;
        case LOGIN:
            tea.Login_menu(this->TeaInfo,this->CRoomOrder);
            return;
        default:
            cout<<"错误输入，请重新输入！"<<endl;
            break;
        }

        system("pause");
        system("cls");
    }

}

void ReservationSystem::StudentSystem()
{
    system("cls");

    this->Init_Stu_ReadFile(this->StuInfo,this->CRoomOrder);
//    this->check_CRoom_empty(this->CRoomOrder);

    Student stu;

    while(1)
    {
        this->menu_choice();

        cout<<"请选择操作：";
        int stu_choice;
        cin>>stu_choice;

        switch(stu_choice)
        {
        case RETURN:
            return;
        case REGISTRATION:
            stu.Registration_menu(this->StuInfo);
            break;
        case LOGIN:
            stu.Login_menu(this->StuInfo,this->CRoomOrder);
            return;
        default:
            cout<<"错误输入，请重新输入！"<<endl;
            break;
        }

        system("pause");
        system("cls");
    }

}

void ReservationSystem::Exit()
{
    cout<<"欢迎下次使用！"<<endl;
    exit(0);
}



//other system

void ReservationSystem::menu()
{
    cout<<"*****************************"<<endl;
    cout<<"    欢迎使用机房预约系统"<<endl;
    cout<<"*****************************"<<endl;
    cout<<"     |----------------|      "<<endl;
    cout<<"     |    1、管理员   |      "<<endl;
    cout<<"     |    2、教师     |      "<<endl;
    cout<<"     |    3、学生     |      "<<endl;
    cout<<"     |    0、退出     |      "<<endl;
    cout<<"     |----------------|      "<<endl;
    cout<<"*****************************"<<endl;
    cout<<endl;
}

void ReservationSystem::menu_choice()
{
    cout<<"     |----------------|      "<<endl;
    cout<<"     |    1、注册     |      "<<endl;
    cout<<"     |    2、登录     |      "<<endl;
    cout<<"     |    0、返回     |      "<<endl;
    cout<<"     |----------------|      "<<endl;
}

void ReservationSystem::read_AdminFile(vector<Administrator> &AdminInfo)
{
    //1、打开文件
    ifstream ifs;
    ifs.open(filename_ad,ios::in);

    //2、文件是否存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在";
        ifs.close();
        return;
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();

    if(ifs.eof())
    {
//        cout<<"文件为空";
        ifs.close();
        return;
    }

    //4、文件读取
    ifs.putback(ch);

//    cout<<"文件读取成功"<<endl;
    Administrator ad_t;
    while(ifs>>ad_t.I_Name&&ifs>>ad_t.I_Password)
    {
        AdminInfo.push_back(ad_t);
    }

    //5、关闭文件
    ifs.close();
}

void ReservationSystem::read_Teafile(vector<Teacher> &TeaInfo)
{
    //1、打开文件
    ifstream ifs;
    ifs.open(filename_tea,ios::in);

    //2、文件是否存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在";
        ifs.close();
        return;
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();

    if(ifs.eof())
    {
//        cout<<"文件为空";
        ifs.close();
        return;
    }

    //4、文件读取
    ifs.putback(ch);

    Teacher tea_t;
    while(ifs>>tea_t.TeaNum&&ifs>>tea_t.I_Name&&ifs>>tea_t.I_Password)
    {
        TeaInfo.push_back(tea_t);
    }

    //5、关闭文件
    ifs.close();
}

void ReservationSystem::read_Stufile(vector<Student> &StuInfo)
{
    //1、打开文件
    ifstream ifs;
    ifs.open(filename_stu,ios::in);

    //2、文件是否存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在";
        ifs.close();
        return;
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();

    if(ifs.eof())
    {
//        cout<<"文件为空";
        ifs.close();
        return;
    }

    //4、文件读取
    ifs.putback(ch);

    Student stu_t;
    while(ifs>>stu_t.StuNum&&ifs>>stu_t.I_Name&&ifs>>stu_t.I_Password)
    {
        StuInfo.push_back(stu_t);
    }

    //5、关闭文件
    ifs.close();
}

void ReservationSystem::read_CRO_File(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    //1、打开文件
    ifstream ifs;
    ifs.open(filename_CRO,ios::in);

    //2、文件是否存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在";
        ifs.close();
        return;
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();

    if(ifs.eof())
    {
//        cout<<"文件为空";
        ifs.close();
        return;
    }

    //4、文件读取
    ifs.putback(ch);

//    cout<<"文件读取成功"<<endl;

    string str1;//索引/预约人
    string str2;//CR状态/OD状态
    string str3;//容量/星期
    string str4;//':'/时间段


    int pos;
    int T_capacity=CRoomOrder.size();

    vector<Order> vod_t;
    ComputerRoom cr_t;
    Order od_t;

    while(ifs>>str1&&ifs>>str2&&ifs>>str3&&ifs>>str4)
    {
        pos=str4.find(":");//找到返回下标，找不到返回-1

        if(pos != -1)//找到':'
        {
            if(T_capacity==0)
            {
                cr_t.CR_index=str1;
                cr_t.capacity=str3;
                cr_t.CR_state=str2;
                T_capacity++;
            }

            else//容量不为0
            {
                CRoomOrder.insert(make_pair(cr_t,vod_t));

                vod_t.clear();

                cr_t.CR_index=str1;
                cr_t.capacity=str3;
                cr_t.CR_state=str2;


            }
        }

        else//pos==-1,找不到':'
        {
            od_t.Applicant=str1;
            od_t.Week=str3;
            od_t.time=str4;
            od_t.OD_state=str2;

            vod_t.push_back(od_t);
        }
//        cout<<CRoomOrder.size()<<" ";//test
    }
    CRoomOrder.insert(make_pair(cr_t,vod_t));
//    cout<<CRoomOrder.size()<<" ";//test

    //5、关闭文件
    ifs.close();
}

void ReservationSystem::Init_Admin_ReadFile(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
//    cout<<"调用init";

    AdminInfo.clear();
    read_AdminFile(AdminInfo);

    TeaInfo.clear();
    read_Teafile(TeaInfo);

    StuInfo.clear();
    read_Stufile(StuInfo);

    CRoomOrder.clear();
    read_CRO_File(CRoomOrder);
}

void ReservationSystem::Init_Tea_ReadFile(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    TeaInfo.clear();
    read_Teafile(TeaInfo);

    CRoomOrder.clear();
    read_CRO_File(CRoomOrder);
}

void ReservationSystem::Init_Stu_ReadFile(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    StuInfo.clear();
    read_Stufile(StuInfo);

    CRoomOrder.clear();
    read_CRO_File(CRoomOrder);
}

void ReservationSystem::check_CRoom_empty(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it=CRoomOrder.begin();it!=CRoomOrder.end();it++)
    {
        if(it->second.size()==0)
        {
            ComputerRoom cr_t;
            cr_t.CR_index=it->first.CR_index;
            cr_t.capacity=it->first.capacity;
            cr_t.CR_state="0";

            vector<Order> empty_vod;

            CRoomOrder.erase(it);

            CRoomOrder.insert(make_pair(cr_t,empty_vod));
        }
    }
    Administrator ad_t;
    ad_t.save_ComRoom(CRoomOrder);
}
