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
        //创建文件夹

    //1、
//    string folderPath = ".\\file";
//
//    string command;
//    command = "mkdir -p " + folderPath;
//    system(command.c_str());

    //2、
    system("md .\\file");

    cout<<"文件夹创建成功！"<<endl;
    }


    ReservationSystem rs;

    while(1)
    {
        //打印菜单
        rs.menu();

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
            rs.AdministratorSystem();
            break;
        case TEACHER:
            rs.TeacherSystem();
            break;
        case STUDENT:
            rs.StudentSystem();
            break;
        }

        //3、清屏
        system("pause");
        system("cls");
    }
    return 0;
}
