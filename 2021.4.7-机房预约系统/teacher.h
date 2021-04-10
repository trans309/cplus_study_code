#pragma once

using namespace std;

#include <iostream>
#include <string>

#include "Identity.h"
#include "computer_room.h"
#include "order.h"

class Teacher:public Identity
{
public:

//    string T_Name;//����
//    string T_Password;//����
    string TeaNum;//ְ����

        //1����ȡ�ļ�
//    ReservationSystem::StudentSystem�Խ��ж�ȡ

    //2.1��ע�����
    void Registration_menu(vector<Teacher> &TeaInfo);

        //2.1.1��������ע���ʦ
        void save_Teafile(vector<Teacher> &TeaInfo);

    //2.2����¼����
    void Login_menu(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

    //3�������ʦ����
    void Teacher_main(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

        //3.1����ʦ�˵�
        void Teacher_menu();

        //3.2����ȡ�ļ�
        void read_tea_file(vector<Teacher> &TeaInfo,map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);


            //3.2.1���鿴����ԤԼ
            void Veiw_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

            //3.2.2�����ԤԼ
            void Audit_All_Order(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.2.1���� ����/ԤԼ ��Ϣ
                void save_ComRoom(map<ComputerRoom,vector<Order>,less_ComRoom> &CRoomOrder);

                //3.2.2.2�����״̬ѧ��
                string get_odstate_stu(string od_state);

                //3.2.2.3�����״̬��ʦ
                string get_odstate_tea(string od_state);

};
