#pragma once

using namespace std;

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "administrator.h"
#include "teacher.h"
#include "student.h"
#include "computer_room.h"

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
class Administrator;

class ReservationSystem
{
public:

    bool ad_empty;
    bool tea_empty;
    bool stu_empty;

    vector<Administrator> AdminInfo;//����Ա��Ϣ
    vector<Teacher> TeaInfo;//��ʦ��Ϣ
    vector<Student> StuInfo;//ѧ����Ϣ

    map<int,ComputerRoom> A_ComInfo;//������Ϣ




    //����/����
    ReservationSystem();
    ~ReservationSystem();



    //basic system

    //ѧ��ϵͳ
    void StudentSystem();//vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //��ʦϵͳ
    void TeacherSystem();//vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //����Աϵͳ
    void AdministratorSystem();//vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

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
    void read_IentityFile(int type,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //��ʼ����ȡ�ļ�
    void init_readfile(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);


};
