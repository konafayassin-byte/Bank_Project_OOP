#pragma once
#include "clsScreen.h"
#include"clsCurrency.h"

class clsCurrencyList : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Currency.Country();
        cout << "| " << setw(20) << left << Currency.CurrencyCode();
        cout << "| " << setw(12) << left << Currency.CurrencyName();
        cout << "| " << setw(20) << left << Currency.Cur;
        cout << "| " << setw(10) << left << Currency.;
        cout << "| " << setw(12) << left << Currency.;

    }
};
