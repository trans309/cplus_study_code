#include <iostream>

using namespace std;

#include "administrator.h"
#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "����Ա��Ϣ"
#define filename_tea "��ʦ��Ϣ"
#define filename_stu "ѧ����Ϣ"

void Administrator::Administrator_menu()
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

void Administrator::Login_menu()
{

    while(1)
    {
        ReservationSystem rs_a;
        rs_a.menu();

        cout<<"���������Ա������";
        cin>>this->I_Name;

        for(vector<Administrator>::iterator it=ReservationSystem::AdminInfo.begin();it!=ReservationSystem::AdminInfo.end();it++)
        {
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
                    this->Administrator_menu();
                }
            }
        }

        cout<<"�˻������ڣ�"<<endl;
    }

}

void Administrator::save_Adminfile()
{

}



void Administrator::Registration_menu()
{

}
