#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCalculater : protected clsScreen
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

	static float FromCurrency2Dolar(float Amount, clsCurrency& CFrom)
	{
		return (float)Amount / CFrom.Rate();
	}

	static float FromDollar2Currency(float AmountinDollar, clsCurrency& C_2)
	{
		return (float)AmountinDollar * C_2.Rate();
	}




public:

	static void ShowCurrencyClaculaterScreen()
	{
		char Answer = 'n';
		do
		{
			system("cls");
			_DrawScreenHeader("\t CurrencyClaculaterScreen");

			string CodeFrom = "";

			cout << "\nPlease Enter Currency Code You want 2 Convert From: ";
			CodeFrom = clsInputValidate::ReadString();
			clsCurrency CFrom = clsCurrency::FindByCode(CodeFrom);

			while (!clsCurrency::IsCurrencyExist(CodeFrom))
			{
				cout << "This Currency Not Found " << nl;
				cout << "Enter Code Again :";
				CodeFrom = clsInputValidate::ReadString();
			}


			string CodeTo = "";

			cout << "\nPlease Enter Currency Code You want 2 Convert to: ";
			CodeTo = clsInputValidate::ReadString();
			clsCurrency C_TO = clsCurrency::FindByCode(CodeTo);

			while (!clsCurrency::IsCurrencyExist(CodeTo))
			{
				cout << "This Currency Not Found " << nl;
				cout << "Enter Code Again :";
				CodeTo = clsInputValidate::ReadString();
			}

			CFrom = clsCurrency::FindByCode(CodeFrom);
			C_TO = clsCurrency::FindByCode(CodeTo);


			cout << "\n\nEnter The Amount You Want 2 Convert it : ";
			float Amount;
			cin >> Amount;

			CodeFrom = clsString::UpperAllString(CodeFrom);
			CodeTo = clsString::UpperAllString(CodeTo);

			float Converted2Dollar = FromCurrency2Dolar(Amount, CFrom);

			cout << Amount << " " << CodeFrom << " = " << Converted2Dollar << " USD" << nl;

			if (clsCurrency::IsCurrencyExist(CodeFrom))
			{
				_PrintCurrencyCard(CFrom);
			}
			cout << "\n\n\n";

			if (clsCurrency::IsCurrencyExist(CodeTo))
			{
				_PrintCurrencyCard(C_TO);
			}

			cout << "\n\n";

			float ConvertedFromDollar = FromDollar2Currency(Converted2Dollar, C_TO);

			cout << Amount << " " << CodeFrom << " = " << ConvertedFromDollar << " " << CodeTo;

			cout << "\n\n";



			cout << "Do You wanna 2 Calc Another Converts y / n ?" << nl;
			cin >> Answer;
		} while (toupper(Answer) == 'Y');

	}

};