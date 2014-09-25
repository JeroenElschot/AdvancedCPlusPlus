#include <string>       // voor: std::string
using std::string;

class MenuFunction
{
private:
    const string description;
    const ApplFunction function;
public:
    //MenuFunction(...,...) : ... {}
    const string getDescription() const
    {
        //...
    }
    const ApplFunction getFunction() const
    {
        //...
    }
};
