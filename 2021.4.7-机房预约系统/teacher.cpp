#include <iostream>

using namespace std;

#include "ReservationSystem.h"

#define filename_tea "./file/教师信息.txt"
#define filename_CRO "./file/机房-预约记录.txt"

void Teacher::Registration_menu(vector<Teacher> &TeaInfo)
{
    cout<<"请输入职工号：";
    string TeaNum;
    cin>>TeaNum;

    cout<<"请输入姓名：";
    string Name;
    cin>>Name;

    cout<<"请输入密码：";
    string Password;
    cin>>Password;

    Teacher tea_t;
    tea_t.I_Name=Name;
    tea_t.I_Password=Password;
    tea_t.TeaNum=TeaNum;

    TeaInfo.push_back(tea_t);

    this->save_Teafile(TeaInfo);

    cout<<"注册成功！"<<endl;
}

void Teacher::save_Teafile(vector<Teacher> &TeaInfo)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_tea,ios::trunc);

    //2、保存文件
    for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();it++)
    {
        ofs<<it->TeaNum<<"\t"
           <<it->I_Name<<"\t"
           <<it->I_Password<<endl;
    }

    //3关闭文件
    ofs.close();
}

void Teacher::Login_menu(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{

    while(1)
    {
        system("cls");

        ReservationSystem rs_a;
        rs_a.menu_choice();

        cout<<"请输入教师职工号：";
        cin>>this->TeaNum;

        for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();it++)
        {

            if(it->TeaNum==this->TeaNum)
            {
                while(1)
                {
                    cout<<"请输入姓名：";
                    cin>>this->I_Name;

                        if(it->I_Name==this->I_Name)
                        {
                            while(1)
                            {
                                cout<<"请输入密码：";
                                cin>>this->I_Password;

                                if(it->I_Password==this->I_Password)
                                {
                                    cout<<endl<<"登录成功！"<<endl;
                                    cout<<"欢迎您！教师 "<<this->I_Name<<endl;
                                    system("pause");
                                    system("cls");

                                    this->Teacher_main(TeaInfo,CRoomOrder);

                                    return;
                                }

                                cout<<endl<<"密码错误！请重新输入！"<<endl<<endl;
                            }
                        }
                    cout<<endl<<"职工号与姓名不匹配！请重新输入！"<<endl<<endl;

                }
            }
        }

        cout<<"职工号无记录！"<<endl;
        cout<<"是否重新输入?(y/n)"<<endl;

        char ch;
        cin>>ch;
        if(ch=='n') break;

    }

}

void Teacher::Teacher_main(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    while(1)
    {
        //打印菜单
        this->Teacher_menu();

        //读取文件
        this->read_tea_file(TeaInfo,CRoomOrder);

        cout<<"请进行操作：";
        int choice;
        cin>>choice;

        //2、选择
        switch(choice)
        {
        case 0://注销
            cout<<"注销成功！"<<endl;
            return;
        case 1://查看所有预约
            this->Veiw_All_Order(CRoomOrder);
            break;
        case 2://审核预约
            this->Audit_All_Order(CRoomOrder);
            break;
        }

        //3、清屏
        system("pause");
        system("cls");
    }
}

void Teacher::Teacher_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      欢迎您！教师    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |       1、查看所有预约      |   "<<endl;
    cout<<"   |       2、审核预约          |   "<<endl;
    cout<<"   |       0、注销登录          |   "<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"************************************"<<endl;
    cout<<endl;
}

void Teacher::read_tea_file(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    ReservationSystem rs_t;
    rs_t.Init_Tea_ReadFile(TeaInfo,CRoomOrder);
}

void Teacher::save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_CRO,ios::trunc);

    //2、保存文件
    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin(); it1!=CRoomOrder.end(); it1++)
    {
        ofs<<it1->first.CR_index<<"\t"
           <<it1->first.CR_state<<"\t"
           <<it1->first.capacity<<"\t"
           <<":"<<endl;

        for(vector<Order>::iterator it2=it1->second.begin(); it2!=it1->second.end(); it2++)
        {
            ofs<<it2->Applicant<<"\t"
               <<it2->OD_state<<"\t"
               <<it2->Week<<"\t"
               <<it2->time<<endl;
        }
    }

    //3关闭文件
    ofs.close();
}

void Teacher::Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Teacher_menu();

    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin();it1!=CRoomOrder.end();it1++)
    {
        cout<<it1->first.CR_index<<"机房";

        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
                cout<<endl<<"\t预约人："<<it2->Applicant
                    <<"\t预约时间："<<it2->get_week()
                    <<"\t预约时段："<<it2->get_time()
                    <<"\t预约状态："<<this->get_odstate_stu(it2->OD_state)<<endl;
        }

        if(it1->first.CR_state=="0")
        {
             cout<<"\t无预约信息"<<endl;
        }

        cout<<"-------------------------------------------------------"<<endl;
    }
}

void Teacher::Audit_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Teacher_menu();

    int index=0;
    vector<Order>::iterator* it=new vector<Order>::iterator[21];

    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin();it1!=CRoomOrder.end();it1++)
    {
        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
            if(it2->OD_state=="1")
            {
                cout<<index+1<<"、";
                cout<<it1->first.CR_index<<"机房";
                cout<<"\t预约人："<<it2->Applicant
                    <<"\t预约时间："<<it2->get_week()
                    <<"\t预约时段："<<it2->get_time()
                    <<"\t预约状态："<<this->get_odstate_tea(it2->OD_state)<<endl;

                it[index]=it2;
                index++;
            }
        }
    }

    cout<<endl<<"请选择要审核的预约(按\"0\"返回)：";
    int can_od;
    cin>>can_od;

    if(can_od<index+1 && can_od>0)
    {
        cout<<"1、通过"<<endl
            <<"2、不通过"<<endl
            <<"是否通过申请(按\"0\"返回)?";

        int is_pass;
        cin>>is_pass;
        if(is_pass==1)
        {
            //it是一个vector<order>的迭代器（相当于指针），及it存放的是预约--map容器的地址
            //该迭代器可指向CRoomOredr，改变其中参数
            it[can_od-1]->OD_state="3";
            cout<<this->get_odstate_tea(it[can_od-1]->OD_state)<<endl;

            delete[] it;
            it=NULL;
        }

        else if(is_pass==2)
        {
            it[can_od-1]->OD_state="0";
            cout<<this->get_odstate_tea(it[can_od-1]->OD_state)<<endl;

            delete[] it;
            it=NULL;
        }

        this->save_ComRoom(CRoomOrder);
    }

    delete[] it;
    it=NULL;
    return;
}

string Teacher::get_odstate_stu(string od_state)
{
    if(od_state=="0")   return "预约失败";
    if(od_state=="1")   return "审核中";
    if(od_state=="2")   return "已取消预约";
    if(od_state=="3")   return "预约成功";
    return "";
}

string Teacher::get_odstate_tea(string od_state)
{
    if(od_state=="0")   return "审核不通过";
    if(od_state=="1")   return "待审核";
    if(od_state=="3")   return "审核通过";
    return "";
}
