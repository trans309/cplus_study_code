#include "head.h"
#include "MyArray.hpp"

void test1()
{
    my_array<char> a1(3);
//    my_array<> a2(a1);
//    my_array<> a3(3);
//    a3=a1;

    for(int i=0;i<26;i++)
    {
        a1.push_end(i+97);
    }

    for(int i=0;i<0;i++)
    {
        a1.pop_end();
    }

    a1.print();

    a1.find_elem();


//    for(int i=0;i<10;i++)
//    {
//        *(a1.parr)=i;
//    }
//    my_array<> a2(a1);

}
