#include "MenuHandler.h"

MenuHandler::MenuHandler()
{
    //ctor
}

MenuHandler::~MenuHandler()
{
    //dtor
}

void MenuHandler::showMenu() const
{
    for (;;)
    {
        // print heading
        cout << "\n\tTUI: "
             << appl->getDescription() << endl;
        // print the menu
        for (unsigned i = 0; i < functions.size(); ++i)
        {
            cout << "\t" << (i+1) << "\t"
                 << functions[i]->getDescription()
                 << endl;
        }
        cout << "\t0\texit" << endl;
        cout << "\t\tChoose action: " << flush;
        unsigned chosenindex = 0;
        cin >> chosenindex; // read choice
        if (chosenindex == 0)
            return;
        if ( (chosenindex >= 1)
                && (chosenindex <= functions.size()) )
        {
            (appl->*(
                 functions[chosenindex–1]->getFunction())) ();
        }
        else
            cout << "sorry, no such function" << endl;
    }
}
}

