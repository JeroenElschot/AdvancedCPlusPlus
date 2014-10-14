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
    vector<MenuFunction*> const & functions; // aanbod van applicatie
    vector< map<char,MenuFunction*> *>         menus;
        std::map<int, char> *keys;

    private:
        //typedef std::map<int, char*> keys; // bind a key to a function index

    public:

        MenuHandler(Application *app) : appl(app), functions(app->getFunctions()){}
        void showStartMenu() const;
        void showMenu() const;
        void BindFunctions() const;
        void unbind();
        void gosub(int);

};

#endif // MENUHANDLER_H
