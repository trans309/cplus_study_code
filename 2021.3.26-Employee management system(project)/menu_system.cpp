#include "menu_system.h"
#include "worker.h"

//��ӡ�˵�
void menu_system::menu()
{
    cout<<"******************************"<<endl;
    cout<<"*****��ӭʹ��ְ������ϵͳ*****"<<endl;
    cout<<"*****  1�� ����ְ����Ϣ  *****"<<endl;
    cout<<"*****  2�� ��ʾְ����Ϣ  *****"<<endl;
    cout<<"*****  3�� ɾ����ְְ��  *****"<<endl;
    cout<<"*****  4�� �޸�ְ����Ϣ  *****"<<endl;
    cout<<"*****  5�� ����ְ����Ϣ  *****"<<endl;
    cout<<"*****  6�� ����������  *****"<<endl;
    cout<<"*****  7�� ��������ĵ�  *****"<<endl;
    cout<<"*****  0�� �˳�����ϵͳ  *****"<<endl;
    cout<<"******************************"<<endl;
}

//����--��ʼ���ļ�����
void menu_system::init_num()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int num=0;
    string m_id;
    string m_name;
    int m_p_id;

    //ÿ��ȡһ�У�����num+1
    while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)//ifs>>  ----  ��ģʽ��ȡ��ÿ�������ո񡢻��С��ļ���������ֹͣ��ȡ
    {
        num++;
    }

    //��ʼ������
    this->worker_num=num;

//    //����
//    cout<<"������"<<num<<"��ְ��"<<endl;
    ifs.close();
}

//����--�����ļ����ݣ�ָ��ָ���ļ�����
void menu_system::init_worker()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    worker** new_worker_arr=new worker*[this->worker_num];

        string m_id;
        string m_name;
        int m_p_id;
        int i=0;

        while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)
        {
            if(m_p_id==1)
            {
                new_worker_arr[i]=new employee(m_id,m_name,m_p_id);
            }
            else if(m_p_id==2)
            {
                new_worker_arr[i]=new manage(m_id,m_name,m_p_id);
            }
            else if(m_p_id==3)
            {
                new_worker_arr[i]=new boss(m_id,m_name,m_p_id);
            }
            i++;
        }

    //�ͷžɿռ�
    delete[] this->worker_arr;
    this->worker_arr=NULL;

    //�����¿ռ�
    this->worker_arr=new_worker_arr;

//    //���ԣ���ӡԱ��
//    this->show_worker();

    ifs.close();
}

//����Ϊ�ļ�
void menu_system::save_worker()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    int i=0;
    for(;i<this->worker_num;i++)
    {
        ofs<<this->worker_arr[i]->id<<"\t"
            <<this->worker_arr[i]->name<<"\t"
            <<this->worker_arr[i]->p_id<<endl;
    }
    ofs.close();
}

//���ְ��
void menu_system::add_worker()
{
    int num;
    cout<<"���������ְ������"<<endl;
    cin>>num;

    //�ж���������
    if(num>0)
    {
        //�����¿ռ�
        worker **newspace=new worker*[this->worker_num+num];
        //����Ԫ��,�������ݿ���
        if(this->worker_arr!=NULL)
        {

            int i=0;
            for(;i<this->worker_num;i++)
            {
                newspace[i]=this->worker_arr[i];
            }
        }

        //ѭ�����
        int j=0;
        for(;j<num;j++)
        {
            int post;
            string name,id;

            cout<<"������ְ�����:";
            cin>>id;
            cout<<"������ְ������:";
            cin>>name;
            cout<<"1��Ա��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
            cout<<"������ְ��ְλ:"<<endl;
            cin>>post;

            //����ְλ�����¿ռ䣨Ԫ�أ�
            switch(post)
            {
            case 1:
                newspace[worker_num+j]=new employee(id,name,post);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            case 2:
                newspace[worker_num+j]=new manage(id,name,post);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            case 3:
                newspace[worker_num+j]=new boss(id,name,post);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            default:
                cout<<"��������������\n"<<endl;
                j--;
                break;
            }
        }

        //�ͷ��Ͽռ䣬�����¿ռ�
        delete[] this->worker_arr;
        this->worker_arr=newspace;

        //����ְ������
        this->worker_num+=num;

        //�����ļ�
        this->save_worker();
        cout<<"�ɹ����"<<num<<"��ְ��\n"<<endl;
    }

    //���������������
    else
    {
        cout<<"�������,�˳����\n"<<endl;
    }
}

//��ʾ����ӡ��ϵͳְ��
void menu_system::show_worker()
{
    int i=0;
    if(this->worker_num>0)
    {
        for(;i<this->worker_num;i++)
        {
            this->worker_arr[i]->showInfo();
        }
    }
    else
    {
        cout<<"��ְ����Ϣ��"<<"\n"<<"�������ӣ���\n"<<endl;
    }
}
