#include "head.h"

class Animal
{
public:

    virtual void speak()=0;

    virtual ~Animal()=0;
};

Animal::~Animal(){}

class cat:public Animal
{
public:

    void speak()
    {
        cout<<"Ã¨Ëµ»°"<<endl;
    }
};


void PVF_test()
{
    Animal *c=new cat;
    c->speak();
    delete c;
}
