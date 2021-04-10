#pragma once

using namespace std;

#include <iostream>
#include <string>

class Order
{
public:

    string Applicant;//ԤԼ��

    string Week;//����

    /*
    1--����
    2--����
    3--����
     */
    string time;//һ����ʱ���

    /*
 ״̬--    ��ʦ    /ѧ������   /����ѧ�����鿴���У�

    0--��˲�ͨ��  /ԤԼʧ��   /����
    1--�����      /�����     /�����
    2--            /��ȡ��ԤԼ /����
    3--�����ͨ��  /ԤԼ�ɹ�   /����ԤԼ
    4--            /           /
     */
    string OD_state;

    Order();

    string get_week();
    string get_time();

    bool operator==(Order& odt);
};

class Order_Sort
{
public:
    bool operator()(const Order& od1,const Order& od2) const
    {
        if(od1.Applicant==od2.Applicant)
        {
            if(od1.Week==od2.Week)
            {
                return od1.time<od2.time;
            }

            return od1.Week<od2.Week;
        }

        return od1.Applicant<od2.Applicant;
    }
};
