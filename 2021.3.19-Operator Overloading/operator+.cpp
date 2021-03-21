#include "OperatorOverloading.h"

class opadd
{
public:
    opadd(int a=0)
    {
        m_a=a;
    }
    opadd operator+(opadd& p)
    {
        opadd temp;
        temp.m_a=p.m_a+this->m_a;
        return temp;
    }

    int m_a;
};

//opadd operator+(opadd& p1,opadd& p2)
//{
//    opadd temp;
//    temp.m_a=p1.m_a+p2.m_a;
//    return temp;
//}


void test1()
{
    opadd p1(10);
    opadd p2(12);
    opadd p4(10);
    opadd p3=p1+p2+p4;

    cout<<p3.m_a;
}
