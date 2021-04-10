#pragma once

using namespace std;

#include <iostream>
#include <string>

class Order
{
public:

    string Applicant;//预约人

    string Week;//星期

    /*
    1--上午
    2--下午
    3--晚上
     */
    string time;//一天中时间段

    /*
 状态--    教师    /学生本人   /其他学生（查看所有）

    0--审核不通过  /预约失败   /空闲
    1--待审核      /审核中     /审核中
    2--            /已取消预约 /空闲
    3--审核已通过  /预约成功   /已有预约
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
