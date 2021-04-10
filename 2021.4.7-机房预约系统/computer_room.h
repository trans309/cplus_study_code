#pragma once

using namespace std;

#include <iostream>

#include <string>

class ComputerRoom
{
public:

    string CR_index;//索引值

    string capacity;//容量

    /*
 状态--管理员 /    教师    /学生本人   /其他学生（查看所有）

    0--闲置   /审核不通过  /预约失败   /空闲
    1--已预约 /待审核      /审核中     /审核中
    2--闲置   /            /已取消预约 /空闲
    3--已预约 /审核已通过  /预约成功   /已有预约
    4--已满   /            /           /
     */
    string CR_state;//状态
    //0--闲置
    //1--存在预约记录--已满（不可预约）



    ComputerRoom();

    void init_state();

        //重载==
//    bool operator==(char ch) const;




};

class less_ComRoom
{
public:
    bool operator()(const ComputerRoom &cr1,const ComputerRoom &cr2) const
    {
        return cr1.CR_index<cr2.CR_index;
    }
};
