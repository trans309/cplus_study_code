#include <iostream>

using namespace std;

#include "ReservationSystem.h"


int main()
{
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
//            rs.TeacherSystem();
            break;
        case STUDENT:
//            rs.StudentSystem();
            break;
        }

        //3������
        system("pause");
        system("cls");
    }
    return 0;
}
