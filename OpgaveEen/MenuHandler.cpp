#include "MenuHandler.h"

void MenuHandler::showMenu() const
{
    const int ESCAPE = 27;

    cout << "Press ESC to quit" << endl;
    cout << endl << endl;

    //printing heading
    cout << "=====" << appl->getDescription() << "=====" << endl;

    for(;;)
    {
        char key = getch();
        if(key == ESCAPE)
        {
            cout << "Program is quiting" << endl;
            break;
        }
        else if(key = 'b')
        {

        }
    }
}


