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
        cout << "Press u to unbind stuff" << endl;

//         show other functions that were binded here, including sub menus


        std::map<int,char>::iterator it;
        std::map<char,MenuHandler*>::iterator itmenu;
        for (std::map<char,int>::iterator it= keys->begin(); it!=keys->end(); ++it)
        {
            string functionname = functions[it->second]->getDescription();
            std::cout << it->first << " => " << functionname << '\n';
        }

        for (std::map<char,MenuHandler*>::iterator itmenu= menus->begin(); itmenu!=menus->end(); ++itmenu)
        {
            //MenuHandler *mh = itmenu->second;
            std::cout << itmenu->first << " => submenu " << '\n';
        }

        cout << "Press ESC to go back or exit" << endl;
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
        else if(key == 'u')
        {
            unBind();
        }
        else
        {
            bool ismenu = false;
            for (std::map<char,MenuHandler*>::iterator itmenu= menus->begin(); itmenu!=menus->end(); ++itmenu)
            {
                if(itmenu->first == key) // if key is equal to an item in menus, go to that menu
                {
                    MenuHandler *mh = itmenu->second;
                    mh->showStartMenu();
                    ismenu = true;
                }
            }

            if(ismenu != true) // if the key is not in a menu, check if the key belongs to a function
            {
                for (std::map<char,int>::iterator it= keys->begin(); it!=keys->end(); ++it) // go through all the keys that have a binding
                {
                    if( it->first == key) // if key is equal to the key of a binding
                    {
                        (appl->*(functions[it->second]->getFunction())) (); // execute the function
                    }
                }
            }

        }
    }

    system("cls");
}

void MenuHandler::makeSub() const
{
    cout << "press a key to bind this new menu" << endl;
    char chosenKey; // some default value
    cin >> chosenKey;

    bool keyExists = false;
    for (std::map<char,int>::iterator it= keys->begin(); it!=keys->end(); ++it) // go through all the keys that have a binding
    {
        if( it->first == chosenKey) // if key is equal to the key of a binding
        {
            keyExists = true;
            break;
        }
    }
    if(!keyExists) // if key not exists, bind menu to it
    {
        MenuHandler *newMenu = new MenuHandler(appl);
        menus->insert(make_pair(chosenKey, newMenu) );
        cout << "You have created a new sub menu" << endl;
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
        // do something with actual binding
        // still gives errors after chosen a key

        char chosenKey; // some default value

        for(;;)
        {
            cout << endl;
            cout << "\t\t Choose Key: " << flush;

            cin >> chosenKey;
            if(chosenKey == 'b')
            {
                cout << "Cannot bind the bind function" << endl;
                cout << "Try again" << endl;
            }
            else if(chosenKey == 'u')
            {
                cout << "Cannot bind the unbind function" << endl;
                cout << "Try again" << endl;
            }
            else
            {
                bool keyExists = false;
                for (std::map<char,int>::iterator it= keys->begin(); it!=keys->end(); ++it) // go through all the keys that have a binding
                {
                    if( it->first == chosenKey) // if key is equal to the key of a binding
                    {
                        keys->erase(it);
                        keyExists = true;
                        break;
                    }
                }

                if(keyExists){
                    cout << "Binding already exists and will be overrided" << endl;
                    break;
                } else {
                    break;
                }
            }
        }

        cout << "erase" << endl;
        keys->insert(make_pair(chosenKey,chosenIndex-1) );
        system("cls");
    }
    else
    {
        system("cls");
    }
}

void MenuHandler::unBind() const
{
    cout << endl << endl;

    cout << "Select a key you want to unbind" << endl;

    char chosenKey; // some default value

    for(;;)
    {
        cout << endl;
        cout << "\t\t Choose Key: " << flush;

        cin >> chosenKey;

        for (std::map<char,int>::iterator it= keys->begin(); it!=keys->end(); ++it)
        {
            if(it->first == chosenKey) // if key is equal to the key of the iterator key , erase it
            {
                keys->erase(it);
            }
        }
        for (std::map<char,MenuHandler*>::iterator itmenu= menus->begin(); itmenu!=menus->end(); ++itmenu)
        {
            if(itmenu->first == chosenKey) // same way as the keys
            {
                menus->erase(itmenu);
            }
        }

        break;
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

