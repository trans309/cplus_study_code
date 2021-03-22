#include "head.h"

//计算器------普通实现

class calculator
{
public:

    int a;
    int b;

    calculator(int sa,int sb)
    {
        a=sa;
        b=sb;
//        cout<<"这是calculator构造--father"<<endl;
    }

    int getresult(string oper)
    {
        if(oper=="+")
        {
            return a+b;
        }

        else if(oper=="-")
        {
            return a-b;
        }

        else if(oper=="*")
        {
            return a*b;
        }

        else if(oper=="/")
        {
            return a/b;
        }
        return 0;
    }
};

//class print:public calculator
//{
//public:
//    print()
//    {
////        cout<<calculator::sum<<endl;
////        cout<<"这是print构造--son"<<endl;
//    }
//};





//计算器--多态实现

class abstract_calculator
{
public:
    int a;
    int b;

    virtual int getresult()//抽象计算器，虚函数
    {
        return 0;
    }
};

class add_calu:public abstract_calculator
{
    int getresult()
    {
        return a+b;
    }
};

class sub_calu:public abstract_calculator
{
    int getresult()
    {
        return a-b;
    }
};

class mul_calu:public abstract_calculator
{
    int getresult()
    {
        return a*b;
    }
};

class div_calu:public abstract_calculator
{
    int getresult()
    {
        return a/b;
    }
};




void Calculator()
{

//    //普通调用
//    calculator ex(100,29);
//    cout<<ex.getresult("+")<<endl;
////    ex.add();





    //多态调用

    abstract_calculator* abc=new div_calu;
    abc->a=107;
    abc->b=11;
    cout<<abc->getresult()<<endl;


}

void Calculator_test()
{
    Calculator();
}
