#include <iostream>

using namespace std;

#include "administrator.h"
#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "./file/����Ա��Ϣ.txt"
#define filename_tea "./file/��ʦ��Ϣ.txt"
#define filename_stu "./file/ѧ����Ϣ.txt"

void Administrator::Administrator_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      ��ӭ��������Ա    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |  1�����/ɾ����ʦ�˺�      |   "<<endl;
    cout<<"   |  2�����/ɾ��ѧ���˺�      |   "<<endl;
    cout<<"   |  3���鿴���н�ʦ/ѧ���˺�  |   "<<endl;
    cout<<"   |  4���޸Ļ�����Ϣ           |   "<<endl;
    cout<<"   |  0��ע����¼               |   "<<endl;
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

        cout<<"���������Ա������";
        cin>>this->I_Name;

        for(vector<Administrator>::iterator it=AdminInfo.begin();it!=AdminInfo.end();it++)
        {
            //����
//            cout<<it->I_Name<<endl<<it->I_Password<<endl;
//            cout<<"����"<<endl;

            if(it->I_Name==this->I_Name)
            {
                cout<<"���������룺";
                cin>>this->I_Password;
                if(it->I_Password==this->I_Password)
                {
                    cout<<endl<<"��¼�ɹ���"<<endl;
                    cout<<"��ӭ��������Ա"<<it->I_Name<<endl;
                    system("pause");
                    system("cls");
                    this->Administrator_main(AdminInfo,TeaInfo,StuInfo);
                    return;
                }
            }
        }

        cout<<"�˻������ڣ�"<<endl;
        cout<<"�Ƿ���������?(y/n)"<<endl;

        char ch;
        cin>>ch;
        if(ch=='n') break;

    }

}

void Administrator::save_Adminfile(vector<Administrator> &AdminInfo)
{
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_ad,ios::out|ios::app);

    //2�������ļ�
    for(vector<Administrator>::iterator it=AdminInfo.begin();it!=AdminInfo.end();it++)
    {
        ofs<<it->I_Name<<"\t"<<it->I_Password<<endl;
    }

    //3�ر��ļ�
    ofs.close();
}



void Administrator::Registration_menu(vector<Administrator> &AdminInfo)
{
    cout<<"�������˺ţ�";
    string Name;
    cin>>Name;

    cout<<"���������룺";
    string Password;
    cin>>Password;

    Administrator ad_t;
    ad_t.I_Name=Name;
    ad_t.I_Password=Password;

    AdminInfo.push_back(ad_t);
//    this->AdminInfo.push_back(ad_t);

    this->save_Adminfile(AdminInfo);

    cout<<"ע��ɹ���"<<endl;
}

void Administrator::Administrator_main(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    while(1)
    {
        //��ӡ�˵�
        this->Administrator_menu();

        cout<<"����в�����";
        int choice;
        cin>>choice;

        //2��ѡ��
        switch(choice)
        {
        case 0://ע��
            cout<<"ע���ɹ���"<<endl;
            return;
        case 1://���/ɾ����ʦ�˺�
            break;
        case 2://���/ɾ��ѧ���˺�
            break;
        case 3://�鿴���н�ʦ/ѧ���˺�
            break;
        case 4://�޸Ļ�����Ϣ
            break;
        }

        //3������
        system("pause");
        system("cls");
    }
}

void Administrator::read_file(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    ReservationSystem rs_t;

    rs_t.init_readfile(AdminInfo,TeaInfo,StuInfo);
}
