#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "_______________________________________" << nl;
		cout << "| " << "Currency Country      : " << Currency.Country() << nl;
		cout << "| " << "Currency CurrencyCode : " << Currency.CurrencyCode() << nl;
		cout << "| " << "Currency CurrencyName : " << Currency.CurrencyName() << nl;
		cout << "| " << "Currency Rate / (1$)  : " << Currency.Rate() << nl;
		cout << "_______________________________________" << nl;
	}

	static void ReadRate_Update(clsCurrency &C)
	{
		float Rate;
		cout << "Enter The Rate you want 2 update : " << nl;
		cin >> Rate;

		C.UpdateRate(Rate);
	}

public:
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Rate Screen");

		string Code = "";

		cout << "\nPlease Enter Currency Code: ";
		Code = clsInputValidate::ReadString();
		Code = clsString::UpperAllString(Code);

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "This Currency Not Found " << nl;
			Code = clsInputValidate::ReadString();
			Code = clsString::UpperAllString(Code);
		}

		clsCurrency C = clsCurrency::FindByCode(Code);

		_PrintCurrencyCard(C);

		cout << "\nAre you sure you want to update this Currncy Rate [y/n]? ";

		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Currncy Rate:";
			cout << "\n____________________\n";

			ReadRate_Update(C);

			cout << "Currncy Rate Updated Sccessfully ! & New Rate is " << C.Rate();

			_PrintCurrencyCard(C);

		}
		else
		{
			return;
		}


	}

};