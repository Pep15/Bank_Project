#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
{
private:
	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float Rate = 0;
		Rate = clsInputValidate<float>::ReadNumber();

		return Rate;
	}
	static void _PrintCardOfCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "\n________________________";
		cout << "\nCountry     : " << Currency.GetCountery();
		cout << "\nCode        : " << Currency.GetCurrencyCode();
		cout << "\nName        : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) =  : " << Currency.GetRate();
		cout << "\n________________________\n";



	}

public:

	static void ShowUpdateScreenCurrency()
	{
		_DrawScreenHeader("\t Update Currency Screen\n");
		string CurrencyCode;
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate<string>::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was not Found , Please enter correct currency: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCardOfCurrency(Currency);

		char Answer = 'n';
		
		cout << "\n\nAre you sure you want to update the rate of this Currency y/n ";
		cin >> Answer;

		
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n___________________\n";
			
			
			Currency.UpdateRate(_ReadRate());
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCardOfCurrency(Currency);
		}
	}
};

