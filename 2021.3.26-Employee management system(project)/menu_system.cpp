#include "menu_system.h"
#include "worker.h"

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
                newspace[worker_num+j]=new employee(id,name);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            case 2:
                newspace[worker_num+j]=new manage(id,name);cout<<"��ӳɹ���"<<endl<<endl;
                break;
            case 3:
                newspace[worker_num+j]=new boss(id,name);cout<<"��ӳɹ���"<<endl<<endl;
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
    }

    //���������������
    else
    {
        cout<<"�������,�˳����\n"<<endl;
    }
}

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
