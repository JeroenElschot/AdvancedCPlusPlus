#ifndef FACTORY_H
#define FACTORY_H
#include "Application.h"

class Factory : public Application {
    public:
        Factory();
    void sayHello();
    void quitProgram();
    void calc();
    void realQuit();
    void changeNiceColor();
};

#endif // FACTORY_H
