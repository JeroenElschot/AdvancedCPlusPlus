#include "MenuHandler.h"

void MenuHandler::showMenu() const
{
    const int ESCAPE = 27;
    for(;;)
    {
        cout << "Starting menu..." << endl;
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
            break;
        if((chosenIndex >= 1) && (chosenIndex <= functions.size()))
        {
            cout << endl;
            (appl->*(functions[chosenIndex-1]->getFunction())) ();
            system("cls");
        } else {
            system("cls");
        }
    }

    system("cls");

    cout << "==== Headquarters ====" << endl << endl;
    cout << "Press l to see the menu" << endl;
    cout << "Press b to bind stuff" << endl;
	cout << "Press ESC to quit" << endl;
	cout << endl;


	while(true){
        char key = getch();
        if(key == ESCAPE){
            cout << "Program is quiting" << endl;
            break;
        } else if(key == 'b'){

        } else {
            break;
        }
    }

    system("cls");
    showMenu();
}


