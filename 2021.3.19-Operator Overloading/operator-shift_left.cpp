#include "OperatorOverloading.h"

class opera_shift_left
{
public:

    opera_shift_left(int a,int b):m_a(a),m_b(b)
    {
        m_a=a;
        m_b=b;
    }

//    opera_shift_left operator<<(opera_shift_left& t,ostream& cout)
//    {
//        cout<<"a="<<t.m_a<<"b="<<t.m_b;
//    }
    int m_a;
    int m_b;
};

ostream& operator<<(ostream& cout,opera_shift_left t)
{
    cout<<"a="<<t.m_a<<" b="<<t.m_b;
    return cout;
}
void test2()
{
    opera_shift_left a(10,20);
    cout<<a<<endl;
}
