#pragma once
#include <iostream>
#include "clsCurrency.h"
#include <iomanip>
#include "clsScreen.h"
class clsCurreniesListScreen : protected clsScreen
{
private:

	static void _PrintCurrenciesListScreen(clsCurrency Currency)
	{
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountery();
        cout << "| " << setw(8) << left << Currency.GetCurrencyCode();
        cout << "| " << setw(45) << left << Currency.GetCurrencyName();
        cout << "| " << setw(10) << left << Currency.GetRate();
	}

public:

  static  void _ShowCurrencyScreen()
        {
        vector <clsCurrency> _vCurrencies = clsCurrency::GetCurrenciesList();
        string Titel = "\t  Currencies List Screen\n";
        string SubTitel = "\t  (" + to_string(_vCurrencies.size()) + ") Currency.\n";

        _DrawScreenHeader(Titel, SubTitel);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (_vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else
        {
            for (clsCurrency C : _vCurrencies)
            {
                _PrintCurrenciesListScreen(C);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

