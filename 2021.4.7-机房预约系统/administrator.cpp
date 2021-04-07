#include <iostream>

using namespace std;

#include "administrator.h"
#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "./file/管理员信息.txt"
#define filename_tea "./file/教师信息.txt"
#define filename_stu "./file/学生信息.txt"

void Administrator::Administrator_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      欢迎您！管理员    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |  1、添加/删除教师账号      |   "<<endl;
    cout<<"   |  2、添加/删除学生账号      |   "<<endl;
    cout<<"   |  3、查看所有教师/学生账号  |   "<<endl;
    cout<<"   |  4、修改机房信息           |   "<<endl;
    cout<<"   |  0、注销登录               |   "<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"************************************"<<endl;
    cout<<endl;
}

void Administrator::Login_menu(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{

    while(1)
    {
        system("cls");

        ReservationSystem rs_a;
        rs_a.menu_choice();

        cout<<"请输入管理员姓名：";
        cin>>this->I_Name;

        for(vector<Administrator>::iterator it=AdminInfo.begin();it!=AdminInfo.end();it++)
        {
            //测试
//            cout<<it->I_Name<<endl<<it->I_Password<<endl;
//            cout<<"测试"<<endl;

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
                    this->Administrator_main(AdminInfo,TeaInfo,StuInfo);
                    return;
                }
            }
        }

        cout<<"账户不存在！"<<endl;
        cout<<"是否重新输入?(y/n)"<<endl;

        char ch;
        cin>>ch;
        if(ch=='n') break;

    }

}

void Administrator::save_Adminfile(vector<Administrator> &AdminInfo)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_ad,ios::out|ios::app);

    //2、保存文件
    for(vector<Administrator>::iterator it=AdminInfo.begin();it!=AdminInfo.end();it++)
    {
        ofs<<it->I_Name<<"\t"<<it->I_Password<<endl;
    }

    //3关闭文件
    ofs.close();
}



void Administrator::Registration_menu(vector<Administrator> &AdminInfo)
{
    cout<<"请输入账号：";
    string Name;
    cin>>Name;

    cout<<"请输入密码：";
    string Password;
    cin>>Password;

    Administrator ad_t;
    ad_t.I_Name=Name;
    ad_t.I_Password=Password;

    AdminInfo.push_back(ad_t);
//    this->AdminInfo.push_back(ad_t);

    this->save_Adminfile(AdminInfo);

    cout<<"注册成功！"<<endl;
}

void Administrator::Administrator_main(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    while(1)
    {
        //打印菜单
        this->Administrator_menu();

        cout<<"请进行操作：";
        int choice;
        cin>>choice;

        //2、选择
        switch(choice)
        {
        case 0://注销
            cout<<"注销成功！"<<endl;
            return;
        case 1://添加/删除教师账号
            break;
        case 2://添加/删除学生账号
            break;
        case 3://查看所有教师/学生账号
            break;
        case 4://修改机房信息
            break;
        }

        //3、清屏
        system("pause");
        system("cls");
    }
}

void Administrator::read_file(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    ReservationSystem rs_t;

    rs_t.init_readfile(AdminInfo,TeaInfo,StuInfo);
}
