#include <iostream>
#include "Student.h"
#include "Application.h"

using namespace std;

int main()
{
    const string targetDir = "students";
    Application *appl = new Application(targetDir);
    appl->showMenu();

    delete appl;
    return 0;
}
