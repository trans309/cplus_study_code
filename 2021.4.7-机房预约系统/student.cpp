#include <iostream>

using namespace std;

#include "ReservationSystem.h"

#include <algorithm>

#define filename_stu "./file/学生信息.txt"
#define filename_CRO "./file/机房-预约记录.txt"

void Student::Registration_menu(vector<Student> &StuInfo)
{
    cout<<"请输入学号：";
    string StuNum;
    cin>>StuNum;

    cout<<"请输入姓名：";
    string Name;
    cin>>Name;

    cout<<"请输入密码：";
    string Password;
    cin>>Password;

    Student stu_t;
    stu_t.I_Name=Name;
    stu_t.I_Password=Password;
    stu_t.StuNum=StuNum;

    StuInfo.push_back(stu_t);

    this->save_Stufile(StuInfo);

    cout<<"注册成功！"<<endl;
}

void Student::save_Stufile(vector<Student> &StuInfo)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_stu,ios::trunc);

    //2、保存文件
    for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();it++)
    {
        ofs<<it->StuNum<<"\t"
           <<it->I_Name<<"\t"
           <<it->I_Password<<endl;
    }

    //3关闭文件
    ofs.close();
}

void Student::Login_menu(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{

    while(1)
    {
        system("cls");

        ReservationSystem rs_a;
        rs_a.menu_choice();

        cout<<"请输入学生学号：";
        cin>>this->StuNum;

        for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();it++)
        {

            if(it->StuNum==this->StuNum)
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
                                    cout<<"欢迎您！学生代表 "<<this->I_Name<<endl;
                                    system("pause");
                                    system("cls");

                                    this->Student_main(StuInfo,CRoomOrder);

                                    return;
                                }

                                cout<<endl<<"密码错误！请重新输入！"<<endl<<endl;
                            }
                        }
                    cout<<endl<<"学号与姓名不匹配！请重新输入！"<<endl<<endl;

                }
            }
        }

        cout<<"学号无记录！"<<endl;
        cout<<"是否重新输入?(y/n)"<<endl;

        char ch;
        cin>>ch;
        if(ch=='n') break;

    }

}

void Student::Student_main(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    while(1)
    {
        //打印菜单
        this->Student_menu();

        //读取文件
        this->read_stu_file(StuInfo,CRoomOrder);

        cout<<"请进行操作：";
        int choice;
        cin>>choice;

        //2、选择
        switch(choice)
        {
        case 0://注销
            cout<<"注销成功！"<<endl;
            return;
        case 1://申请预约
            this->ApplyFor_Order(CRoomOrder);
            break;
        case 2://取消预约
            this->CancelFor_Order(CRoomOrder);
            break;
        case 3://查看我的预约
            this->Veiw_My_Order(CRoomOrder);
            break;
        case 4://查看所有预约预约
            this->Veiw_All_Order(CRoomOrder);
            break;
        }

        //3、清屏
        system("pause");
        system("cls");
    }
}

void Student::Student_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      欢迎您！学生代表    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |       1、申请预约          |   "<<endl;
    cout<<"   |       2、取消预约          |   "<<endl;
    cout<<"   |       3、查看我的预约      |   "<<endl;
    cout<<"   |       4、查看所有预约      |   "<<endl;
    cout<<"   |       0、注销登录          |   "<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"************************************"<<endl;
    cout<<endl;
}

void Student::read_stu_file(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    ReservationSystem rs_t;
    rs_t.Init_Stu_ReadFile(StuInfo,CRoomOrder);
}

