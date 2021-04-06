#pragma once
#include <iostream>

using namespace std;

#include <vector>
#include "Player.h"
#include <map>



enum
{
    EXIT,//0
    START,
    VIEW,
    CLEAR
};

class system_base
{
public:

    //�˵�
    void menu();

    //system����base
    void Start();//��ʼ����
    void View();//�鿴��¼
    void Clear();//��ռ�¼
    void Exit();//�˳�ϵͳ

    //other����base
    system_base();//����
    void creat_player(vector<Player>&player);//����ѡ����Ϣ
    void print_player(vector<Player>&player);//��ӡѡ����Ϣ
    void divide_player(vector<Player>&player);//��̭��������Ϣ
    void first_score(vector<Player>&player);//��һ�ε÷�
    void second_score(vector<Player>&player);//�ڶ��ε÷�
    void save(vector<Player>&player);//����Ϊ�ļ�
    void read();

    //����ļ���Ϣ
    map<int,vector<string> >vectory;

    //�ļ��ձ�־
    bool empty_file;
};

class printstring
{
public:
    void operator()(string s)
    {
        cout<<s<<" ";
    }
};
