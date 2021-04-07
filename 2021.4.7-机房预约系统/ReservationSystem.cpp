#include <iostream>

using namespace std;

#include "ReservationSystem.h"
#include "administrator.h"

#define filename_ad "管理员信息"
#define filename_tea "教师信息"
#define filename_stu "学生信息"

ReservationSystem::ReservationSystem()
{
        this->ad_empty=true;
        this->tea_empty=true;
        this->stu_empty=true;
}

ReservationSystem::~ReservationSystem()
{

}



//basic system

void ReservationSystem::AdministratorSystem()
{
    this->read_IentityFile(1);

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
            break;
        case LOGIN:
            break;
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

void ReservationSystem::read_IentityFile(int type)
{
    //1、打开文件
    ifstream ifs;
    if(type==1) ifs.open(filename_ad,ios::in);
    if(type==2) ifs.open(filename_tea,ios::in);
    if(type==3) ifs.open(filename_stu,ios::in);
    //2、文件是否存在
    if(!ifs.is_open())
    {
        if(type==1)
        {
            ReservationSystem::ad_empty=true;
            return;
        }

        if(type==2)
        {
            ReservationSystem::tea_empty=true;
            return;
        }

        if(type==3)
        {
            ReservationSystem::stu_empty=true;
            return;
        }
    }

    //3、文件是否为空
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {
        if(type==1)
        {
            ReservationSystem::ad_empty=true;
            return;
        }

        if(type==2)
        {
            ReservationSystem::tea_empty=true;
            return;
        }

        if(type==3)
        {
            ReservationSystem::stu_empty=true;
            return;
        }
    }

    //4、文件读取
    ifs.putback(ch);

    if(type==1)
    {
        ReservationSystem::ad_empty=false;
    }

    if(type==2)
    {
        ReservationSystem::tea_empty=false;
    }

    if(type==3)
    {
        ReservationSystem::stu_empty=false;
    }

    //5、关闭文件
    ifs.close();
}
