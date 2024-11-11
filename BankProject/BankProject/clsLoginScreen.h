#pragma once
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include"clsRegisterLogins.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        int FaildLogs = 0;
        string Username, Password;
        do
        {


            if (LoginFaild)
            {
                FaildLogs++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\nYou have " << (3 - FaildLogs) << " Trial(s) to login.\n\n";
            }

            if (FaildLogs == 3)
            {
                cout << "\nYour are Loced after 3 faild trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

