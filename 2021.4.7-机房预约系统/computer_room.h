#pragma once

using namespace std;

#include <iostream>

#include <string>

class ComputerRoom
{
public:

//    int index;//����ֵ

    int capacity;//����

    /*
    0--����/��ԤԼ
    1--��ԤԼ
    2--��ȡ��/��ԤԼ
     */
    int state;//״̬

    int Week;//����

    /*
    1--����
    2--����
    3--����
     */
    int time;//һ����ʱ���

    ComputerRoom();

    string get_week();
    string get_time();

};
