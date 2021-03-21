#include "OperatorOverloading.h"

class num
{
public:
    int ma;

    num(int a)
    {
        ma=a;
    }

    num& operator++()
    {
        ma++;
        return *this;
    }

    num operator++(int)
    {
        num temp=*this;
        ma++;
        return temp;
    }

};

ostream& operator<<(ostream& cout,num t)
{
    cout<<t.ma;
    return cout;
}

void test3()
{
    num p(10);
//    p++;
//    cout<<p++<<endl;
//    cout<<p<<endl;
    cout<<++p<<endl;
    cout<<++(++p)<<endl;
}
