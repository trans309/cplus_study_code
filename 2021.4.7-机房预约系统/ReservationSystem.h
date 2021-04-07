#pragma once

using namespace std;

#include <iostream>
#include <cstdlib>
#include <vector>

#include "administrator.h"
#include "teacher.h"
#include "student.h"

enum re_menu
{
    EXIT,
    ADMINISTRATOR,
    TEACHER,
    STUDENT
};

enum ad_menu
{
    AD_RETURN,
    REGISTRATION,
    LOGIN
};

class ReservationSystem
{
public:

    bool ad_empty;
    bool tea_empty;
    bool stu_empty;

    vector<Administrator> AdminInfo;//����Ա��Ϣ
    vector<Teacher> TeaInfo;//��ʦ��Ϣ
    vector<Student> StuInfo;//ѧ����Ϣ




    //����/����
    ReservationSystem();
    ~ReservationSystem();



    //basic system

    //ѧ��ϵͳ
    void StudentSystem();

    //��ʦϵͳ
    void TeacherSystem();

    //����Աϵͳ
    void AdministratorSystem();

    //�˳�ԤԼϵͳ
    void Exit();



    //other system

    //����˵�����
    void menu();
    void menu_choice();

    //��ȡ�ļ�
    //type1---����Ա
    //type2---��ʦ
    //type3---ѧ��
    void read_IentityFile(int type);
};
