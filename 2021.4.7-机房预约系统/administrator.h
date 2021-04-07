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

    //1��ȡ�ļ�


    //2.1��ע�����
    void Registration_menu(vector<Administrator> &AdminInfo);

        //2.1.1��������ע�����Ա
        void save_Adminfile(vector<Administrator> &AdminInfo);

    //2.2����¼����
    void Login_menu(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

    //3���������Ա����
    void Administrator_main(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

        //3.1������Ա�˵�
        void Administrator_menu();

        //3.2����ȡ�ļ�
        void read_file(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);

            //3.2.1�����/ɾ����ʦ�˺�
            void teacher_modify();

            //3.2.2�����/ɾ��ѧ���˺�
            void student_modify();

            //3.2.3���鿴���н�ʦ/ѧ���˺�
            void TS_veiw();

            //3.2.4���޸Ļ�����Ϣ
            void computerroom_modify(vector<Administrator> &AdminInfo,vector<Teacher> &TeaInfo,vector<Student> &StuInfo);







};
