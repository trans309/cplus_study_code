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
        case 0://�˳�
            cout<<"��лʹ�ã���"<<endl;
            exit(0);
            break;
        case 1://���
            op.add_worker();
            break;
        case 2://��ӡ
            op.show_worker();
            break;
        case 3://ɾ��
            op.delete_worker();
            break;
        case 4://�޸�
            op.modify_worker();
            break;
        case 5://����
            op.search_worker();
            break;
        case 6://����
            op.sort_worker();
            break;
        case 7://���
            op.clean_worker();
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
