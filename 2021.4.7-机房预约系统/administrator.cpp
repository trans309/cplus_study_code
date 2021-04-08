#include <iostream>

using namespace std;

#include "administrator.h"
#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "./file/管理员信息.txt"
#define filename_tea "./file/教师信息.txt"
#define filename_stu "./file/学生信息.txt"
#define filename_ComRoom "./file/机房信息.txt"

#define MAX_CAPACITY 20 //机房最大容量

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

void Administrator::Login_menu(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
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
                while(1)
                {
                    cout<<"请输入密码：";
                    cin>>this->I_Password;

                    if(it->I_Password==this->I_Password)
                    {
                        cout<<endl<<"登录成功！"<<endl;
                        cout<<"欢迎您！管理员"<<it->I_Name<<endl;
                        system("pause");
                        system("cls");
                        this->Administrator_main(ComRoomInfo,AdminInfo,TeaInfo,StuInfo);
                        return;
                    }

                    cout<<"密码错误！请重新输入！"<<endl;

                    system("pause");
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
    ofs.open(filename_ad,ios::trunc);

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

void Administrator::Administrator_main(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    while(1)
    {
        //打印菜单
        this->Administrator_menu();

        //读取文件
        this->read_file(ComRoomInfo,AdminInfo,TeaInfo,StuInfo);

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
            this->teacher_modify(TeaInfo);
            break;
        case 2://添加/删除学生账号
            this->student_modify(StuInfo);
            break;
        case 3://查看所有教师/学生账号
            this->TS_veiw(TeaInfo,StuInfo);
            break;
        case 4://修改机房信息
            this->computerroom_modify_main(ComRoomInfo);
            break;
        }

        //3、清屏
        system("pause");
        system("cls");
    }
}

void Administrator::read_file(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    ReservationSystem rs_t;

    rs_t.init_readfile(ComRoomInfo,AdminInfo,TeaInfo,StuInfo);
}

void Administrator::teacher_modify(vector<Teacher> &TeaInfo)
{
    system("cls");

    cout<<"|-----------------|"<<endl;
    cout<<"| 1、添加教师账号 |"<<endl;
    cout<<"| 2、删除教师账号 |"<<endl;
    cout<<"| 0、返回上一级   |"<<endl;
    cout<<"|-----------------|"<<endl;
    cout<<endl<<"请选择操作：";
    int t;
    cin>>t;

    if(t==0)
    {
        return;
    }

    if(t==1)
    {
        Teacher tea;
        cout<<"请输入职工号：";
        cin>>tea.TeaNum;
        cout<<"请输入姓名：";
        cin>>tea.I_Name;
        cout<<"请输入密码：";
        cin>>tea.I_Password;

        TeaInfo.push_back(tea);

        this->save_Teacher(TeaInfo);

        cout<<"添加成功！"<<endl;
    }

    if(t==2)
    {
        Teacher tea_t;
        cout<<"请输入删除教师职工编号：";
        cin>>tea_t.TeaNum;

        for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();)
        {
            if(it->TeaNum==tea_t.TeaNum)
                it=TeaInfo.erase(it);

                else
                    it++;
        }

        this->save_Teacher(TeaInfo);

        cout<<"删除成功！"<<endl;
    }
}

void Administrator::student_modify(vector<Student> &StuInfo)
{
    system("cls");


    cout<<"|-----------------|"<<endl;
    cout<<"| 1、添加学生账号 |"<<endl;
    cout<<"| 2、删除学生账号 |"<<endl;
    cout<<"| 0、返回上一级   |"<<endl;
    cout<<"|-----------------|"<<endl;
    cout<<endl<<"请选择操作：";
    int t;
    cin>>t;

    if(t==0)
    {
        return;
    }

    if(t==1)
    {
        Student stu;
        cout<<"请输入学号：";
        cin>>stu.StuNum;
        cout<<"请输入姓名：";
        cin>>stu.I_Name;
        cout<<"请输入密码：";
        cin>>stu.I_Password;

        StuInfo.push_back(stu);

        this->save_Student(StuInfo);

        cout<<"添加成功！"<<endl;
    }

    if(t==2)
    {
        Student stu_t;
        cout<<"请输入删除学生学号：";
        cin>>stu_t.StuNum;

//        cout<<StuInfo.size()<<endl;
//        for(vector<Student>::iterator it2=StuInfo.begin();it2!=StuInfo.end();it2++)
//        {
//            cout<<"\t学号："<<it2->StuNum
//                <<"\t学生姓名："<<it2->I_Name
//                <<"\t密码："<<it2->I_Password<<endl;
//        }

        for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();)
        {
//            cout<<"\t学号："<<it->StuNum
//                <<"\t学生姓名："<<it->I_Name
//                <<"\t密码："<<it->I_Password<<endl;

            if(it->StuNum==stu_t.StuNum)
                it=StuInfo.erase(it);//erase删除元素后返回下一个元素的迭代器，≈ ++操作

                else
                    it++;//erase删除元素后不进行++操作，当删除最后一个元素时，返回的迭代器指向NULL，此时++会导致程序崩溃


//            cout<<"\t学号："<<it->StuNum
//                <<"\t学生姓名："<<it->I_Name
//                <<"\t密码："<<it->I_Password<<endl;

//            cout<<"---------------"<<endl;
        }

//        cout<<StuInfo.size()<<endl;
//        for(vector<Student>::iterator it1=StuInfo.begin();it1!=StuInfo.end();it1++)
//        {
//            cout<<"\t学号："<<it1->StuNum
//                <<"\t学生姓名："<<it1->I_Name
//                <<"\t密码："<<it1->I_Password<<endl;
//        }

        this->save_Student(StuInfo);

        cout<<"删除成功！"<<endl;
    }
}

