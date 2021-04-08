#include <iostream>

using namespace std;

#include "ReservationSystem.h"
#include "administrator.h"
#include "student.h"
#include "teacher.h"
#include "computer_room.h"

#define filename_ad "./file/����Ա��Ϣ.txt"
#define filename_tea "./file/��ʦ��Ϣ.txt"
#define filename_stu "./file/ѧ����Ϣ.txt"
#define filename_ComRoom "./file/������Ϣ.txt"

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

        cout<<"��ѡ�������";
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
            cout<<"�������룬���������룡"<<endl;
            break;
        }

        system("pause");
        system("cls");
    }



}

void ReservationSystem::Exit()
{
    cout<<"��ӭ�´�ʹ�ã�"<<endl;
    exit(0);
}



//other system

void ReservationSystem::menu()
{
    cout<<"*****************************"<<endl;
    cout<<"    ��ӭʹ�û���ԤԼϵͳ"<<endl;
    cout<<"*****************************"<<endl;
    cout<<"     |----------------|      "<<endl;
    cout<<"     |    1������Ա   |      "<<endl;
    cout<<"     |    2����ʦ     |      "<<endl;
    cout<<"     |    3��ѧ��     |      "<<endl;
    cout<<"     |    0���˳�     |      "<<endl;
    cout<<"     |----------------|      "<<endl;
    cout<<"*****************************"<<endl;
    cout<<endl;
}

void ReservationSystem::menu_choice()
{
    cout<<"     |----------------|      "<<endl;
    cout<<"     |    1��ע��     |      "<<endl;
    cout<<"     |    2����¼     |      "<<endl;
    cout<<"     |    0������     |      "<<endl;
    cout<<"     |----------------|      "<<endl;
}

void ReservationSystem::read_IentityFile(int type,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    //1�����ļ�
    ifstream ifs;
    if(type==1) ifs.open(filename_ad,ios::in);
    if(type==2) ifs.open(filename_tea,ios::in);
    if(type==3) ifs.open(filename_stu,ios::in);

    //2���ļ��Ƿ����
    if(!ifs.is_open())
    {
//        cout<<"�ļ�������";
        return;
    }

    //3���ļ��Ƿ�Ϊ��
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {

//        cout<<"�ļ�Ϊ��";
        return;

    }

    //4���ļ���ȡ
    ifs.putback(ch);

    if(type==1)
    {
//        cout<<"�ļ���ȡ�ɹ�"<<endl;
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

    //5���ر��ļ�
    ifs.close();
}

void ReservationSystem::read_ComRoomFile(map<int,ComputerRoom> &ComInfo)
{
        //1�����ļ�
    ifstream ifs;
    ifs.open(filename_ComRoom,ios::in);

    //2���ļ��Ƿ����
    if(!ifs.is_open())
    {
//        cout<<"�ļ�������";
        return;
    }

    //3���ļ��Ƿ�Ϊ��
    char ch;
    ch=ifs.get();
    if(ifs.eof())
    {

//        cout<<"�ļ�Ϊ��";
        return;

    }

    //4���ļ���ȡ
    ifs.putback(ch);
    int index;


//    cout<<"�ļ���ȡ�ɹ�"<<endl;
    ComputerRoom com_t;
    while(ifs>>index&&ifs>>com_t.capacity&&ifs>>com_t.state&&ifs>>com_t.Week&&ifs>>com_t.time)
    {
        ComInfo.insert(make_pair(index,com_t));
    }

    //5���ر��ļ�
    ifs.close();
}

void ReservationSystem::init_readfile(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
//    cout<<"����init";

    AdminInfo.clear();
    read_IentityFile(1,AdminInfo,TeaInfo,StuInfo);

    TeaInfo.clear();
    read_IentityFile(2,AdminInfo,TeaInfo,StuInfo);

    StuInfo.clear();
    read_IentityFile(3,AdminInfo,TeaInfo,StuInfo);

    ComRoomInfo.clear();
    read_ComRoomFile(ComRoomInfo);
}
