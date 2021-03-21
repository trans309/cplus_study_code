#include "OperatorOverloading.h"

class exmaple
{
public:
    string name;
    int age;

    exmaple(string na,int a)
    {
        name=na;
        age=a;
    }

    bool operator==(exmaple& e2)
    {
        if(name==e2.name&&age==e2.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

void test5()
{
    exmaple e1("asdas",32);
    exmaple e2("asdas",32);

    if(e1==e2)
    {
        cout<<"same"<<endl;
    }

    else
    {
        cout<<"not same"<<endl;
    }
}
