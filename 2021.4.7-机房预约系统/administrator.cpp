#include <iostream>

using namespace std;

#include "administrator.h"
#include "ReservationSystem.h"

#include <cstdlib>

#define filename_ad "./file/����Ա��Ϣ.txt"
#define filename_tea "./file/��ʦ��Ϣ.txt"
#define filename_stu "./file/ѧ����Ϣ.txt"
#define filename_ComRoom "./file/������Ϣ.txt"

#define MAX_CAPACITY 20 //�����������

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

void Administrator::Login_menu(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
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
                while(1)
                {
                    cout<<"���������룺";
                    cin>>this->I_Password;

                    if(it->I_Password==this->I_Password)
                    {
                        cout<<endl<<"��¼�ɹ���"<<endl;
                        cout<<"��ӭ��������Ա"<<it->I_Name<<endl;
                        system("pause");
                        system("cls");
                        this->Administrator_main(ComRoomInfo,AdminInfo,TeaInfo,StuInfo);
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

void Administrator::Administrator_main(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo)
{
    while(1)
    {
        //��ӡ�˵�
        this->Administrator_menu();

        //��ȡ�ļ�
        this->read_file(ComRoomInfo,AdminInfo,TeaInfo,StuInfo);

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
        case 4://�޸Ļ�����Ϣ
            this->computerroom_modify_main(ComRoomInfo);
            break;
        }

        //3������
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

        for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();)
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

        for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();)
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
    for(vector<Teacher>::iterator it=TeaInfo.begin();it!=TeaInfo.end();it++)
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
    for(vector<Student>::iterator it=StuInfo.begin();it!=StuInfo.end();it++)
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
        for(vector<Teacher>::iterator it1=TeaInfo.begin();it1!=TeaInfo.end();it1++)
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
        for(vector<Student>::iterator it2=StuInfo.begin();it2!=StuInfo.end();it2++)
        {
            cout<<"\tѧ�ţ�"<<it2->StuNum
                <<"\tѧ��������"<<it2->I_Name
                <<"\t���룺"<<it2->I_Password<<endl;
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
        cout<<"| 1�����Ļ�����Ϣ |"<<endl;
        cout<<"| 2����ӡ������Ϣ |"<<endl;
        cout<<"| 0��������һ��   |"<<endl;
        cout<<"|-----------------|"<<endl;
        cout<<endl<<"��ѡ�������";
        int t;
        cin>>t;

        if(t==1)
        {
            this->computerroom_modify(ComRoomInfo);
        }

        else if(t==2)
        {
            if(ComRoomInfo.size()==0)   cout<<"�޻�����Ϣ��"<<endl;
            for(map<int,ComputerRoom>::iterator it=ComRoomInfo.begin();it!=ComRoomInfo.end();it++)
            {
                cout<<it->first<<"�Ż���"
                    <<"\t������"<<it->second.capacity;

                if(it->second.state==1)
                {
                    cout<<"\t����״̬����ԤԼ";
                    cout<<"\tԤԼʱ�䣺"<<it->second.get_week()
                        <<"\tԤԼʱ�Σ�"<<it->second.get_time()<<endl;
                }

                else
                {
                    cout<<"\t����״̬������"<<endl;
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
        cout<<"| 1�����ӻ�����Ϣ |"<<endl;
        cout<<"| 2��ɾ��������Ϣ |"<<endl;
        cout<<"| 0��������һ��   |"<<endl;
        cout<<"|-----------------|"<<endl;
        cout<<endl<<"��ѡ�������";
        int t;
        cin>>t;

        if(t==0)   return;

        else if(t==1)
        {
            ComputerRoom com_in;

            cout<<"�����û���������";
            int i;
            cin>>i;
            com_in.capacity=i;

            int index;

            //����»���
            for(index=1;index<=MAX_CAPACITY;index++)
            {
                //����ȱ�ٵĻ������
                if(ComRoomInfo.find(index) == ComRoomInfo.end())
                {
                    ComRoomInfo.insert(make_pair(index,com_in));
                    break;
                }

            }

            cout<<"��ӳɹ���"<<endl;
            this->save_ComRoom(ComRoomInfo);
        }

        else if(t==2)
        {
            cout<<"������Ҫɾ���Ļ�����";
            int t;
            cin>>t;

            if(ComRoomInfo.find(t)==ComRoomInfo.end())
            {
                cout<<"�޴˻�����Ϣ��"<<endl;
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
    //1�����ļ�
    ofstream ofs;
    ofs.open(filename_ComRoom,ios::trunc);

    //2�������ļ�
    for(map<int,ComputerRoom>::iterator it=ComRoomInfo.begin();it!=ComRoomInfo.end();it++)
    {
        ofs<<it->first
            <<"\t"<<it->second.capacity
            <<"\t"<<it->second.state
            <<"\t"<<it->second.Week
            <<"\t"<<it->second.time<<endl;
    }

    //3�ر��ļ�
    ofs.close();
}



