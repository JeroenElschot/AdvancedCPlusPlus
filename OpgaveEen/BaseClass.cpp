#include <string>       // voor: std::string
#include <vector>       // voor: std::vector
#include "MenuFunction.cpp"
using std::string;
using std::vector;

class Application   // The Application baseclass
{
protected:
    const string description; // menu title
    vector<MenuFunction*> functions; // menu entries
public:
    Application(const string& s) : description(s) {}
    virtual ~Application()
    {
        //…
    } // for cleanup
    const string& getDescription() const
    {
        return description;
    }
    const vector<MenuFunction*>& getFunctions() const
    {
        return functions;
    }
};
