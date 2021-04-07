#include <iostream>

using namespace std;

#include "ReservationSystem.h"


int main()
{
    ReservationSystem rs;

    //打印菜单
    rs.menu();

    while(1)
    {
        cout<<"请选择登入系统：";
        int choice;
        cin>>choice;

        //2、选择
        switch(choice)
        {
        case EXIT:
            rs.Exit();
            break;
        case ADMINISTRATOR:
//            rs.AdministratorSystem();
            break;
        case TEACHER:
//            rs.TeacherSystem();
            break;
        case STUDENT:
//            rs.StudentSystem();
            break;
        }

        //3、清屏
        system("pause");
        system("cls");
    }
    return 0;
}
