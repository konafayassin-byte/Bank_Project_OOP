#include<cpp.h>
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsShow_Main_Screen : protected clsScreen
{
private:

    enum enMain_Menue_Options 
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _Read_MainMenue_Option()
    {
        cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 8]? ";
        short option = clsInputValidate::ReadIntNumberBetween(1 , 8 , "The Number You Entered Isn't in The Range [1 , 8] , Enter Again!");
        return option;
    }

    static  void _Back_2_MainMenue()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
    
        system("pause>0");
        // ShowMainMenue();
    }

    static void _Show_AllClients_Screen()
    {
     cout << "\nClient List Screen Will be here...\n";
     
    }
    
    static void _Show_AddNewClients_Screen()
    {
        cout << "\nAdd New Client Screen Will be here...\n";
      
    }
    
    static void _Show_DeleteClient_Screen()
    {
        cout << "\nDelete Client Screen Will be here...\n";
    }
    
    static void _Show_UpdateClient_Screen()
    {
        cout << "\nUpdate Client Screen Will be here...\n";
    }
    
    static void _Show_FindClient_Screen()
    {
        cout << "\nFind Client Screen Will be here...\n";
    }
    
    static void _Show_Transactions_Menue()
    {
        cout << "\nTransactions Menue Will be here...\n";
    }
    
    static void _Show_ManageUsers_Menue()
    {
        cout << "\nUsers Menue Will be here...\n";
    }
    
    static void _Show_EndScreen()
     {
            cout << "\nEnd Screen Will be here...\n";
     }

    static void _Perfrom_MainMenue_Options(enMain_Menue_Options option)
    {
        switch (option)
        {
        case enMain_Menue_Options::eListClients :
            system("cls");
            _Show_AllClients_Screen();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eAddNewClient :
            system("cls");
            _Show_AddNewClients_Screen();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eDeleteClient :
            system("cls");
            _Show_DeleteClient_Screen();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eUpdateClient :
            system("cls");
            _Show_UpdateClient_Screen();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eFindClient :
            system("cls");
            _Show_FindClient_Screen();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eShowTransactionsMenue :
            system("cls");
            _Show_Transactions_Menue();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eManageUsers :
            system("cls");
            _Show_ManageUsers_Menue();
            _Back_2_MainMenue();
            break;
        case enMain_Menue_Options::eExit :
            system("cls");
            _Show_EndScreen();
            // Login();
            break;
        default:
            break;
        }
    }

public:

    static void ShowMainMenue()
    {
       
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left <<""<< "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _Perfrom_MainMenue_Options((enMain_Menue_Options)_Read_MainMenue_Option());
    }

    
};