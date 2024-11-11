#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsDate.h"
using namespace std;
class clsLoginRegisteration : protected clsScreen
{
    static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord User)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << clsDate::GetSystemDateTimeString();
        cout << "| " << setw(20) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;

    }

public:

    static void ShowUsersList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLogRegistration))
        {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLogs = clsUser::GetLoginRegisterList();
        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vLogs.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(5) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLogs.size() == 0)
            cout << "\t\t\t\tNo Logs Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord R : vLogs)
            {

                _PrintUserRecordLine(R);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};

