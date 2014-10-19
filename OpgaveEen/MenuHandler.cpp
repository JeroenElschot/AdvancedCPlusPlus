#include "MenuHandler.h"


void MenuHandler::showStartMenu() const
{
    const int ESCAPE = 27;
    for(;;)
    {
        system("cls");

        cout << "==== Headquarters ====" << endl << endl;
        cout << "Press b to bind stuff" << endl;
        cout << "Press m to make a submenu" << endl;

        std::map<int,char>::iterator it;
        std::map<char,MenuHandler*>::iterator itmenu;
        for (std::map<int,char>::iterator it= keys->begin(); it!=keys->end(); ++it)
        {
            string functionname = functions[it->first]->getDescription();
            std::cout << it->second << " => " << functionname << '\n';
        }

       for (std::map<char,MenuHandler*>::iterator itmenu= menus->begin(); itmenu!=menus->end(); ++itmenu)
        {
            MenuHandler *mh = itmenu->second;
            mh->showStartMenu();
            std::cout << itmenu->second << " submenu " << '\n';
        }

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
        else if (key == 'm')
        {
            makeSub();
        }
        else
        {
            for (std::map<int,char>::iterator it= keys->begin(); it!=keys->end(); ++it) // go through all the keys that have a binding
            {
                if( it->second == key) // if key is equal to the key of a binding
                {
                    (appl->*(functions[it->first]->getFunction())) (); // execute the function
                }
            }
        }
    }

    system("cls");
}

void MenuHandler::makeSub() const
{
    cout << "You have created a new sub menu" << endl;
    cout << "press a key to bind this new menu" << endl;
    char chosenKey = 'x'; // some default value
    cin >> chosenKey;

    MenuHandler *newMenu = new MenuHandler(appl);
    menus->insert(make_pair(chosenKey, newMenu) );

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
            keys->insert(make_pair(chosenIndex-1, chosenKey) );
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

