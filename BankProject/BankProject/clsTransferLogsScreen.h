#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsTransactionsScreen.h"
#include "Global.h"
#include "clsScreen.h"
using namespace std;
class clsTransferLogsScreen :protected clsScreen
{
private:

    static void _PrintTransferRecordLine(clsBankClient::stLoginTransfer User)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << clsDate::GetSystemDateTimeString();
        cout << "| " << setw(8) << left << User.AccountSource;
        cout << "| " << setw(8) << left << User.AccountDestnation;
        cout << "| " << setw(8) << left << User.Amount;
        cout << "| " << setw(10) << left << User.BalanceSource;
        cout << "| " << setw(10) << left << User.BalanceDestnation;
        cout << "| " << setw(8) << left << CurrentUser.UserName;
    }

public:

   static void ShowTransferLogsScreen()
    {
      

        vector <clsBankClient::stLoginTransfer> Transfer = clsBankClient::GetTransferActionsLogs();

        string Titel = "\t Transfer Log List Screen";
        string subTitle = "\t       (" + to_string(Transfer.size()) + ") Record(s).\n";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (Transfer.size() == 0)
            cout << "\t\t\t\tNo Logs Available In the System!";
        else
        {
            for (clsBankClient::stLoginTransfer& T : Transfer)
            {
                _PrintTransferRecordLine(T);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

