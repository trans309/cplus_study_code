#pragma once

using namespace std;

#include <iostream>

#include <string>

class ComputerRoom
{
public:

    string CR_index;//����ֵ

    string capacity;//����

    /*
 ״̬--����Ա /    ��ʦ    /ѧ������   /����ѧ�����鿴���У�

    0--����   /��˲�ͨ��  /ԤԼʧ��   /����
    1--��ԤԼ /�����      /�����     /�����
    2--����   /            /��ȡ��ԤԼ /����
    3--��ԤԼ /�����ͨ��  /ԤԼ�ɹ�   /����ԤԼ
    4--����   /            /           /
     */
    string CR_state;//״̬
    //0--����
    //1--����ԤԼ��¼--����������ԤԼ��



    ComputerRoom();

    void init_state();

        //����==
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
