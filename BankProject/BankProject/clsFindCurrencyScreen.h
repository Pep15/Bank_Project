#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen: protected clsScreen
{
private:

	
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

	static void _ShowFindCurrencyScreen(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCardOfCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}


public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen\n");
		
		cout << "\nFind By: [1] Code or [2] Country? ";
		short Answer = 1;

		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency CurrencyByCode = clsCurrency::FindByCode(CurrencyCode);
			_ShowFindCurrencyScreen(CurrencyByCode);
		}
		else
		{
			string CurrencyCountry;
			cout << "\nPlease Enter Country Name: ";
			CurrencyCountry = clsInputValidate<string>::ReadString();
			clsCurrency CurrencyByCountry = clsCurrency::FindByCountry(CurrencyCountry);
			_ShowFindCurrencyScreen(CurrencyByCountry);
		}
	}


	
};

