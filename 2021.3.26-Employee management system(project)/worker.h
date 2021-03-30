#pragma once

#include <iostream>

using namespace std;

#include <cstdlib>
#include <string>

class worker
{
public:
    virtual void showInfo()=0;
    virtual string get_post()=0;

    string id;//职工编号
    string name;//职工姓名
    int p_id;//职工职位编号
    //1、员工
    //2、经理
    //3、老板

};

class employee:public worker
{
public:
    employee(string m_id,string m_name,int m_p_id);

    void showInfo();

    string get_post();
};

class manage:public worker
{
public:
    manage(string m_id,string m_name,int m_p_id);

    void showInfo();

    string get_post();
};

class boss:public worker
{
public:
    boss(string m_id,string m_name,int m_p_id);

    void showInfo();

    string get_post();
};
