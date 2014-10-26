#include <conio.h>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <string>

#include "Application.h"
#include "FileReader.h"

using namespace std;

Application::~Application()
{

}

struct CompareByClass
{
    bool operator() (const Student &s1, const Student &s2)
    {
        return s1.getClassID() < s2.getClassID();
    }
};

void printStudents(Student &student)
{
    student.toString();
}

template<class Iterator>
Iterator Unique(Iterator first, Iterator last)
{
    while (first != last)
    {
        Iterator next(first);
        last = std::remove(++next, last, *first);
        first = next;
    }

    return last;
}

void Application::showMenu()
{
    cout << "Application started in directory: " << filePath << endl << endl;
    cout << "Press the key 't' to start the transformation" << endl << endl;

    char pressed = getch();
    if(pressed == 't')
    {
        if(Application::fillStudents())
        {
            int currentCounter = 0;
            int sortedByNameCounter = 0;
            int sortedByClassCounter = 0;

            cout << endl << "Loaded input from file(s): " << endl;
            for_each (students.begin(), students.end(), printStudents);
            currentCounter = students.size();
            cout << endl << "\tTotal Students (Not sorted): " << currentCounter << endl << endl;

            cout << "Sorted output" << endl;
            students.erase( Unique( students.begin(), students.end() ), students.end() );
            sort(students.begin(), students.end());
            for_each (students.begin(), students.end(), printStudents);
            sortedByNameCounter  = students.size();
            cout << endl << "\tTotal Students (Sorted by Name): " << sortedByNameCounter << endl << endl;

            stable_sort(students.begin(), students.end(), CompareByClass());
            for_each (students.begin(), students.end(), printStudents);
            sortedByClassCounter = students.size();
            cout << endl << "\tTotal Students (Sorted by Class): " << sortedByClassCounter << endl << endl;

            writeToFile();
            cout << "Transformed to file: formatted.xml" << endl;
        }
    }
}

bool Application::fillStudents()
{
    string filePathString = getFilePath();
    const char *filePath = filePathString.c_str();

    cout << "Starting to fill a vector with containers" << endl;
    struct dirent *ent;
    DIR *dir;
    if ((dir = opendir(filePath)) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            string fileName = ent->d_name;

            if(fileName.substr(fileName.find_last_of(".") + 1) == "txt")
            {
                const char *charPointer = fileName.c_str();

                std::string fileNameInString = std::string(charPointer);
                string fullPath = filePathString + "/" + fileNameInString;
                FileReader *reader = new FileReader(fullPath);

                vector<Student> tmp_students;
                tmp_students = reader->readFile();
                std::copy(tmp_students.begin(), tmp_students.end(),std::back_inserter(students));

                delete reader;
            }
        }
        closedir (dir);
        return true;
    }
    else
    {
        perror ("");
        return false;
    }
}

void Application::writeToFile()
{
    fstream outfile("formatted.xml");
    outfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    outfile << "<School>" << endl;
    for( std::vector<Student>::iterator i = students.begin(); i != students.end(); ++i){
        outfile << "\t <Student>" << endl;
        outfile << "\t\t<Name>" << i->getSurname() << "</Name>" << endl;
        outfile << "\t\t<Achternaam>" << i->getName() << "</Achternaam>" << endl;
        outfile << "\t\t<Plaats>" << i->getCity() << "</Plaats>" << endl;
        outfile << "\t\t<Geslacht>" << i->getGender() << "</Geslacht>" << endl;
        outfile << "\t\t<Klas>" << i->getClassID() << "</Klas>" << endl;
        outfile << "\t </Student>" << endl;
    }

    outfile << "</School>" << std::endl;
    outfile.close();
}


