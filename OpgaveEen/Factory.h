#include "Application.h"

class Factory : public Application
{
public:
    Factory();
    ~Factory();

    // the methods to be called from the menu
    void addSupplier();
    void addMachine();
    void addProblem();
};
