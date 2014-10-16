#include "MenuHandler.h"


void MenuHandler::showStartMenu() const
{
    const int ESCAPE = 27;
    for(;;)
    {
        system("cls");

        cout << "==== Headquarters ====" << endl << endl;
        cout << "Press b to bind stuff" << endl;

        // show other functions that were binded here, including sub menus
        //for(unsigned i = 0; i < keys->size(); i++)
        //{
            //do something with iteration
        //}

        cout << "Press ESC to quit" << endl;
        cout << endl;

        char key = getch();

        cout << "gekozen:" << key << endl;

        if(key == ESCAPE)
        {
            cout << "Program is quiting" << endl;
            break;
        }
        else if (key == 'b')
        {
            BindFunctions();
        }
        else
        {

        }
    }

    system("cls");
}

void MenuHandler::BindFunctions() const
{
    cout << endl << endl;

    cout << "Available functions" << endl;
    cout << "Select number to bind" << endl;

    for(unsigned i = 0; i < functions.size(); i++)
    {
        cout << "\t" << (i+1) << "\t" << functions[i]->getDescription() << endl;
    }
    cout << endl;
    cout << "\t\tChoose Function: " << flush;
        unsigned chosenIndex = 0;
        cin >> chosenIndex;
        if(chosenIndex == 0)
        {

        }
        else if((chosenIndex >= 1) && (chosenIndex <= functions.size()))
        {
            cout << endl;
            cout << "\t\t Choose Key: " << flush;
            // do something with actual binding
            // still gives errors after chosen a key
            char chosenKey = 'x'; // some default value
            cin >> chosenKey;
            keys->insert(make_pair(chosenIndex-1, chosenKey));
            cout << "\t\t Toegevoegd: " << chosenKey << "met functie: " << functions[chosenIndex-1]->getDescription() << endl;
            system("cls");
        }
        else
        {
            system("cls");
        }
}

void MenuHandler::unbind()
{
    // go through the bindings and unbind the chosen ones
}

void MenuHandler::gosub(int)
{
    // go to index of menus
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

