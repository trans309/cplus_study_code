//#include <iostream>
//
//using namespace std;
//
//#include <fstream>
//#include <string>
//
//int main()
//{
////文本写文件
//    //1、头文件
//
//    //2、创建流对象
//    ofstream outfile;
//
//    //3、打开文件
//    outfile.open("test.data",ios::out);
//
//    //4、写数据
//    outfile<<"张三\nlisi\n13898"<<endl;
//
//    outfile<<"李四"<<endl;
//    outfile<<"name"<<endl;
//    outfile<<16273<<endl;
//
//    //5、关闭文件
//    outfile.close();
//
////文本读文件
//    //1、头文件
//
//    //2、创建流对象
//    ifstream infile;
//
//    //3、打开文件，判断是否打开成功
//    infile.open("test.data",ios::in);
//
//    if(!infile.is_open())
//    {
//        cout<<"打开文件失败"<<endl;
//    }
//    //4、读数据
//        //1、一行行读，当读完文件返回false
////        char buf[1024]={0};
////        while(infile>>buf)
////        {
////            cout<<buf<<endl;
////        }
//
//        //2、ifstream类中定义函数getline---一行行读取
////        char buf[1024]={0};
////        while(infile.getline(buf,sizeof(buf)))
////        {
////            cout<<buf<<endl;
////        }
//
//        //3、利用全局函数---getline，将文件数据读入buf
////        string buf;
////        while(getline(infile,buf))
////        {
////            cout<<buf<<endl;
////        }
//
//        //4、利用类中定义函数  一个一个  读数据
//        char b;
//        while((b=infile.get())!=EOF)//EOF--end of file文件结尾标识符
//        {
//            cout<<b;
//        }
//
//    //5、关闭文件
//    infile.close();
//
//    return 0;
//}
