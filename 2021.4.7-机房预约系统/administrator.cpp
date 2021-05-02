#include <iostream>

using namespace std;

#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "./file/����Ա��Ϣ.txt"
#define filename_tea "./file/��ʦ��Ϣ.txt"
#define filename_stu "./file/ѧ����Ϣ.txt"
#define filename_CRO "./file/����-ԤԼ��¼.txt"

#define MAX_CAPACITY 5 //�����������

void Administrator::Administrator_menu()
{
    cout<<"************************************"<<endl;
    cout<<"      ��ӭ��������Ա    "<<this->I_Name<<endl;
    cout<<"************************************"<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"   |  1�����/ɾ����ʦ�˺�      |   "<<endl;
    cout<<"   |  2�����/ɾ��ѧ���˺�      |   "<<endl;
    cout<<"   |  3���鿴���н�ʦ/ѧ���˺�  |   "<<endl;
    cout<<"   |  4���������ԤԼ           |   "<<endl;
    cout<<"   |  5���޸Ļ�����Ϣ           |   "<<endl;
    cout<<"   |  0��ע����¼               |   "<<endl;
    cout<<"   |----------------------------|   "<<endl;
    cout<<"************************************"<<endl;
    cout<<endl;
}

void Administrator::Login_menu(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{

    while(1)
    {
        system("cls");

        ReservationSystem rs_a;
        rs_a.menu_choice();

        cout<<"���������Ա������";
        cin>>this->I_Name;

        for(vector<Administrator>::iterator it=AdminInfo.begin(); it!=AdminInfo.end(); it++)
        {
            //����
//            cout<<it->I_Name<<endl<<it->I_Password<<endl;
//            cout<<"����"<<endl;

            if(it->I_Name==this->I_Name)
            {
                while(1)
                {
                    cout<<"���������룺";
                    cin>>this->I_Password;

                    if(it->I_Password==this->I_Password)
                    {
                        cout<<endl<<"��¼�ɹ���"<<endl;
                        cout<<"��ӭ��������Ա "<<it->I_Name<<endl;
                        system("pause");
                        system("cls");
                        this->Administrator_main(CRoomOrder,AdminInfo,TeaInfo,StuInfo);
                        return;
                    }

                    cout<<"����������������룡"<<endl;

                    system("pause");
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
    ofs.open(filename_ad,ios::trunc);

    //2�������ļ�
    for(vector<Administrator>::iterator it=AdminInfo.begin(); it!=AdminInfo.end(); it++)
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

void Administrator::Administrator_main(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    while(1)
    {
        //��ӡ�˵�
        this->Administrator_menu();

        //��ȡ�ļ�
        this->read_ad_file(CRoomOrder,AdminInfo,TeaInfo,StuInfo);

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
            this->teacher_modify(TeaInfo);
            break;
        case 2://���/ɾ��ѧ���˺�
            this->student_modify(StuInfo);
            break;
        case 3://�鿴���н�ʦ/ѧ���˺�
            this->TS_veiw(TeaInfo,StuInfo);
            break;
        case 4://��ջ���ԤԼ
            this->clear_all_order(CRoomOrder);
            break;
        case 5://�޸Ļ�����Ϣ����ɾ��
            this->computerroom_modify_main(CRoomOrder);
            break;
        }

        //3������
        system("pause");
        system("cls");
    }
}

void Administrator::read_ad_file(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    ReservationSystem rs_t;
    rs_t.Init_Admin_ReadFile(CRoomOrder,AdminInfo,TeaInfo,StuInfo);
//    rs_t.check_CRoom_empty(CRoomOrder);
}

void Administrator::teacher_modify(vector<Teacher> &TeaInfo)
{
    system("cls");

    cout<<"|-----------------|"<<endl;
    cout<<"| 1����ӽ�ʦ�˺� |"<<endl;
    cout<<"| 2��ɾ����ʦ�˺� |"<<endl;
    cout<<"| 0��������һ��   |"<<endl;
    cout<<"|-----------------|"<<endl;
    cout<<endl<<"��ѡ�������";
    int t;
    cin>>t;

    if(t==0)
    {
        return;
    }

    if(t==1)
    {
        Teacher tea;
        cout<<"������ְ���ţ�";
        cin>>tea.TeaNum;
        cout<<"������������";
        cin>>tea.I_Name;
        cout<<"���������룺";
        cin>>tea.I_Password;

        TeaInfo.push_back(tea);

        this->save_Teacher(TeaInfo);

        cout<<"��ӳɹ���"<<endl;
    }

    if(t==2)
    {
        Teacher tea_t;
        cout<<"������ɾ����ʦְ����ţ�";
        cin>>tea_t.TeaNum;

        for(vector<Teacher>::iterator it=TeaInfo.begin(); it!=TeaInfo.end();)
        {
            if(it->TeaNum==tea_t.TeaNum)
                it=TeaInfo.erase(it);

            else
                it++;
        }

        this->save_Teacher(TeaInfo);

        cout<<"ɾ���ɹ���"<<endl;
    }
}

void Administrator::student_modify(vector<Student> &StuInfo)
{
    system("cls");


    cout<<"|-----------------|"<<endl;
    cout<<"| 1�����ѧ���˺� |"<<endl;
    cout<<"| 2��ɾ��ѧ���˺� |"<<endl;
    cout<<"| 0��������һ��   |"<<endl;
    cout<<"|-----------------|"<<endl;
    cout<<endl<<"��ѡ�������";
    int t;
    cin>>t;

    if(t==0)
    {
        return;
    }

    if(t==1)
    {
        Student stu;
        cout<<"������ѧ�ţ�";
        cin>>stu.StuNum;
        cout<<"������������";
        cin>>stu.I_Name;
        cout<<"���������룺";
        cin>>stu.I_Password;

        StuInfo.push_back(stu);

        this->save_Student(StuInfo);

        cout<<"��ӳɹ���"<<endl;
    }

    if(t==2)
    {
        Student stu_t;
        cout<<"������ɾ��ѧ��ѧ�ţ�";
        cin>>stu_t.StuNum;

//        cout<<StuInfo.size()<<endl;
//        for(vector<Student>::iterator it2=StuInfo.begin();it2!=StuInfo.end();it2++)
//        {
//            cout<<"\tѧ�ţ�"<<it2->StuNum
//                <<"\tѧ��������"<<it2->I_Name
//                <<"\t���룺"<<it2->I_Password<<endl;
//        }

        for(vector<Student>::iterator it=StuInfo.begin(); it!=StuInfo.end();)
        {
//            cout<<"\tѧ�ţ�"<<it->StuNum
//                <<"\tѧ��������"<<it->I_Name
//                <<"\t���룺"<<it->I_Password<<endl;

            if(it->StuNum==stu_t.StuNum)
                it=StuInfo.erase(it);//eraseɾ��Ԫ�غ󷵻���һ��Ԫ�صĵ��������� ++����

            else
                it++;//eraseɾ��Ԫ�غ󲻽���++��������ɾ�����һ��Ԫ��ʱ�����صĵ�����ָ��NULL����ʱ++�ᵼ�³������


//            cout<<"\tѧ�ţ�"<<it->StuNum
//                <<"\tѧ��������"<<it->I_Name
//                <<"\t���룺"<<it->I_Password<<endl;

//            cout<<"---------------"<<endl;
        }

//        cout<<StuInfo.size()<<endl;
//        for(vector<Student>::iterator it1=StuInfo.begin();it1!=StuInfo.end();it1++)
//        {
//            cout<<"\tѧ�ţ�"<<it1->StuNum
//                <<"\tѧ��������"<<it1->I_Name
//                <<"\t���룺"<<it1->I_Password<<endl;
//        }

        this->save_Student(StuInfo);

        cout<<"ɾ���ɹ���"<<endl;
    }
}

void Administrator::save_Teacher(vector<Teacher> &TeaInfo)
{
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_tea,ios::trunc);

    //2�������ļ�
    for(vector<Teacher>::iterator it=TeaInfo.begin(); it!=TeaInfo.end(); it++)
    {
        ofs<<it->TeaNum<<"\t"<<it->I_Name<<"\t"<<it->I_Password<<endl;
    }

    //3�ر��ļ�
    ofs.close();
}

void Administrator::save_Student(vector<Student> &StuInfo)
{
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_stu,ios::trunc);

    //2�������ļ�
    for(vector<Student>::iterator it=StuInfo.begin(); it!=StuInfo.end(); it++)
    {
        ofs<<it->StuNum<<"\t"<<it->I_Name<<"\t"<<it->I_Password<<endl;
    }

    //3�ر��ļ�
    ofs.close();
}

void Administrator::TS_veiw(vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    if(TeaInfo.size()==0)
//    if(TeaInfo.begin()==TeaInfo.end())
    {
        cout<<"�޽�ʦ�˺ţ�"<<endl;
    }
    else
    {
        cout<<"��ʦ�˺ţ�"<<endl;
        for(vector<Teacher>::iterator it1=TeaInfo.begin(); it1!=TeaInfo.end(); it1++)
        {
            cout<<"\tְ���ţ�"<<it1->TeaNum
                <<"\t��ʦ������"<<it1->I_Name
                <<"\t���룺"<<it1->I_Password<<endl;
        }
    }


    cout<<"---------------------"<<endl;

    if(StuInfo.size()==0)
//    if(StuInfo.begin()==StuInfo.end())
    {
        cout<<"��ѧ���˺ţ�"<<endl;
    }
    else
    {
        cout<<"ѧ���˺ţ�"<<endl;
        for(vector<Student>::iterator it2=StuInfo.begin(); it2!=StuInfo.end(); it2++)
        {
            cout<<"\tѧ�ţ�"<<it2->StuNum
                <<"\tѧ��������"<<it2->I_Name
                <<"\t���룺"<<it2->I_Password<<endl;
        }
    }
}

void Administrator::computerroom_modify_main(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");

    while(1)
    {
        ReservationSystem rs_t;
        CRoomOrder.clear();
        rs_t.read_CRO_File(CRoomOrder);

        cout<<"|-----------------|"<<endl;
        cout<<"| 1�����Ļ�����Ϣ |"<<endl;
        cout<<"| 2����ӡ������Ϣ |"<<endl;
        cout<<"| 0��������һ��   |"<<endl;
        cout<<"|-----------------|"<<endl;
        cout<<endl<<"��ѡ�������";
        int t;
        cin>>t;

        if(t==1)
        {
            this->computerroom_modify(CRoomOrder);
        }

        else if(t==2)
        {
            if(CRoomOrder.size()==0)   cout<<"�޻�����Ϣ��"<<endl;
            for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it=CRoomOrder.begin(); it!=CRoomOrder.end(); it++)
            {
                cout<<it->first.CR_index<<"�Ż���"
                    <<"\t������"<<it->first.capacity;

                if(it->first.CR_state=="1")
                {
                    if(it->second.size()==21)   cout<<"\t����״̬���ѱ�����������ԤԼ����"<<endl;
                    else cout<<"\t����״̬������ԤԼ��¼"<<endl;

                    for(vector<Order>::iterator it1=it->second.begin(); it1!=it->second.end(); it1++)
                    {
                        if(it1->OD_state=="1" || it1->OD_state=="2" || it1->OD_state=="3")
                        {
                            cout<<"\tԤԼ�ˣ�"<<it1->Applicant
                                <<"\tԤԼ״̬��"<<this->get_OD_state(it1->OD_state)
                                <<"\tԤԼʱ�䣺"<<it1->get_week()
                                <<"\tԤԼʱ�Σ�"<<it1->get_time()<<endl;
                        }

                    }
                    cout<<"-------------------------------------------------------"<<endl;
                }

                else
                {
                    cout<<"\t����״̬������"<<endl
                        <<"-------------------------------------------------------"
                        <<endl;
                }
            }
        }

        else if(t==0)   return;

        system("pause");
        system("cls");
    }
}

void Administrator::computerroom_modify(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    system("cls");

    while(1)
    {
        cout<<"|-----------------|"<<endl;
        cout<<"| 1�����ӻ�����Ϣ |"<<endl;
        cout<<"| 2��ɾ��������Ϣ |"<<endl;
        cout<<"| 3���޸Ļ�����Ϣ |"<<endl;
        cout<<"| 0��������һ��   |"<<endl;
        cout<<"|-----------------|"<<endl;
        cout<<endl<<"��ѡ�������";
        int t;
        cin>>t;

        if(t==0)   return;

        else if(t==1)
        {
            ComputerRoom com_in;
            vector<Order> vod_in;

            cout<<"�����û���������";
            string i;
            cin>>i;
            com_in.capacity=i;

            string index_seed="0123456789";

            int index_num;

//            cout<<CRoomOrder.size()<<endl;

            //����»���
            for(index_num=1;index_num<=MAX_CAPACITY;index_num++)
            {
                string index;
                int ten=index_num/10;//ʮλ
                index+=index_seed[ten];
                int bit=index_num%10;//��λ
                index+=index_seed[bit];

                com_in.CR_index=index;

                if(CRoomOrder.find(com_in)/*�ҵ����ز���Ԫ�ص��������Ҳ�������end�������Ҳ���Ԫ�ؾͻ����*/ == CRoomOrder.end())
                {
                    CRoomOrder.insert(make_pair(com_in,vod_in));
                    cout<<"��ӳɹ���"<<endl;
                    this->save_ComRoom(CRoomOrder);
                    break;
                }

            }

            if(index_num>MAX_CAPACITY &&MAX_CAPACITY != 0)
                {
                    cout<<"�����ѵ����ޣ��޷���ӣ�"<<endl;
                }

//            cout<<CRoomOrder.size()<<endl;
        }

        else if(t==2)
        {
            cout<<"������Ҫɾ���Ļ�����";
            string t;
            cin>>t;

            ComputerRoom cr_t;
            cr_t.CR_index=t;

            map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it=CRoomOrder.find(cr_t);

            if(it==CRoomOrder.end())
            {
                cout<<"�޴˻�����Ϣ��"<<endl;
            }

            else
            {
                CRoomOrder.erase(it);
                cout<<"ɾ���ɹ���"<<endl;
                this->save_ComRoom(CRoomOrder);
            }
        }

        else if(t==3)
        {
            cout<<"������Ҫ�޸ĵĻ�����";
            string t;
            cin>>t;

            ComputerRoom cr_t;
            cr_t.CR_index=t;

            map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it=CRoomOrder.find(cr_t);

            if(it==CRoomOrder.end())
            {
                cout<<"�޴˻�����Ϣ��"<<endl;
            }

            else
            {
                cout<<"�޸�����Ϊ��";
                string capacity;
                cin>>capacity;
                cr_t.capacity=capacity;

                cr_t.CR_state=it->first.CR_state;
                vector<Order> new_od=it->second;

                CRoomOrder.erase(it);
                CRoomOrder.insert(make_pair(cr_t,new_od));
                cout<<"�޸ĳɹ���"<<endl;
                this->save_ComRoom(CRoomOrder);
            }
        }


        system("pause");
        system("cls");
    }
}

void Administrator::save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
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

void Administrator::clear_all_order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder)
{
    cout<<"�Ƿ��������ԤԼ����(y/n)";
    char t;
    cin>>t;

    if(t=='y')
    {
        for(map<ComputerRoom,vector<Order>,less_ComRoom>::iterator it=CRoomOrder.begin(); it!=CRoomOrder.end(); it++)
        {
            //it->first.init_state();
            //it->firstΪconst���Σ������޸�
            //�� CR_index/capacity ��������ɾ�������²���

            vector<Order> empty_order;
            string index=it->first.CR_index;
            string capacity=it->first.capacity;

            ComputerRoom init_state_cr;

            init_state_cr.CR_index=index;
            init_state_cr.capacity=capacity;
            init_state_cr.CR_state="0";

            CRoomOrder.erase(it);
            CRoomOrder.insert(make_pair(init_state_cr,empty_order));

        }

        this->save_ComRoom(CRoomOrder);

        cout<<"����ԤԼ�����"<<endl;

        return;
    }

    cout<<"ȡ����ճɹ���"<<endl;

}

string Administrator::get_OD_state(string od_state)
{
    if(od_state=="1")   return "�����";
    if(od_state=="2")   return "��ȡ��ԤԼ";
    if(od_state=="3")   return "ԤԼ�ɹ�";

    return "";
}
