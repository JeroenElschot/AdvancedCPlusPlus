#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    string surname;
    string city;
    string gender;
    string classID;

public:
    Student(string theName, string theSurname, string theCity, string theGender, string theClassID)
    {
        name = theName;
        surname = theSurname;
        city = theCity;
        gender = theGender;
        classID = theClassID;
    }

    ~Student();

    //Getters
    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
    string getCity()
    {
        return city;
    }
    string getGender()
    {
        return gender;
    }
    string getClassID() const
    {
        return classID;
    }

    //Setters
    void setName(string pName)
    {
        name = pName;
    }
    void setSurname(string pSurname)
    {
        surname = pSurname;
    }
    void setCity(string pCity)
    {
        city = pCity;
    }
    void setGender(string pGender)
    {
        gender = pGender;
    }
    void setClassID(string pClassID)
    {
        classID = pClassID;
    }

    void toString();

    bool operator<(const Student &student) const
    {
        return surname < student.classID;
    }

    bool operator==(const Student &student) const
    {
        if(name == student.name && surname == student.surname)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // STUDENT_H
