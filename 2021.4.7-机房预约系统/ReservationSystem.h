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
#include "order.h"

enum re_menu
{
    EXIT,
    ADMINISTRATOR,
    TEACHER,
    STUDENT
};

enum system_menu
{
    RETURN,
    REGISTRATION,
    LOGIN
};

class ReservationSystem
{
public:

    vector<Administrator> AdminInfo;//����Ա��Ϣ
    vector<Teacher> TeaInfo;//��ʦ��Ϣ
    vector<Student> StuInfo;//ѧ����Ϣ

    map<ComputerRoom,vector<Order>,less_ComRoom> CRoomOrder;//����ԤԼ��Ϣ



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

    //��������״̬
    void check_CRoom_empty(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);




    //��ȡ ��� �ļ�
    //type1---����Ա
    void read_AdminFile(vector<Administrator> &AdminInfo);
    //type2---��ʦ
    void read_Teafile(vector<Teacher> &TeaInfo);
    //type3---ѧ��
    void read_Stufile(vector<Student> &StuInfo);

    //��ȡ ����/ԤԼ��¼ �ļ�
    void read_CRO_File(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);
    //Administrator
    //��ʼ�� ����Ա ��ȡ�ļ�
    void Init_Admin_ReadFile(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //Teacher
    //��ʼ�� ��ʦ ��ȡ�ļ�
    void Init_Tea_ReadFile(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

    //Student
    //��ʼ�� ѧ�� ��ȡ�ļ�
    void Init_Stu_ReadFile(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

};
