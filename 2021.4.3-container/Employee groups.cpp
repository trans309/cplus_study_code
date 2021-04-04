#include "container.h"
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

class Employee
{
public:

    string m_name;
    int m_salary;
    int m_department;

    Employee(string name,int salary,int department)
    {
        this->m_department=department;
        this->m_name=name;
        this->m_salary=salary;
    }

    string get_department()
    {
        if(this->m_department==1)
            return "�߻�";
        else if(this->m_department==2)
            return "����";
        else
            return "�з�";
    }
};

void crear_emp(vector<Employee>&E)
{
    for(int i=0;i<10;i++)
    {
        string nameseed="ABCDEFGHIJ";
        string name="Ա��";
        name+=nameseed[i];

        int salary=rand()%3001+5000;//5000~8000

        int department=rand()%3+1;//1~3

        E.push_back(Employee(name,salary,department));
    }
}

void divide(vector<Employee>&E,multimap<int,Employee>&e)
{
    for(vector<Employee>::iterator it=E.begin();it!=E.end();it++)
    {
        e.insert(make_pair(it->m_department,*it));
    }
}

void print_by_department(multimap<int,Employee>&e)
{
    cout<<"�߻����ţ�"<<endl;
    for(multimap<int,Employee>::iterator it1=e.find(1);it1!=e.find(2);it1++)
    {
        cout<<"������"<<it1->second.m_name<<"\t"
//            <<"ְλ��"<<it1->second.get_department()<<" "<<it1->first<<"\t"
            <<"���ʣ�"<<it1->second.m_salary<<endl;
    }
    cout<<endl;

    cout<<"�������ţ�"<<endl;
    for(multimap<int,Employee>::iterator it2=e.find(2);it2!=e.find(3);it2++)
    {
        cout<<"������"<<it2->second.m_name<<"\t"
//            <<"ְλ��"<<it2->second.get_department()<<" "<<it2->first<<"\t"
            <<"���ʣ�"<<it2->second.m_salary<<endl;
    }
    cout<<endl;

    cout<<"�з����ţ�"<<endl;
    for(multimap<int,Employee>::iterator it3=e.find(3);it3!=e.end();it3++)
    {
        cout<<"������"<<it3->second.m_name<<"\t"
//            <<"ְλ��"<<it3->second.get_department()<<" "<<it3->first<<"\t"
            <<"���ʣ�"<<it3->second.m_salary<<endl;
    }

}

void test2()
{
    vector<Employee>E;
    multimap<int,Employee>e;

    crear_emp(E);
    divide(E,e);
    print_by_department(e);
}
