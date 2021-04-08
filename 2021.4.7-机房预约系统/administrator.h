#pragma once

using namespace std;

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

#include "computer_room.h"
#include "teacher.h"
#include "student.h"
#include "Identity.h"

class Administrator:public Identity
{
public:

    //1\��ȡ�ļ�
    //ReservationSystem::AdministratorSystem�Խ��ж�ȡ

    //2.1��ע�����
    void Registration_menu(vector<Administrator> &AdminInfo);

        //2.1.1��������ע�����Ա
        void save_Adminfile(vector<Administrator> &AdminInfo);

    //2.2����¼����
    void Login_menu(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //3���������Ա����
    void Administrator_main(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

        //3.1������Ա�˵�
        void Administrator_menu();

        //3.2����ȡ�ļ�
        void read_file(map<int,ComputerRoom> &ComRoomInfo,vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

            //3.2.1�����/ɾ����ʦ�˺�
            void teacher_modify(vector<Teacher> &TeaInfo);

                //3.2.1.1�����ʦ�˺�
                void save_Teacher(vector<Teacher> &TeaInfo);

            //3.2.2�����/ɾ��ѧ���˺�
            void student_modify(vector<Student> &StuInfo);

                //3.2.1.1����ѧ���˺�
                void save_Student(vector<Student> &StuInfo);

            //3.2.3���鿴���н�ʦ/ѧ���˺�
            void TS_veiw(vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

            //3.2.4���޸�/��ӡ������Ϣ
            void computerroom_modify_main(map<int,ComputerRoom> &ComRoomInfo);

                //3.2.4.1���޸Ļ�����Ϣ
                void computerroom_modify(map<int,ComputerRoom> &ComRoomInfo);

                    //3.2.4.1.1����������ļ�
                    void save_ComRoom(map<int,ComputerRoom> &ComRoomInfo);







};
