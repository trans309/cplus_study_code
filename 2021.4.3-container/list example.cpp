#include <iostream>
#include "container.h"
#include <string>
#include <list>
#include <cstdlib>
#include <fstream>


#define filename "data"

using namespace std;

class person
{
public:

    string m_name;
    int m_age;
    int m_height;

    person(string name,int age,int height)
    {
        this->m_age=age;
        this->m_height=height;
        this->m_name=name;
    }
};

void creat_p(list<person>& p,int num)
{
    for(int i=0;i<num;i++)
    {
        //生成随机名字
        string seed="QWERTYUIOPLKJHGFDSAZXCVBNM";
        string name;
        for(int n=0;n<3;n++)
        {
            name+=seed[rand()%26];
        }

        //生成随机年龄
        int age=rand()%21+20;

        //生成随机身高
        int height=rand()%21+160;

        //将person尾插存入list
        person per(name,age,height);
        p.push_back(per);
    }

}

//打印
void print_p(const list<person>& p)
{
    for(list<person>::const_iterator it=p.begin();it != p.end();it++)
    {
        cout<<"姓名："<<it->m_name<<"\t年龄："<<it->m_age<<"\t身高："<<it->m_height<<"cm"<<endl;
    }
}

//年龄升序
//若年龄相同，按身高降序
//若年龄、身高相同，按名字升序
bool compare(person p1,person p2)
{
    if(p1.m_age==p2.m_age)
    {
        if(p1.m_age==p2.m_age&&p1.m_height==p2.m_height)
        {
            return p1.m_name<p2.m_name;
        }
        return p1.m_height>p2.m_height;
    }
    return p1.m_age<p2.m_age;
}

void save(list<person>& p)
{
    ofstream ofs;
    ofs.open(filename,ios::out);
    for(list<person>::const_iterator it=p.begin();it != p.end();it++)
    {
        ofs<<it->m_name<<"\t"<<it->m_age<<"\t"<<it->m_height<<endl;
    }
    ofs.close();
}

void read(list<person>& p)
{
    ifstream ifs;
    ifs.open(filename,ios::in);

    string name;
    int age;
    int height;

    while(ifs>>name&&ifs>>age&&ifs>>height)
    {
        person per(name,age,height);
        p.push_back(per);
    }
    ifs.close();
}

void test1()
{

    list<person> p;

    //读取文件
    read(p);
    print_p(p);

    cout<<"请输入创建人数：";
    int num;
    cin>>num;
    creat_p(p,num);

    p.sort(compare);
    save(p);
    print_p(p);
}
