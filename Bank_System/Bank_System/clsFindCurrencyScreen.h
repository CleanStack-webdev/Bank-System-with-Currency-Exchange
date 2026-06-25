#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
			cout << "\nCurrency Was not Found :-(\n";
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t  Find Currency Screen");

		short Answer;
		cout << "\nFind by: [1] Code or [2] Country ? ";
		cin >> Answer;

		string UserInput;

		if (Answer == 1)
		{
			cout << "\nPlease Enter Currency Code: ";
			UserInput = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(UserInput);
			_ShowResults(Currency);
		}
		else if (Answer == 2)
		{
			cout << "\nPlease Enter Country Name: ";
			UserInput = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(UserInput);
			_ShowResults(Currency);
		}
		else
		{
			cout << "\nWrong input";
		}
	}
};

