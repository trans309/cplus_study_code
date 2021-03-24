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


    //虚析构
    virtual ~BASE()
    {
        cout<<"(析构)制作成功！！"<<endl;
        cout<<"------------------"<<endl;
    }


    //纯虚析构
//    virtual ~BASE()=0;
};

//纯虚析构实现
//BASE::~BASE()
//{
//    cout<<"(析构)制作成功！！"<<endl;
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
        cout<<"加入纯净水"<<endl;
    }
    void boil()
    {
        cout<<"烧水ing"<<endl;
    }
    void additive()
    {
        cout<<"加入茶叶"<<endl;
    }
    void enrichment(){}
};

class COFFEE:public BASE
{
public:
    void water()
    {
        cout<<"加入纯净水"<<endl;
    }
    void boil()
    {
        cout<<"烧水ing"<<endl;
    }
    void additive()
    {
        cout<<"加入咖啡"<<endl;
    }
    void enrichment()
    {
        cout<<"coffee浓缩ing"<<endl;
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
