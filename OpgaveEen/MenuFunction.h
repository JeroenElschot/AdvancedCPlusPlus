#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H

#include <string>       // voor: std::string
#include <vector>       // voor: std::vector

using std::string;
using std::vector;

class Application; // to fix Application has not been delcared

// The pseudo type for an Application method
typedef void (Application::* ApplFunction) ();

class MenuFunction
{
private:
    const string description;
    const ApplFunction function;
public:
    MenuFunction(const string& d, const ApplFunction& f) : description(d), function(f) {}
    const string getDescription() const
    {
        return description;
    }
    const ApplFunction getFunction() const
    {
        return function;
    }
};

#endif // MENUFUNCTION_H
