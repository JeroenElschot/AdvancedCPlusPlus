#include "BaseClass.cpp" // for the public Application

// A derived class for a specific Factory
class Factory : public Application
{
//...
public:
    Factory();
// the methods to be called from the menu
    void addSupplier();
    void addMachine();
    void addProblem();
//...
};
