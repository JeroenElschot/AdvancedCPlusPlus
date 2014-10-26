#include "Student.h"

Student::~Student()
{

}

void Student::toString(){

    cout << "Naam:" << getSurname() << "\t Achternaam: " << getName() << "\t Plaats: " << getCity() << "\tKlas:" << getClassID() << endl;
}


