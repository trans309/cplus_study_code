#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cstdlib>

#include "Identity.h"
#include "computer_room.h"
#include "order.h"

class Student:public Identity
{
public:

//    string S_Name;//����
//    string S_Password;//����
    string StuNum;//ѧ��


    //1����ȡ�ļ�
//    ReservationSystem::StudentSystem�Խ��ж�ȡ

    //2.1��ע�����
    void Registration_menu(vector<Student> &StuInfo);

        //2.1.1��������ע��ѧ��
        void save_Stufile(vector<Student> &StuInfo);

    //2.2����¼����
    void Login_menu(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

    //3������ѧ������
    void Student_main(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

        //3.1��ѧ���˵�
        void Student_menu();

        //3.2����ȡ�ļ�
        void read_stu_file(vector<Student> &StuInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.1������ԤԼ
            void ApplyFor_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.1.1���� ����/ԤԼ ��Ϣ
                void save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.2��ȡ��ԤԼ
            void CancelFor_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.3���鿴�ҵ�ԤԼ
            void Veiw_My_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.4���鿴����ԤԼ
            void Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.3/4.1�����״̬
                string get_odstate(string od_state);

};
