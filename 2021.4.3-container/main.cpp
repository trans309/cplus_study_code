#include <iostream>
#include "container.h"
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

class compare_set
{
public:
    bool operator()(int e1,int e2)
    {
        return e1>e2;
    }
};

int main()
{
//    test1();
    test2();





    //set排序

//    set<int,compare_set>s;
//
//    s.insert(41);
//    s.insert(43);
//    s.insert(44);
//    s.insert(42);
//    s.insert(34);
//    s.insert(24);
//
//    for(set<int,compare_set>::iterator it=s.begin();it!=s.end();it++)
//    {
//        cout<<*it<<endl;
//    }






    //multimap插入重复数据

//    multimap<int,int>m;
//
//    m.insert(pair<int,int>(3,40));
//    m.insert(make_pair(3,79));
//    m.insert(make_pair(1,69));
//    m.insert(make_pair(2,49));
//    m.insert(make_pair(3,29));
//
////    cout<<m[3,40]<<endl;
//
//    for(multimap<int,int>::iterator it=m.begin();it!=m.end();it++)
//    {
//        cout<<it->first<<"\t"<<it->second<<endl;
//    }

    return 0;
}
