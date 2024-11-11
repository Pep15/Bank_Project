#pragma once
#include <iostream>
#include <string>
#include "fstream"
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
using namespace std;
class clsCurrency
{
private:
	enum enMode
	{
		EmptyMode = 0,
		UpdateMode = 1
	};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1]
			, vCurrencyData[2], stod(vCurrencyData[3]));
	}
	static string _CovnertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stCurrenctRecord = "";
		stCurrenctRecord += Currency.GetCountery() + Seperator;
		stCurrenctRecord += Currency.GetCurrencyCode() + Seperator;
		stCurrenctRecord += Currency.GetCurrencyName() + Seperator;
		stCurrenctRecord += to_string(Currency.GetRate());

		return stCurrenctRecord;
	}
	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		vector <clsCurrency> vCurrencys;
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}

			Myfile.close();
		}

		return vCurrencys;
	}
	static void _SaveCurrencyDateToFile(vector <clsCurrency> vCurrencys)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out | ios::app);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrencys)
			{
				DataLine = _CovnertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();
		for (clsCurrency& C : _vCurrencys)
		{
			C = *this;
			break;
		}

		_SaveCurrencyDateToFile(_vCurrencys);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrency(enMode Mode, string Countery, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Countery;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	string GetCountery()
	{
		return _Country;
	}
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float GetRate()
	{
		return _Rate;
	}
	static clsCurrency FindByCode(string CurremcyCode)
	{
		CurremcyCode = clsString::UpperAllString(CurremcyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.GetCurrencyCode() == CurremcyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.GetCountery()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}
	float ConvertToUSD( int Amount)
	{
		return (float) (Amount / GetRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.GetRate());
	}
};

