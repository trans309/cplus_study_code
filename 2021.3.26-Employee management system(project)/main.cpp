#include "menu_system.h"


int main()
{
    menu_system op;
    while(1)
    {
        int choice;
        op.menu();
        cout<<"�������������";
        cin>>choice;
        switch(choice)
        {
        case 0:
            cout<<"��лʹ�ã���"<<endl;
            exit(0);
            break;
        case 1:
            op.add_worker();
            break;
        case 2:
            op.show_worker();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
