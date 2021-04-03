#include <iostream>

using namespace std;

#include "STL.h"
#include <vector>

void test1()
{
    vector<vector<int> >v;

    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    for(int i=0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(vector<vector<int> >::iterator i1=v.begin();i1<v.end();i1++)
    {
        for(vector<int>::iterator i2=(*i1).begin();i2<(*i1).end();i2++)
        {
            cout<<*i2<<" ";
        }
        cout<<endl;
    }
}
