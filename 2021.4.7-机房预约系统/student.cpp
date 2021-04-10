#include <iostream>

using namespace std;

#include "ReservationSystem.h"

#include <algorithm>

#define filename_stu "./file/ѧ����Ϣ.txt"
#define filename_CRO "./file/����-ԤԼ��¼.txt"

void Student::Registration_menu(vector<Student> &StuInfo)
{
    cout<<"������ѧ�ţ�";
    string StuNum;
    cin>>StuNum;

    cout<<"������������";
    string Name;
    cin>>Name;

    cout<<"���������룺";
    string Password;
    cin>>Password;

    Student stu_t;
    stu_t.I_Name=Name;
    stu_t.I_Password=Password;
    stu_t.StuNum=StuNum;

    StuInfo.push_back(stu_t);

    this->save_Stufile(StuInfo);

    cout<<"ע��ɹ���"<<endl;
}

void Student::save_Stufile(vector<Student> &StuInfo)
{
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_stu,ios::trunc);

    //2�������ļ�
    for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();it++)
    {
        ofs<<it->StuNum<<"\t"
           <<it->I_Name<<"\t"
           <<it->I_Password<<endl;
    }

    //3�ر��ļ�
    ofs.close();
}

void Student::Login_menu(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{

    while(1)
    {
        system("cls");

        ReservationSystem rs_a;
        rs_a.menu_choice();

        cout<<"������ѧ��ѧ�ţ�";
        cin>>this->StuNum;

        for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();it++)
        {

            if(it->StuNum==this->StuNum)
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
                                    cout<<"��ӭ����ѧ������ "<<this->I_Name<<endl;
                                    system("pause");
                                    system("cls");

                                    this->Student_main(StuInfo,CRoomOrder);

                                    return;
                                }

                                cout<<endl<<"����������������룡"<<endl<<endl;
                            }
                        }
                    cout<<endl<<"ѧ����������ƥ�䣡���������룡"<<endl<<endl;

                }
            }
        }

        cout<<"ѧ���޼�¼��"<<endl;
        cout<<"�Ƿ���������?(y/n)"<<endl;

        char ch;
        cin>>ch;
        if(ch=='n') break;

    }

}

void Student::Student_main(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    while(1)
    {
        //��ӡ�˵�
        this->Student_menu();

        //��ȡ�ļ�
        this->read_stu_file(StuInfo,CRoomOrder);

        cout<<"����в�����";
        int choice;
        cin>>choice;

        //2��ѡ��
        switch(choice)
        {
        case 0://ע��
            cout<<"ע���ɹ���"<<endl;
            return;
        case 1://����ԤԼ
            this->ApplyFor_Order(CRoomOrder);
            break;
        case 2://ȡ��ԤԼ
            this->CancelFor_Order(CRoomOrder);
            break;
        case 3://�鿴�ҵ�ԤԼ
            this->Veiw_My_Order(CRoomOrder);
            break;
        case 4://�鿴����ԤԼԤԼ
            this->Veiw_All_Order(CRoomOrder);
            break;
        }

        //3������
        system("pause");
        system("cls");
    }
}

void Student::Student_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      ��ӭ����ѧ������    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |       1������ԤԼ          |   "<<endl;
    cout<<"   |       2��ȡ��ԤԼ          |   "<<endl;
    cout<<"   |       3���鿴�ҵ�ԤԼ      |   "<<endl;
    cout<<"   |       4���鿴����ԤԼ      |   "<<endl;
    cout<<"   |       0��ע����¼          |   "<<endl;
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
        cout<<it->first.CR_index<<"����"
        <<"\t����������"<<it->first.capacity<<endl;
    }

    ComputerRoom com_order;

    cout<<"��ѡ�������";
    cin>>com_order.CR_index;

    it=CRoomOrder.find(com_order);

    if(it==CRoomOrder.end())
    {
        cout<<"�޴˻�����Ϣ��ԤԼʧ�ܣ�"<<endl;
        return;
    }

    com_order.capacity=it->first.capacity;
    com_order.CR_state="1";

    Order od_inp;
    od_inp.Applicant=this->I_Name;
    od_inp.OD_state="1";

    cout<<"��ѡ��ԤԼʱ��/���ڣ�1~7����";
    cin>>od_inp.Week;

    cout<<"1������"<<endl
        <<"2������"<<endl
        <<"3������"<<endl
        <<"��ѡ��ԤԼʱ��Σ�1~3����";
    cin>>od_inp.time;

    for(vector<Order>::iterator itv=it->second.begin();itv!=it->second.end();itv++)
    {
        if(*itv==od_inp&&(itv->OD_state=="1"||itv->OD_state=="3"))
        {
            cout<<"��ʱ���Ѵ���ԤԼ��������ԤԼ��"<<endl;
            return;
        }
    }

    it->second.push_back(od_inp);

    cout<<"������ԤԼ�������!"<<endl;

    vector<Order>::iterator ito1=it->second.begin();
    vector<Order>::iterator ito2=it->second.end();
    sort(ito1,ito2,Order_Sort());//��ԤԼ�ˣ����ڣ�ʱ���������

    vector<Order> vos_inp=it->second;

    CRoomOrder.erase(it);
    CRoomOrder.insert(make_pair(com_order,vos_inp));

    this->save_ComRoom(CRoomOrder);

}

void Student::save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
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
                cout<<index+1<<"��"
                    <<it1->first.CR_index<<"����"
                    <<"\tԤԼʱ�䣺"<<it2->get_week()
                    <<"\tԤԼʱ�Σ�"<<it2->get_time()
                    <<"\tԤԼ״̬��"<<this->get_odstate(it2->OD_state)<<endl;

                it[index]=it2;
                index++;
            }

        }
    }

//    //test
//    cout<<sizeof(it)<<" "<<sizeof(vector<Order>::iterator);

    cout<<"��ѡ��Ҫȡ����ԤԼ(��\"0\"����)��";
    int can_od;
    cin>>can_od;



    if(can_od<index+1 && can_od>0)
    {
        it[can_od-1]->OD_state="2";

        cout<<"ȡ���ɹ���"<<endl;

        this->save_ComRoom(CRoomOrder);

        delete[] it;
        it=NULL;
    }

    else    cout<<"�޸�ԤԼ��ȡ��ʧ�ܣ�"<<endl;

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
                cout<<"ԤԼ������"<<it1->first.CR_index
                    <<"\tԤԼʱ�䣺"<<it2->get_week()
                    <<"\tԤԼʱ�Σ�"<<it2->get_time()
                    <<"\tԤԼ״̬��"<<this->get_odstate(it2->OD_state)<<endl;
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
        cout<<it1->first.CR_index<<"����";

        for(vector<Order>::iterator it2=it1->second.begin();it2!=it1->second.end();it2++)
        {
                cout<<endl<<"\tԤԼ�ˣ�"<<it2->Applicant
                    <<"\tԤԼʱ�䣺"<<it2->get_week()
                    <<"\tԤԼʱ�Σ�"<<it2->get_time()
                    <<"\tԤԼ״̬��"<<this->get_odstate(it2->OD_state)<<endl;
        }

        if(it1->first.CR_state=="0")
        {
             cout<<"\t��ԤԼ��Ϣ"<<endl;
        }

        cout<<"-------------------------------------------------------"<<endl;
    }
}

string Student::get_odstate(string od_state)
{
    if(od_state=="0")   return "ԤԼʧ��";
    if(od_state=="1")   return "�����";
    if(od_state=="2")   return "��ȡ��ԤԼ";
    if(od_state=="3")   return "ԤԼ�ɹ�";
    return "";
}
