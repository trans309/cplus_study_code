#include <iostream>

using namespace std;

#include "administrator.h"
#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "管理员信息"
#define filename_tea "教师信息"
#define filename_stu "学生信息"

void Administrator::Administrator_menu()
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

void Administrator::Login_menu()
{

    while(1)
    {
        ReservationSystem rs_a;
        rs_a.menu();

        cout<<"请输入管理员姓名：";
        cin>>this->I_Name;

        for(vector<Administrator>::iterator it=ReservationSystem::AdminInfo.begin();it!=ReservationSystem::AdminInfo.end();it++)
        {
            if(it->I_Name==this->I_Name)
            {
                cout<<"请输入密码：";
                cin>>this->I_Password;
                if(it->I_Password==this->I_Password)
                {
                    cout<<endl<<"登录成功！"<<endl;
                    cout<<"欢迎您！管理员"<<it->I_Name<<endl;
                    system("pause");
                    system("cls");
                    this->Administrator_menu();
                }
            }
        }

        cout<<"账户不存在！"<<endl;
    }

}

void Administrator::save_Adminfile()
{

}



void Administrator::Registration_menu()
{

}
