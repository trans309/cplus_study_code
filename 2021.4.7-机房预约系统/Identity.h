#pragma once

using namespace std;

#include <iostream>
#include <string>

class Identity
{
public:

    string I_Name;//����
    string I_Password;//����

    virtual void Registration_menu(){}//ע��˵�
    virtual void Login_menu(){}//��½�˵�
};
