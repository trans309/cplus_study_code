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
//������д�ļ�
    //1��ͷ�ļ�

    //2������������
    ofstream ofs;

    //3�����ļ�
    ofs.open("test_binary.data",ios::out|ios::binary);

    //4��д����
    person p={"����",21};
    ofs.write((const char*)&p,sizeof(person));

    //5���ر��ļ�
    ofs.close();


//�����ƶ��ļ�
    //1��ͷ�ļ�

    //2������������
    ifstream ifs;

    //3�����ļ�
    ifs.open("test_binary.data",ios::in|ios::binary);

    //4��д����
    person p_get;
    while(ifs.read((char*)&p_get,sizeof(person)))

    cout<<p_get.name<<p_get.age<<endl;

    //5���ر��ļ�
    ofs.close();

    return 0;
}
