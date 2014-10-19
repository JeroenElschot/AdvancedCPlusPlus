#include <iostream>
#include "Factory.h"
#include "MenuFunction.h"
#include <conio.h>
#include <unistd.h>
#include <cstdlib>
#define METHOD(method) \
    static_cast<ApplFunction>(&Factory::method)

//const string& s, ApplFunction& func

Factory::Factory(): Application("Application Menu")
{
    functions.push_back(new MenuFunction("Say Hello", METHOD(sayHello) ));
    functions.push_back(new MenuFunction("Calculate something ",METHOD(calc ) ));
   // functions.push_back(new MenuFunction("Quit program",&Factory::quitProgram ));
   // functions.push_back(new MenuFunction("Please quit it ",&Factory::realQuit ));
   // functions.push_back(new MenuFunction("Color me", &Factory::changeNiceColor ));
}

void Factory::sayHello()
{
    cout << "Hello, how are you today?" << endl;
    cout << "Press a key to close function" << endl;
    getch();
}


void Factory::quitProgram()
{
    cout << "Not quiting anything, keep on playing" << endl;
    cout << "Press a key to close function" << endl;
    getch();
}

void Factory::calc(){

    unsigned firstNumber = 0;
    unsigned secondNumber = 0;

    cout << "Opening calculator.." << endl;
    cout << "Enter number: ";
    cin >> firstNumber;
    cout << endl;
    cout << "Enter number: ";
    cin >> secondNumber;
    cout << endl;
    cout << "Result " << firstNumber + secondNumber << endl;

    cout << "Press a key to close function" << endl;
    getch();
}

void Factory::realQuit(){
    cout << "Its to much fun to quit now!" << endl;
    cout << "Press a key to close function" << endl;
    getch();
}

void Factory::changeNiceColor()
{
    for(int i = 0; i < 10; i++)
    {
		system("Color 1A");
		system("Color 2B");
		system("Color 3C");
		system("Color 4D");
		system("Color 5E");
		system("Color 6F");
		system("Color A1");
		system("Color B2");
		system("Color C3");
		system("Color D4");
		system("Color E5");
		system("Color F6");
		system("Color Z1");
    }
    cout << "Thats a nice color to have right?" << endl;
    cout << "Press a key to close function" << endl;
    getch();
}


