//#include <iostream>
//
//using namespace std;
//
//#include <fstream>
//#include <string>
//
//int main()
//{
////�ı�д�ļ�
//    //1��ͷ�ļ�
//
//    //2������������
//    ofstream outfile;
//
//    //3�����ļ�
//    outfile.open("test.data",ios::out);
//
//    //4��д����
//    outfile<<"����\nlisi\n13898"<<endl;
//
//    outfile<<"����"<<endl;
//    outfile<<"name"<<endl;
//    outfile<<16273<<endl;
//
//    //5���ر��ļ�
//    outfile.close();
//
////�ı����ļ�
//    //1��ͷ�ļ�
//
//    //2������������
//    ifstream infile;
//
//    //3�����ļ����ж��Ƿ�򿪳ɹ�
//    infile.open("test.data",ios::in);
//
//    if(!infile.is_open())
//    {
//        cout<<"���ļ�ʧ��"<<endl;
//    }
//    //4��������
//        //1��һ���ж����������ļ�����false
////        char buf[1024]={0};
////        while(infile>>buf)
////        {
////            cout<<buf<<endl;
////        }
//
//        //2��ifstream���ж��庯��getline---һ���ж�ȡ
////        char buf[1024]={0};
////        while(infile.getline(buf,sizeof(buf)))
////        {
////            cout<<buf<<endl;
////        }
//
//        //3������ȫ�ֺ���---getline�����ļ����ݶ���buf
////        string buf;
////        while(getline(infile,buf))
////        {
////            cout<<buf<<endl;
////        }
//
//        //4���������ж��庯��  һ��һ��  ������
//        char b;
//        while((b=infile.get())!=EOF)//EOF--end of file�ļ���β��ʶ��
//        {
//            cout<<b;
//        }
//
//    //5���ر��ļ�
//    infile.close();
//
//    return 0;
//}
