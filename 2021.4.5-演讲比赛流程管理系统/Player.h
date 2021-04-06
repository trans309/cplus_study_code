#pragma once
#include <iostream>

using namespace std;

#include <string>

class Player
{
public:

    int m_Idnum;
    string m_Name;
    double m_Score;

    Player(int Idnum,string Name,double Score);
    Player();
};