void Student::ApplyFor_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Student_menu();

    map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it;

    for(it=CRoomOrder.begin();it!=CRoomOrder.end();it++)
    {
        cout<<it->first.CR_index<<"机房"
        <<"\t机房容量："<<it->first.capacity<<endl;
    }

    ComputerRoom com_order;

    cout<<"请选择机房：";
    cin>>com_order.CR_index;

    it=CRoomOrder.find(com_order);

    if(it==CRoomOrder.end())
    {
        cout<<"无此机房信息！预约失败！"<<endl;
        return;
    }

    com_order.capacity=it->first.capacity;
    com_order.CR_state="1";

    Order od_inp;
    od_inp.Applicant=this->I_Name;
    od_inp.OD_state="1";

    cout<<"请选择预约时间/星期（1~7）：";
    cin>>od_inp.Week;

    cout<<"1、早上"<<endl
        <<"2、下午"<<endl
        <<"3、晚上"<<endl
        <<"请选择预约时间段（1~3）：";
    cin>>od_inp.time;

    for(vector<Order>::iterator itv=it->second.begin();itv!=it->second.end();itv++)
    {
        if(*itv==od_inp&&(itv->OD_state=="1"||itv->OD_state=="3"))
        {
            cout<<"该时间已存在预约！请重新预约！"<<endl;
            return;
        }
    }

    it->second.push_back(od_inp);

    cout<<"已申请预约，审核中!"<<endl;

    vector<Order>::iterator ito1=it->second.begin();
    vector<Order>::iterator ito2=it->second.end();
    sort(ito1,ito2,Order_Sort());//按预约人，星期，时间段升序排

    vector<Order> vos_inp=it->second;

    CRoomOrder.erase(it);
    CRoomOrder.insert(make_pair(com_order,vos_inp));

    this->save_ComRoom(CRoomOrder);

}

void Student::save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
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

void Student::CancelFor_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Student_menu();

    int index=0;

    vector<Order>::iterator* it=new vector<Order>::iterator[CRoomOrder.size()*21];

    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin();it1!=CRoomOrder.end();it1++)
    {
        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
            if((it2->OD_state=="1"||it2->OD_state=="3")&&(it2->Applicant==this->I_Name))
            {
                cout<<index+1<<"、"
                    <<it1->first.CR_index<<"机房"
                    <<"\t预约时间："<<it2->get_week()
                    <<"\t预约时段："<<it2->get_time()
                    <<"\t预约状态："<<this->get_odstate(it2->OD_state)<<endl;

                it[index]=it2;
                index++;
            }

        }
    }

//    //test
//    cout<<sizeof(it)<<" "<<sizeof(vector<Order>::iterator);

    cout<<"请选择要取消的预约(按\"0\"返回)：";
    int can_od;
    cin>>can_od;



    if(can_od<index+1 && can_od>0)
    {
        it[can_od-1]->OD_state="2";

        cout<<"取消成功！"<<endl;

        this->save_ComRoom(CRoomOrder);

        delete[] it;
        it=NULL;
    }

    else    cout<<"无该预约！取消失败！"<<endl;

    return;

}

void Student::Veiw_My_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Student_menu();

    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin();it1!=CRoomOrder.end();it1++)
    {
        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
            if(it2->Applicant==this->I_Name)
            {
                cout<<"预约机房："<<it1->first.CR_index
                    <<"\t预约时间："<<it2->get_week()
                    <<"\t预约时段："<<it2->get_time()
                    <<"\t预约状态："<<this->get_odstate(it2->OD_state)<<endl;
            }

        }
    }
}

void Student::Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Student_menu();

    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin();it1!=CRoomOrder.end();it1++)
    {
        cout<<it1->first.CR_index<<"机房";

        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
                cout<<endl<<"\t预约人："<<it2->Applicant
                    <<"\t预约时间："<<it2->get_week()
                    <<"\t预约时段："<<it2->get_time()
                    <<"\t预约状态："<<this->get_odstate(it2->OD_state)<<endl;
        }

        if(it1->first.CR_state=="0")
        {
             cout<<"\t无预约信息"<<endl;
        }

        cout<<"-------------------------------------------------------"<<endl;
    }
}

string Student::get_odstate(string od_state)
{
    if(od_state=="0")   return "预约失败";
    if(od_state=="1")   return "审核中";
    if(od_state=="2")   return "已取消预约";
    if(od_state=="3")   return "预约成功";
    return "";
}
