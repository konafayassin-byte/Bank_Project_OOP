#include <cpp.h>
#include "clsLoginScreen.h"

int main()
{

    while (true)
    {
        /*
			->if we call This in The _Logout() function in clsMainscreen.h it will 
			_cause a Circular call between the main function and the _Logout() function in clsMainscreen.h
			_& an Error will occur 2 The Compiler that the function is already defined in the main function. 
        */

        clsLoginScreen::ShowLoginScreen();
    }
    
    return 0;
}