#include "head.h"

//������------��ͨʵ��

class calculator
{
public:

    int a;
    int b;

    calculator(int sa,int sb)
    {
        a=sa;
        b=sb;
//        cout<<"����calculator����--father"<<endl;
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
////        cout<<"����print����--son"<<endl;
//    }
//};





//������--��̬ʵ��

class abstract_calculator
{
public:
    int a;
    int b;

    virtual int getresult()//������������麯��
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

//    //��ͨ����
//    calculator ex(100,29);
//    cout<<ex.getresult("+")<<endl;
////    ex.add();





    //��̬����

    abstract_calculator* abc=new div_calu;
    abc->a=107;
    abc->b=11;
    cout<<abc->getresult()<<endl;


}

void Calculator_test()
{
    Calculator();
}
