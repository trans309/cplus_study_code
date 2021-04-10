#include <iostream>

using namespace std;

#include "ReservationSystem.h"
#include <dirent.h>


int main()
{
    string filedir="./file";
    DIR *dir;
    if((dir=opendir(filedir.c_str())) == NULL)
    {
        //�����ļ���

    //1��
//    string folderPath = ".\\file";
//
//    string command;
//    command = "mkdir -p " + folderPath;
//    system(command.c_str());

    //2��
    system("md .\\file");

    cout<<"�ļ��д����ɹ���"<<endl;
    }


    ReservationSystem rs;

    while(1)
    {
        //��ӡ�˵�
        rs.menu();

        cout<<"��ѡ�����ϵͳ��";
        int choice;
        cin>>choice;

        //2��ѡ��
        switch(choice)
        {
        case EXIT:
            rs.Exit();
            break;
        case ADMINISTRATOR:
            rs.AdministratorSystem();
            break;
        case TEACHER:
            rs.TeacherSystem();
            break;
        case STUDENT:
            rs.StudentSystem();
            break;
        }

        //3������
        system("pause");
        system("cls");
    }
    return 0;
}
