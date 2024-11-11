#pragma once
#include <iostream>
#include <iomanip>
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurreniesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enCurrencyExhangeMenue {
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalculator = 4,
		eMainMenue = 5
	};
	static int _ReadCurrencyExchangeChoose()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		int Choose = clsInputValidate<int>::ReadNumberBetween(1, 5, "\nEnter Number between 1 to 5 ? ");
		return Choose;
	}
	static void _GoBackMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenueCurrency();
	}
	static void _ShowListCurrencies()
	{
		//cout << "\n\nList Currencies Will Be here Soon!!";
		clsCurreniesListScreen::_ShowCurrencyScreen();
	}
	static void _ShowFindCurrency()
	{
		//cout << "\n\nFind Currencies Will Be Here Soon!!";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRate()
	{
		//cout << "\n\nUpdate Rate Will Be Here Soon!!";
		clsUpdateCurrencyScreen::ShowUpdateScreenCurrency();
	}
	static void _ShowCurrencyCalculator()
	{
		//cout << "\n\nCurrency Calculator Will Be Here Soon!!";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _ShowMainMenue()
	{

	}

	static void _PerforminceMainMenue(enCurrencyExhangeMenue TypeMenue)
	{
		switch (TypeMenue)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
		{
			system("cls");
			_ShowListCurrencies();
			_GoBackMainMenue();
			break;
		}
		case clsCurrencyExchangeScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrency();
			_GoBackMainMenue();
			break;
		}
		case clsCurrencyExchangeScreen::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRate();
			_GoBackMainMenue();
			break;
		}
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackMainMenue();
			break;
		}
		case clsCurrencyExchangeScreen::eMainMenue:
		{
		
		}

		}

	}

public:


	static void ShowMainMenueCurrency()
	{

		system("cls");
		_DrawScreenHeader("\t\tCurrency Exhange Menue");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerforminceMainMenue((enCurrencyExhangeMenue)_ReadCurrencyExchangeChoose());
		
	}

};

