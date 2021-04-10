#pragma once

using namespace std;

#include <iostream>
#include <string>

class Identity
{
public:

    string I_Name;//ĞÕÃû
    string I_Password;//ÃÜÂë

    virtual void Registration_menu(){}//×¢²á²Ëµ¥
    virtual void Login_menu(){}//µÇÂ½²Ëµ¥
};
