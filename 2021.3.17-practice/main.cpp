#include <iostream>

using namespace std;

void func(const int& a)
{
    cout<<"1";
}

void func(int& a)
{
    cout<<"2";
}
int main()
{
//    const int& a = 10;
//    func(10);

    int a = 10;//->2
    const int b = 10;//->1
//    int& b=a;
    func(a);
    func(b);
    return 0;
}

