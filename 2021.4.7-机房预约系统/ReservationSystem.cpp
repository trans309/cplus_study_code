#include <iostream>

using namespace std;

#include "ReservationSystem.h"
#include "administrator.h"
#include "student.h"
#include "teacher.h"
#include "computer_room.h"

#define filename_ad "./file/管理员信息.txt"
#define filename_tea "./file/教师信息.txt"
#define filename_stu "./file/学生信息.txt"
#define filename_ComRoom "./file/机房信息.txt"

ReservationSystem::ReservationSystem()
{
    this->AdminInfo.clear();
    this->read_IentityFile(1,this->AdminInfo,this->TeaInfo,this->StuInfo);

    this->TeaInfo.clear();
    this->read_IentityFile(1,this->AdminInfo,this->TeaInfo,this->StuInfo);

    this->StuInfo.clear();
    this->read_IentityFile(1,this->AdminInfo,this->TeaInfo,this->StuInfo);

    this->ComRoomInfo.clear();
    this->read_ComRoomFile(this->ComRoomInfo);
}

ReservationSystem::~ReservationSystem()
{

}



//basic system

void ReservationSystem::AdministratorSystem()
{
    system("cls");

    this->init_readfile(this->ComRoomInfo,this->AdminInfo,this->TeaInfo,this->StuInfo);

    Administrator ad;

    while(1)
    {
        this->menu_choice();

        cout<<"请选择操作：";
        int ad_choice;
        cin>>ad_choice;

        switch(ad_choice)
        {
        case AD_RETURN:
            return;
        case REGISTRATION:
            ad.Registration_menu(this->AdminInfo);
            break;
        case LOGIN:
            ad.Login_menu(this->ComRoomInfo,this->AdminInfo,this->TeaInfo,this->StuInfo);
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

void ReservationSystem::read_IentityFile(int type,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    //1、打开文件
    ifstream ifs;
    if(type==1) ifs.open(filename_ad,ios::in);
    if(type==2) ifs.open(filename_tea,ios::in);
    if(type==3) ifs.open(filename_stu,ios::in);

    //2、文件是否存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在";
        return;
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {

//        cout<<"文件为空";
        return;

    }

    //4、文件读取
    ifs.putback(ch);

    if(type==1)
    {
//        cout<<"文件读取成功"<<endl;
        Administrator ad_t;
        while(ifs>>ad_t.I_Name&&ifs>>ad_t.I_Password)
        {
            AdminInfo.push_back(ad_t);
        }
    }

    if(type==2)
    {
        Teacher tea_t;
        while(ifs>>tea_t.TeaNum&&ifs>>tea_t.I_Name&&ifs>>tea_t.I_Password)
        {
            TeaInfo.push_back(tea_t);
        }
    }

    if(type==3)
    {
        Student stu_t;
        while(ifs>>stu_t.StuNum&&ifs>>stu_t.I_Name&&ifs>>stu_t.I_Password)
        {
            StuInfo.push_back(stu_t);
        }
    }

    //5、关闭文件
    ifs.close();
}

void ReservationSystem::read_ComRoomFile(map<int,ComputerRoom> &ComInfo)
{
        //1、打开文件
    ifstream ifs;
    ifs.open(filename_ComRoom,ios::in);

    //2、文件是否存在
    if(!ifs.is_open())
    {
//        cout<<"文件不存在";
        return;
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {

//        cout<<"文件为空";
        return;

    }

    //4、文件读取
    ifs.putback(ch);
    int index;


//    cout<<"文件读取成功"<<endl;
    ComputerRoom com_t;
    while(ifs>>index&&ifs>>com_t.capacity&&ifs>>com_t.state&&ifs>>com_t.Week&&ifs>>com_t.time)
    {
        ComInfo.insert(make_pair(index,com_t));
    }

    //5、关闭文件
    ifs.close();
}

void ReservationSystem::init_readfile(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
//    cout<<"调用init";

    AdminInfo.clear();
    read_IentityFile(1,AdminInfo,TeaInfo,StuInfo);

    TeaInfo.clear();
    read_IentityFile(2,AdminInfo,TeaInfo,StuInfo);

    StuInfo.clear();
    read_IentityFile(3,AdminInfo,TeaInfo,StuInfo);

    ComRoomInfo.clear();
    read_ComRoomFile(ComRoomInfo);
}
