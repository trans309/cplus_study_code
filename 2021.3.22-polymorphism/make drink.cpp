#include "head.h"

class BASE
{
public:
    virtual void water()=0;
    virtual void boil()=0;
    virtual void enrichment()=0;
    virtual void additive()=0;

    void makedrink_tea();
    void makedrink_coffee();


    //������
    virtual ~BASE()
    {
        cout<<"(����)�����ɹ�����"<<endl;
        cout<<"------------------"<<endl;
    }


    //��������
//    virtual ~BASE()=0;
};

//��������ʵ��
//BASE::~BASE()
//{
//    cout<<"(����)�����ɹ�����"<<endl;
//    cout<<"------------------"<<endl;
//}

void BASE::makedrink_tea()
{
     water();
     boil();
     additive();
}

void BASE::makedrink_coffee()
{
     water();
     boil();
     additive();
     enrichment();

}

class TEA:public BASE
{
public:
    void water()
    {
        cout<<"���봿��ˮ"<<endl;
    }
    void boil()
    {
        cout<<"��ˮing"<<endl;
    }
    void additive()
    {
        cout<<"�����Ҷ"<<endl;
    }
    void enrichment(){}
};

class COFFEE:public BASE
{
public:
    void water()
    {
        cout<<"���봿��ˮ"<<endl;
    }
    void boil()
    {
        cout<<"��ˮing"<<endl;
    }
    void additive()
    {
        cout<<"���뿧��"<<endl;
    }
    void enrichment()
    {
        cout<<"coffeeŨ��ing"<<endl;
    }
};


void MakeDrink_test()
{
    BASE* drink=new COFFEE;
    drink->makedrink_coffee();
    delete drink;

    drink=new TEA;
    drink->makedrink_tea();
    delete drink;

}
