//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//
////打印菜单
//void menu()
//{
//    cout<<"*****1、开始游戏/t0、退出游戏*****"<<endl;
//}
//
//int main()
//{
//    int input = 0;
//    int pre_num=0;
//
//    srand((unsigned int)time(NULL));
//    int rand_num=rand()%100+1;
//    cout<<rand_num<<endl;
//
//    menu();
//    cout<<"请输入：";
//    cin>>input;
//
//    while(input)
//    {
//        cout<<"请输入数字："<<endl;
//        cin>>pre_num;
//        if(pre_num>rand_num)
//        {
//            cout<<"大了"<<endl;
//        }
//        else if(pre_num<rand_num)
//        {
//            cout<<"小了"<<endl;
//        }
//        else
//        {
//            cout<<"恭喜猜测正确！！"<<endl;
//            break;
//        }
//    }
//    return 0;
//}
