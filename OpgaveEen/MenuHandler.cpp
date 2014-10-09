#include "MenuHandler.h"

void MenuHandler::showStartMenu() const
{
    const int ESCAPE = 27;
    for(;;)
    {
        system("cls");

        cout << "==== Headquarters ====" << endl << endl;
        cout << "Press l to see the menu" << endl;
        cout << "Press b to bind stuff" << endl;
        cout << "Press ESC to quit" << endl;
        cout << endl;

        char key = getch();

        cout << "gekozen:" << key << endl;

        if(key == ESCAPE)
        {
            cout << "Program is quiting" << endl;
        }
        else if(key == 'b')
        {
        }
        else if (key == 'l')
        {
            showMenu();
        }
        else
        {

        }
    }

    system("cls");
}

void MenuHandler::showMenu() const
{
        cout << endl << endl;

        cout << "===== " << appl->getDescription() << " =====" << endl;

        for(unsigned i = 0; i < functions.size(); i++)
        {
            cout << "\t" << (i+1) << "\t" << functions[i]->getDescription() << endl;
        }
        cout << endl;

        cout << "\t\tChoose Action: " << flush;
        unsigned chosenIndex = 0;
        cin >> chosenIndex;
        if(chosenIndex == 0)
        {

        }
        else if((chosenIndex >= 1) && (chosenIndex <= functions.size()))
        {
            cout << endl;
            (appl->*(functions[chosenIndex-1]->getFunction())) ();
            system("cls");
        }
        else
        {
            system("cls");
        }
}

