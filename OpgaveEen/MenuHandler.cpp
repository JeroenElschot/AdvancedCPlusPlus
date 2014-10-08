#include "MenuHandler.h"

void MenuHandler::showMenu() const
{
    const int ESCAPE = 27;

    cout << "Press ESC to quit" << endl;
    cout << endl << endl;

    //printing heading
    cout << "===== " << appl->getDescription() << " =====" << endl;

    for(unsigned i = 0; i < functions.size(); i++)
    {
        cout << "\t" << (i+1) << "\t" << functions[i]->getDescription() << endl;
    }

    cout << "\t\tChoose Action: " << flush;
    unsigned chosenIndex = 0;
    cin >> chosenIndex;
    if(chosenIndex == 0)
        return;
    if((chosenIndex >= 1) && (chosenIndex <= functions.size()))
    {
        //call method
        (appl->*(functions[chosenIndex-1]->getFunction())) ();
    }
    else
    {
        cout << "No function!" << endl;
    }

    for(;;)
    {
        char key = getch();
        if(key == ESCAPE)
        {
            cout << "Program is quiting" << endl;
            break;
        }
        else if(key == 'b')
        {

        }
    }
}


