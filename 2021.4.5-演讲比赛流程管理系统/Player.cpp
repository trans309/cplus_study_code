#include <iostream>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"

Player::Player(int Idnum,string Name,double Score)
{
    this->m_Idnum=Idnum;
    this->m_Name=Name;
    this->m_Score=Score;
}

Player::Player()
{

}
