#include "OperatorOverloading.h"

class abc
{
public:
//    void operator()(int test)
//    {
//        cout<<"����α����"<<test<<endl;
//    }

    void operator()(int c,string ch)
    {
        a=c;
        cout<<ch<<":"<<a<<endl;
    }

    int a;
};

void test6()
{
    abc exma;
    exma(21,"����Ϊ");
}


