#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int ESCAPE = 27;


class MenuHandler
{
    // Application call
    // vector with menufunctions
    public:
        MenuHandler();
        void showMenu() const;

};

#endif // MENUHANDLER_H
