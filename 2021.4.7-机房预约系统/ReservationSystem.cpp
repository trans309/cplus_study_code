#include <iostream>

using namespace std;

#include "ReservationSystem.h"
#include "administrator.h"

#define filename_ad "����Ա��Ϣ"
#define filename_tea "��ʦ��Ϣ"
#define filename_stu "ѧ����Ϣ"

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

        cout<<"��ѡ�������";
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

void ReservationSystem::read_IentityFile(int type)
{
    //1�����ļ�
    ifstream ifs;
    if(type==1) ifs.open(filename_ad,ios::in);
    if(type==2) ifs.open(filename_tea,ios::in);
    if(type==3) ifs.open(filename_stu,ios::in);
    //2���ļ��Ƿ����
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

    //3���ļ��Ƿ�Ϊ��
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

    //4���ļ���ȡ
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

    //5���ر��ļ�
    ifs.close();
}
