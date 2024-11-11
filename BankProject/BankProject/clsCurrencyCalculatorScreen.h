#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsCurrencyExchangeScreen.h"
using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = 0;
		Amount = clsInputValidate<float>::ReadNumber();
		return Amount;

	}
	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;

		CurrencyCode = clsInputValidate<string>::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}
	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.GetCountery();
		cout << "\nCode          : " << Currency.GetCurrencyCode();
		cout << "\nName          : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) =    : " << Currency.GetRate();
		cout << "\n_____________________________\n\n";

	}
	static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.GetCurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(Currency2, "To: ");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.GetCurrencyCode()
			<< " = " << AmountInCurrency2 << Currency2.GetCurrencyCode();
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'y';

		while (Answer == 'y' || Answer == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tUpdate Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease enter Currency2 Code: ");
			float Amount = _ReadAmount();
			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Answer;
		}
	}
};

