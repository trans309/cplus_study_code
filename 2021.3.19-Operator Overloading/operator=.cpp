#include "OperatorOverloading.h"

//“=”在类中存在默认拷贝函数成员，进行值拷贝
//值拷贝可能引发浅拷贝
//改用深拷贝可解决浅拷贝问题

class exmaple
{
public:
    int* ma;

    exmaple(int a)
    {
        ma=new int(a);
    }

    exmaple& operator=(exmaple& t)
    {

        if(ma!=NULL)
        {
            delete(ma);
            ma=NULL;
        }
        ma=new int(*t.ma);
        return *this;
    }

    ~exmaple()
    {
        if(ma!=NULL)
        {
            delete(ma);
            ma=NULL;
        }
    }
};

void test4()
{
    exmaple e1(10),e2(20);
    e1=e2;
    cout<<*e1.ma<<endl;

}
