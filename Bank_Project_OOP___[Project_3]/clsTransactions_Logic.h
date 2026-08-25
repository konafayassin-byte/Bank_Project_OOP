#pragma once

#include<iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsClientListScreen;

class clsTransactions : protected clsBankClient
{
private:
    inline static vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

public:

    static void _Deposit()
    {
        string Account_Number = clsInputValidate::ReadString("Enter Account Number :  \n");


        while (!IsClientExist(Account_Number))
        {
            cout << "This Account Number [ " << Account_Number << " ] Isn't found in The System !\n";
            cout << "Try Again !\n";
            Account_Number = clsInputValidate::ReadString("Enter Account Number :  \n");
        }

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == Account_Number)
            {
    
				clsClientListScreen::_PrintClient(C);

                double Cash_Added = 0;
                cout << "\n Enter The cash you want to Add to Account : ";
                cin >> Cash_Added;

                char c;
                cout << "\nAre you sure to add this cash [Y] or [N]? \n";
                cin >> c;

                if (toupper(c) == 'Y')
                {
                    C.AccountBalance += Cash_Added;
                    clsBankClient::_SaveCleintsDataToFile(_vClients);
                    cout << "\n \tThe cash Added Successfully!";
                    cout << "\nNew Balance: " << C.AccountBalance;
                }
                else
                {
                    cout << "No cash Added!";
                }
                return;
            }
        }
        cout << "\nClient with Account Number (" << Account_Number << ") is Not Found!";
    }
/*======================================*/

    static void Withdraw()
    {
        string Account_Number = clsInputValidate::ReadString("Enter Account Number :  \n");

        while (!IsClientExist(Account_Number))
        {
            cout << "This Account Number [ " << Account_Number << " ] Isn't found in The System !\n";
            cout << "Try Again !\n";
            Account_Number = clsInputValidate::ReadString("Enter Account Number :  \n");
        }

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == Account_Number)
            {
                clsClientListScreen::_PrintClient(C);

                double Amount;
                cout << "\n Enter The amount you want to Withdraw: ";
                cin >> Amount;

                while (Amount > C.AccountBalance)
                {
                    cout << "\nAmount Exceeds the balance, you can withdraw up to : " << C.AccountBalance << endl;
                    cout << "Please enter another amount? ";
                    cin >> Amount;
                }


                char c;
                cout << "Are you sure to withdraw this amount [Y] or [N]? \n";
                cin >> c;

                if (toupper(c) == 'Y')
                {
                    C.AccountBalance -= Amount;
                    clsBankClient::_SaveCleintsDataToFile(_vClients);
                    cout << "\n \tThe cash withdrawed Successfully!";
                    cout << "\nNew Balance: " << C.AccountBalance;
                }
                else
                {
                    cout << "No cash withdrawed!";
                }
                return;
            }
        }
        cout << "\nClient with Account Number (" << Account_Number << ") is Not Found!";
    }

    
    

};