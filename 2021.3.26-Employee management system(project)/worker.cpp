#include "worker.h"


//employee
employee::employee(string m_id,string m_name,int m_p_id)
{
    this->id=m_id;
    this->name=m_name;
    this->p_id=m_p_id;
}
void employee::showInfo()
{
    cout<<"ְ�����: "<<id<<"\t"
        <<"ְ������: "<<name<<"\t"
        <<"ְ��ְλ: "<<get_post()<<endl;
}

string employee::get_post()
{
    return "Ա��";
}


//manage
manage::manage(string m_id,string m_name,int m_p_id)
{
    this->id=m_id;
    this->name=m_name;
    this->p_id=m_p_id;
}
void manage::showInfo()
{
    cout<<"ְ�����: "<<id<<"\t"
        <<"ְ������: "<<name<<"\t"
        <<"ְ��ְλ: "<<get_post()<<endl;
}

string manage::get_post()
{
    return "����";
}


//boss
boss::boss(string m_id,string m_name,int m_p_id)
{
    this->id=m_id;
    this->name=m_name;
    this->p_id=m_p_id;
}
void boss::showInfo()
{
    cout<<"ְ�����: "<<id<<"\t"
        <<"ְ������: "<<name<<"\t"
        <<"ְ��ְλ: "<<get_post()<<endl;
}

string boss::get_post()
{
    return "�ϰ�";
}
