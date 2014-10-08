#include "MenuHandler.h"

MenuHandler::MenuHandler()
{

}

void MenuHandler::showMenu() const
{

    cout << "Press ESC to quit" << endl;

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


