#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"
class clsFindCurrencyScreen : protected clsScreen
{
private:
    enum eOptions {Country = 1, Code = 2};

    static void _PrintCurrencyCard(clsCurrency Currency)
    {
        cout << "_______________________________________" << nl;
        cout << "| " <<"Currency Country      : " << Currency.Country() << nl;
        cout << "| " <<"Currency CurrencyCode : " << Currency.CurrencyCode() << nl;
        cout << "| " <<"Currency CurrencyName : " << Currency.CurrencyName() << nl;
        cout << "| " <<"Currency Rate / (1$)  : " << Currency.Rate() << nl;
        cout << "_______________________________________" << nl;
    }

    static int _ReadCurrencyOptions()
    {
         cout << "Choose what do you want to do? [1]--->Country | [2]--->Code ? ";
         short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "Enter What you want 2 Do? ");
         return Choice;
    }

    static bool _FindByCountry()
    {
        vector <clsCurrency> _vCurrency = clsCurrency::GetCurrenciesList();
        cout << nl<<"Enter The Country :";
        string country;
        cin >> country;
        country = clsString::UpperFirstLetterOfEachWord(country);
        for (clsCurrency& C : _vCurrency)
        {
            if (C.Country() == country)
            {
                cout << "Currncy Found"<<nl;
                _PrintCurrencyCard(C);
                return true;
            }
        }
        cout << "Currncy Not Found" << nl;
        return false;
    }

    static bool _FindByCode()
    {
        vector <clsCurrency> _vCurrency = clsCurrency::GetCurrenciesList();
        cout <<nl<< "Enter The Code : ";
        string Code;
        cin >> Code;
        Code = clsString::UpperAllString(Code);
        for (clsCurrency& C : _vCurrency)
        {
            if (C.CurrencyCode() == Code)
            {
                cout << "Currncy Found" << nl;
                _PrintCurrencyCard(C);
                return true;
            }
        }
        cout << "Currncy Not Found" << nl;
        return false;
    }

    
    static void _PerformFindCurrencyOption(eOptions Op)
    {
        switch (Op)
        {
            case eOptions::Country :
                clsFindCurrencyScreen::_FindByCountry();
                break;
            case eOptions::Code:
                clsFindCurrencyScreen::_FindByCode();
            break;
        default:
            break;
        }
    }

public:
    
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t\t[Find Currency Screen]");

        _PerformFindCurrencyOption(eOptions(_ReadCurrencyOptions()));

    }

};