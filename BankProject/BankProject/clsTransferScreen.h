#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        return AccountNumber;
    }
    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount = 0;
        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate<float>::ReadNumber();
        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate<float>::ReadNumber();
        }
        return Amount;
    }
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\tTransfer Screen");
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient , CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild  \n";
            }
        }

        
    }
};
