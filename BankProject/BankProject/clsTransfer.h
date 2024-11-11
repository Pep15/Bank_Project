#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsTransfer : protected clsScreen
{
private:
    static void _PrintClientsCard(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber(string Massage)
    {
        string AccountNumber;
        //cout << "\nPlease Enter Account Number to Transfer From: ";
        cout << Massage;
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            cin >> AccountNumber;
        }
        return AccountNumber;
    }


public:

    static void ShowScreenClinetsTransfer()
    {
        _DrawScreenHeader("\tTransfer Screen");
        clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From: "));
        _PrintClientsCard(Client1);
        clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To: "));
        _PrintClientsCard(Client2);



        cout << "\n\nEnter Transfer Amount? ";
        int Amount = clsInputValidate<double>::ReadNumber();

        cout << "\n\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Withdraw(Amount))
            {
                Client2.Deposit(Amount);
                cout << "\nTransfer done successfully\n\n";
                _PrintClientsCard(Client1);
                _PrintClientsCard(Client2);
            }
            else
            {
                cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
                Amount = clsInputValidate<double>::ReadNumber();
            }
        }
        
    }
};

