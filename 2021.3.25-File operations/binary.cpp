#include <iostream>

using namespace std;

#include <fstream>
#include <string>


class person
{
public:
    char name[20];
    int age;
};
int main()
{
//二进制写文件
    //1、头文件

    //2、创建流对象
    ofstream ofs;

    //3、打开文件
    ofs.open("test_binary.data",ios::out|ios::binary);

    //4、写数据
    person p={"李四",21};
    ofs.write((const char*)&p,sizeof(person));

    //5、关闭文件
    ofs.close();


//二进制读文件
    //1、头文件

    //2、创建流对象
    ifstream ifs;

    //3、打开文件
    ifs.open("test_binary.data",ios::in|ios::binary);

    //4、写数据
    person p_get;
    while(ifs.read((char*)&p_get,sizeof(person)))

    cout<<p_get.name<<p_get.age<<endl;

    //5、关闭文件
    ofs.close();

    return 0;
}
