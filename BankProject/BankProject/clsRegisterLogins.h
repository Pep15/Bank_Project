#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "clsUtil.h"
#include "clsDate.h"
#include "Global.h"
#include "clsUser.h"
#include "clsString.h"
class clsRegisterLogins
{
	
private:
	static string _ConvertLogsObjectsToLine(clsUser logs, string Seprater = "#//#")
	{
		string LineLogs = "";
		LineLogs += clsDate::DateToString(clsDate());
		LineLogs += Seprater + CurrentUser.UserName;
		LineLogs += Seprater + CurrentUser.Password;
		LineLogs += Seprater + to_string(CurrentUser.Permissions);

		return LineLogs;
	}
	
public:

	static void SaveLogs(vector <clsUser> vlogs)
	{
		
		fstream Myfile;
		Myfile.open("Logs.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			string sLineDate;
			while (getline(Myfile, sLineDate))
			{
				for (clsUser& L : vlogs)
				{
					sLineDate = _ConvertLogsObjectsToLine(L);
					Myfile << sLineDate << endl;
				}
			}

			Myfile.close();
		}


	}
	
};

