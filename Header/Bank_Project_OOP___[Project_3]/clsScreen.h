#pragma once
#include <iostream>
#include"clsDate.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsScreen
{
private : 
    static void _Draw_Date_UserName()
    {
        cout << "\n\t\t\t|User name : " << CurrentUser.UserName << "\t|User Full name : " << CurrentUser.FullName()<<"\t|Currnet Date : " << clsDate::DateToString(clsDate::GetSystemDate()) <<"|" <<nl<< nl;
    }
    
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________"<<nl;
        _Draw_Date_UserName();
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            _Draw_Date_UserName();
            return false;
        }
        else
        {
            return true;
        }

    }

};

