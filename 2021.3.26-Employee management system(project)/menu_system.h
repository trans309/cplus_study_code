#pragma once

#include <iostream>

using namespace std;

#include <cstdlib>
#include "worker.h"
#include <fstream>

#define FILENAME "The worker list.data"

class menu_system
{
public:
    //����ϵͳ
    void menu();
    void add_worker();
    void show_worker();
    void save_worker();



    //��������
    int worker_num;//ְ������
    worker** worker_arr;//����ְ������
    bool FileExists;


    //����--���ļ�ʱ��ʼ������
    void init_num();
    //����--���������ļ����ݵ��뻺����
    void init_worker();

    //����
    menu_system()
    {
        ifstream ifs;
        ifs.open(FILENAME,ios::in);

        //1�����ļ���������
        if(!ifs.is_open())
        {
            //����
            cout<<"�ļ������ڣ���"<<endl;
            //��ʼ��
            worker_num=0;
            worker_arr=NULL;
            FileExists=false;
            ifs.close();
            return;
        }

        //2�����ļ���������
        char ch;
        ifs>>ch;//��ȡ���EOF��ʶ�����ļ����ڣ����أ�������״̬**���в���ɾ
        if(ifs.eof())
        {
            //����
            cout<<"�ļ������ݣ���"<<endl;
            //��ʼ��
            worker_num=0;
            worker_arr=NULL;
            FileExists=true;
            ifs.close();
            return;
        }

        //3�����ļ���������

        init_num();//��ʼ������
        init_worker();//��ʼ��Ա��
    }
    //����
    ~menu_system()
    {
        if(worker_arr!=NULL)
        {
            delete[] worker_arr;
            this->worker_arr=NULL;
        }
    }
};