void Administrator::save_Teacher(vector<Teacher> &TeaInfo)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_tea,ios::trunc);

    //2、保存文件
    for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();it++)
    {
        ofs<<it->TeaNum<<"\t"<<it->I_Name<<"\t"<<it->I_Password<<endl;
    }

    //3关闭文件
    ofs.close();
}

void Administrator::save_Student(vector<Student> &StuInfo)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_stu,ios::trunc);

    //2、保存文件
    for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();it++)
    {
        ofs<<it->StuNum<<"\t"<<it->I_Name<<"\t"<<it->I_Password<<endl;
    }

    //3关闭文件
    ofs.close();
}

void Administrator::TS_veiw(vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    if(TeaInfo.size()==0)
//    if(TeaInfo.begin()==TeaInfo.end())
    {
        cout<<"无教师账号！"<<endl;
    }
    else
    {
        cout<<"教师账号："<<endl;
        for(vector<Teacher>::iterator it1=TeaInfo.begin();it1!=TeaInfo.end();it1++)
        {
            cout<<"\t职工号："<<it1->TeaNum
                <<"\t教师姓名："<<it1->I_Name
                <<"\t密码："<<it1->I_Password<<endl;
        }
    }


    cout<<"---------------------"<<endl;

    if(StuInfo.size()==0)
//    if(StuInfo.begin()==StuInfo.end())
    {
        cout<<"无学生账号！"<<endl;
    }
    else
    {
        cout<<"学生账号："<<endl;
        for(vector<Student>::iterator it2=StuInfo.begin();it2!=StuInfo.end();it2++)
        {
            cout<<"\t学号："<<it2->StuNum
                <<"\t学生姓名："<<it2->I_Name
                <<"\t密码："<<it2->I_Password<<endl;
        }
    }
}

void Administrator::computerroom_modify_main(map<int,ComputerRoom> &ComRoomInfo)
{
    system("cls");

    while(1)
    {
        ReservationSystem rs_t;
        rs_t.read_ComRoomFile(ComRoomInfo);

        cout<<"|-----------------|"<<endl;
        cout<<"| 1、更改机房信息 |"<<endl;
        cout<<"| 2、打印机房信息 |"<<endl;
        cout<<"| 0、返回上一级   |"<<endl;
        cout<<"|-----------------|"<<endl;
        cout<<endl<<"请选择操作：";
        int t;
        cin>>t;

        if(t==1)
        {
            this->computerroom_modify(ComRoomInfo);
        }

        else if(t==2)
        {
            if(ComRoomInfo.size()==0)   cout<<"无机房信息！"<<endl;
            for(map<int,ComputerRoom>::iterator it=ComRoomInfo.begin();it!=ComRoomInfo.end();it++)
            {
                cout<<it->first<<"号机房"
                    <<"\t容量："<<it->second.capacity;

                if(it->second.state==1)
                {
                    cout<<"\t机房状态：已预约";
                    cout<<"\t预约时间："<<it->second.get_week()
                        <<"\t预约时段："<<it->second.get_time()<<endl;
                }

                else
                {
                    cout<<"\t机房状态：闲置"<<endl;
                }
            }
        }

        else if(t==0)   return;

        system("pause");
        system("cls");
    }
}

void Administrator::computerroom_modify(map<int,ComputerRoom> &ComRoomInfo)
{
        system("cls");

    while(1)
    {
        cout<<"|-----------------|"<<endl;
        cout<<"| 1、增加机房信息 |"<<endl;
        cout<<"| 2、删除机房信息 |"<<endl;
        cout<<"| 0、返回上一级   |"<<endl;
        cout<<"|-----------------|"<<endl;
        cout<<endl<<"请选择操作：";
        int t;
        cin>>t;

        if(t==0)   return;

        else if(t==1)
        {
            ComputerRoom com_in;

            cout<<"请设置机房容量：";
            int i;
            cin>>i;
            com_in.capacity=i;

            int index;

            //添加新机房
            for(index=1;index<=MAX_CAPACITY;index++)
            {
                //查找缺少的机房编号
                if(ComRoomInfo.find(index) == ComRoomInfo.end())
                {
                    ComRoomInfo.insert(make_pair(index,com_in));
                    break;
                }

            }

            cout<<"添加成功！"<<endl;
            this->save_ComRoom(ComRoomInfo);
        }

        else if(t==2)
        {
            cout<<"请输入要删除的机房：";
            int t;
            cin>>t;

            if(ComRoomInfo.find(t)==ComRoomInfo.end())
            {
                cout<<"无此机房信息！"<<endl;
            }

            else
            {
                ComRoomInfo.erase(ComRoomInfo.find(t));
                this->save_ComRoom(ComRoomInfo);
            }
        }


        system("pause");
        system("cls");
    }
}

void Administrator::save_ComRoom(map<int,ComputerRoom> &ComRoomInfo)
{
    //1、打开文件
    ofstream ofs;
    ofs.open(filename_ComRoom,ios::trunc);

    //2、保存文件
    for(map<int,ComputerRoom>::iterator it=ComRoomInfo.begin();it!=ComRoomInfo.end();it++)
    {
        ofs<<it->first
            <<"\t"<<it->second.capacity
            <<"\t"<<it->second.state
            <<"\t"<<it->second.Week
            <<"\t"<<it->second.time<<endl;
    }

    //3关闭文件
    ofs.close();
}



