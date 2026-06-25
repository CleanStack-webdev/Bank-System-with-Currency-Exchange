#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	enum enCurrenciesMainMenuOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eShowMainMenu = 5
	};

	static short ReadCurrencyExchangeMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _ShowCurrenciesListScreen()
	{
		// cout << "\n  Currencies List Screen will be here.\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		// cout << "\n Find Currency Screen will be here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		// cout << "\n Update Rate Screen will be here.\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		// cout << "\n Currency Calculator Screen will be here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrenciesMenu()
	{
		cout << "\n\nPress any key to go back to Currencies Menu...";
		system("pause>0");
		ShowCurrenciesMenu();
	}

	static void _PerformCurrenciesMainMenuOption(enCurrenciesMainMenuOptions CurrenciesMainMenuOption)
	{
		switch (CurrenciesMainMenuOption)
		{
		case enCurrenciesMainMenuOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eShowMainMenu:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}

public:
	static void ShowCurrenciesMenu()
	{
		system("cls");
		_DrawScreenHeader("\t  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  CurrencyExchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrenciesMainMenuOption((enCurrenciesMainMenuOptions)ReadCurrencyExchangeMenuOption());
	}
};

