#include "OperatorOverloading.h"

//��=�������д���Ĭ�Ͽ���������Ա������ֵ����
//ֵ������������ǳ����
//��������ɽ��ǳ��������

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
