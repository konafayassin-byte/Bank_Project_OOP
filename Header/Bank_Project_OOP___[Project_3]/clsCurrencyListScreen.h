#pragma once
#include "clsScreen.h"
#include"clsCurrency.h"

class clsCurrencyList : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(35) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();
    }

public:
    static void ShowCurrenciesList()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(ies).";

        _DrawScreenHeader(Title, SubTitle);

        // Removed the stray "op" and adjusted underline length to match
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(35) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else
        {
            for (clsCurrency& Currency : vCurrencies)
            {
                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n" << endl;
    }
};
