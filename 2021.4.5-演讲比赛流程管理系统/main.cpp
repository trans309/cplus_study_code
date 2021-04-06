#include <iostream>

using namespace std;

#include "System base.h"
#include <cstdlib>

int main()
{
    system_base sb;
    while(1)
    {
        sb.menu();
        int input;
        cout<<"请选择操作：";
        cin>>input;

        switch(input)
        {
        case EXIT:
            cout<<"欢迎下次使用"<<endl;
            sb.Exit();
            break;
        case START:
            sb.Start();
            break;
        case VIEW:
            sb.View();
            break;
        case CLEAR:
            sb.Clear();
            break;
        }

        system("pause");
        system("cls");
    }
    return 0;
}
