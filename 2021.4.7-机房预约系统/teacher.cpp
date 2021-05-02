#include <iostream>

using namespace std;

#include "ReservationSystem.h"

#define filename_tea "./file/��ʦ��Ϣ.txt"
#define filename_CRO "./file/����-ԤԼ��¼.txt"

void Teacher::Registration_menu(vector<Teacher> &TeaInfo)
{
    cout<<"������ְ���ţ�";
    string TeaNum;
    cin>>TeaNum;

    cout<<"������������";
    string Name;
    cin>>Name;

    cout<<"���������룺";
    string Password;
    cin>>Password;

    Teacher tea_t;
    tea_t.I_Name=Name;
    tea_t.I_Password=Password;
    tea_t.TeaNum=TeaNum;

    TeaInfo.push_back(tea_t);

    this->save_Teafile(TeaInfo);

    cout<<"ע��ɹ���"<<endl;
}

void Teacher::save_Teafile(vector<Teacher> &TeaInfo)
{
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_tea,ios::trunc);

    //2�������ļ�
    for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();it++)
    {
        ofs<<it->TeaNum<<"\t"
           <<it->I_Name<<"\t"
           <<it->I_Password<<endl;
    }

    //3�ر��ļ�
    ofs.close();
}

void Teacher::Login_menu(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{

    while(1)
    {
        system("cls");

        ReservationSystem rs_a;
        rs_a.menu_choice();

        cout<<"�������ʦְ���ţ�";
        cin>>this->TeaNum;

        for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();it++)
        {

            if(it->TeaNum==this->TeaNum)
            {
                while(1)
                {
                    cout<<"������������";
                    cin>>this->I_Name;

                        if(it->I_Name==this->I_Name)
                        {
                            while(1)
                            {
                                cout<<"���������룺";
                                cin>>this->I_Password;

                                if(it->I_Password==this->I_Password)
                                {
                                    cout<<endl<<"��¼�ɹ���"<<endl;
                                    cout<<"��ӭ������ʦ "<<this->I_Name<<endl;
                                    system("pause");
                                    system("cls");

                                    this->Teacher_main(TeaInfo,CRoomOrder);

                                    return;
                                }

                                cout<<endl<<"����������������룡"<<endl<<endl;
                            }
                        }
                    cout<<endl<<"ְ������������ƥ�䣡���������룡"<<endl<<endl;

                }
            }
        }

        cout<<"ְ�����޼�¼��"<<endl;
        cout<<"�Ƿ���������?(y/n)"<<endl;

        char ch;
        cin>>ch;
        if(ch=='n') break;

    }

}

void Teacher::Teacher_main(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    while(1)
    {
        //��ӡ�˵�
        this->Teacher_menu();

        //��ȡ�ļ�
        this->read_tea_file(TeaInfo,CRoomOrder);

        cout<<"����в�����";
        int choice;
        cin>>choice;

        //2��ѡ��
        switch(choice)
        {
        case 0://ע��
            cout<<"ע���ɹ���"<<endl;
            return;
        case 1://�鿴����ԤԼ
            this->Veiw_All_Order(CRoomOrder);
            break;
        case 2://���ԤԼ
            this->Audit_All_Order(CRoomOrder);
            break;
        }

        //3������
        system("pause");
        system("cls");
    }
}

void Teacher::Teacher_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      ��ӭ������ʦ    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |       1���鿴����ԤԼ      |   "<<endl;
    cout<<"   |       2�����ԤԼ          |   "<<endl;
    cout<<"   |       0��ע����¼          |   "<<endl;
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
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_CRO,ios::trunc);

    //2�������ļ�
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

    //3�ر��ļ�
    ofs.close();
}

void Teacher::Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");
    this->Teacher_menu();

    for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it1=CRoomOrder.begin();it1!=CRoomOrder.end();it1++)
    {
        cout<<it1->first.CR_index<<"����";

        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
                cout<<endl<<"\tԤԼ�ˣ�"<<it2->Applicant
                    <<"\tԤԼʱ�䣺"<<it2->get_week()
                    <<"\tԤԼʱ�Σ�"<<it2->get_time()
                    <<"\tԤԼ״̬��"<<this->get_odstate_stu(it2->OD_state)<<endl;
        }

        if(it1->first.CR_state=="0")
        {
             cout<<"\t��ԤԼ��Ϣ"<<endl;
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
                cout<<index+1<<"��";
                cout<<it1->first.CR_index<<"����";
                cout<<"\tԤԼ�ˣ�"<<it2->Applicant
                    <<"\tԤԼʱ�䣺"<<it2->get_week()
                    <<"\tԤԼʱ�Σ�"<<it2->get_time()
                    <<"\tԤԼ״̬��"<<this->get_odstate_tea(it2->OD_state)<<endl;

                it[index]=it2;
                index++;
            }
        }
    }

    cout<<endl<<"��ѡ��Ҫ��˵�ԤԼ(��\"0\"����)��";
    int can_od;
    cin>>can_od;

    if(can_od<index+1 && can_od>0)
    {
        cout<<"1��ͨ��"<<endl
            <<"2����ͨ��"<<endl
            <<"�Ƿ�ͨ������(��\"0\"����)?";

        int is_pass;
        cin>>is_pass;
        if(is_pass==1)
        {
            //it��һ��vector<order>�ĵ��������൱��ָ�룩����it��ŵ���ԤԼ--map�����ĵ�ַ
            //�õ�������ָ��CRoomOredr���ı����в���
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
    if(od_state=="0")   return "ԤԼʧ��";
    if(od_state=="1")   return "�����";
    if(od_state=="2")   return "��ȡ��ԤԼ";
    if(od_state=="3")   return "ԤԼ�ɹ�";
    return "";
}

string Teacher::get_odstate_tea(string od_state)
{
    if(od_state=="0")   return "��˲�ͨ��";
    if(od_state=="1")   return "�����";
    if(od_state=="3")   return "���ͨ��";
    return "";
}
