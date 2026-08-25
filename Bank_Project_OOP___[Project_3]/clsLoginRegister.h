#pragma once
#include<cpp.h>
#include"clsDate.h"


class clsLoginRegister
{
private:

    static string _ConverUserObjectToLine(clsUser& User , string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += clsDate::DateToString(clsDate::GetSystemDate()) += " - ";
        UserRecord += clsDate::GetSystemTimeString()+= " - ";
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += User.GetPassword() + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

    static void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("RegisterLogin.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

public:
    
    static void Save_Logins_2_File(clsUser &User)
    {
        string Data_Line = _ConverUserObjectToLine(User);
        _AddDataLineToFile(Data_Line);
    }


};

