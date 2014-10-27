#include "Student.h"

Student::~Student()
{

}

// used to make the student object readable
void Student::toString()
{
    cout << "Naam:" << getSurname() << "\t Achternaam: " << getName() << "\t Plaats: " << getCity() << "\tKlas:" << getClassID() << endl;
}


