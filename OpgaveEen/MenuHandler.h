#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <map>

#include "MenuFunction.h"

class Application;
class MenuFunction;


class MenuHandler
{
    Application * const appl;
    vector<MenuFunction*> const & functions;
    map<char,MenuHandler*> *menus;
    map<char, int> *keys;

    public:

        MenuHandler(Application *app) : appl(app), functions(app->getFunctions())
        {
            keys = new map<char, int>();
            menus = new map<char,MenuHandler*>();
        }
        void showStartMenu() const;
        void showMenu() const;
        void BindFunctions() const;
        void unBind() const;
        void gosub(int);
        void makeSub() const;

};

#endif // MENUHANDLER_H
