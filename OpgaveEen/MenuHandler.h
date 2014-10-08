#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Application.h"

using namespace std;



class MenuHandler
{
    Application * const appl;
    // vector with menufunctions
    public:
        MenuHandler(Application *app) : appl(app){}
        void showMenu() const;

};

#endif // MENUHANDLER_H
