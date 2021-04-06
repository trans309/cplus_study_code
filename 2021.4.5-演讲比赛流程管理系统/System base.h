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

    //菜单
    void menu();

    //system——base
    void Start();//开始比赛
    void View();//查看记录
    void Clear();//清空记录
    void Exit();//退出系统

    //other——base
    system_base();//构造
    void creat_player(vector<Player>&player);//创建选手信息
    void print_player(vector<Player>&player);//打印选手信息
    void divide_player(vector<Player>&player);//淘汰赛分组信息
    void first_score(vector<Player>&player);//第一次得分
    void second_score(vector<Player>&player);//第二次得分
    void save(vector<Player>&player);//保存为文件
    void read();

    //存放文件信息
    map<int,vector<string> >vectory;

    //文件空标志
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
