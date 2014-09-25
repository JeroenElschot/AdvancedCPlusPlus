class Application; // forward declaration
class MenuFunction; // forward declaration
class MenuHandler   // The generic handler
{
    Application * const appl;
    vector<MenuFunction*> const & functions;
public:
    MenuHandler(Application *ap)
        : appl(ap)
        , functions(ap->getFunctions())
    {
    }
    void showMenu() const;
};


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
        cout << "\t0\texit" << endlcout << "\t\tChoose action: " << flush;
        unsigned chosenindex = 0;
        cin >> chosenindex; // read choice
        if (chosenindex == 0)
            return;
        if ( (chosenindex >= 1)
                && (chosenindex <= functions.size()) )
        {
            // call the chosen method
            (appl->*(
                 functions[chosenindex–1]->getFunction())) ();
        }
        else
            cout << "sorry, no such function" << endl;
    } //
