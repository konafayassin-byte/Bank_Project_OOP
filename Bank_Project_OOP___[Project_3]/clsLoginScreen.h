#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainscreen.h"
#include "Global.h"
#include "clsLoginRegister.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
        bool LoginFaild = false;

        int t = 3;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                printf("You Have %d Chances for The System Before the system logout",t);
            }

            cout << "\n\nEnter Username:  ";
            cin >> Username;

            cout << "\nEnter Password:  ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            
            if (!LoginFaild)
            {
                break;
            }


        } while (--t > 0);

        if (!LoginFaild)
        {
            clsLoginRegister::Save_Logins_2_File(CurrentUser);
            clsShow_Main_Screen::ShowMainMenue();
        }

        if (LoginFaild)
        {
            exit(0);
        }

    }



public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

