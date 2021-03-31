#include "menu_system.h"


int main()
{
    menu_system op;
    while(1)
    {
        int choice;
        op.menu();
        cout<<"请输入操作数：";
        cin>>choice;
        switch(choice)
        {
        case 0://退出
            cout<<"感谢使用！！"<<endl;
            exit(0);
            break;
        case 1://添加
            op.add_worker();
            break;
        case 2://打印
            op.show_worker();
            break;
        case 3://删除
            op.delete_worker();
            break;
        case 4://修改
            op.modify_worker();
            break;
        case 5://查找
            op.search_worker();
            break;
        case 6://排序
            op.sort_worker();
            break;
        case 7://清空
            op.clean_worker();
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
