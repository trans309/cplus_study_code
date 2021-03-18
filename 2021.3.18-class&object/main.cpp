#include <iostream>

using namespace std;

class people
{
public:
    int age;
    people(int a):age(a)
    {
        age=a;
    }
    people& p_age_add(people p)
    {
        age+=p.age;
        return *this;
    }
};
int main()
{
    people p1(10);
    people p2(10);
    cout<<p2.age<<endl;
    p2.p_age_add(p1).p_age_add(p1).p_age_add(p1);
    cout<<p2.age<<endl;
    return 0;
}
