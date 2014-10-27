#include "FileReader.h"
#include "Student.h"
#include <sstream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

FileReader::~FileReader()
{
    //dtor
}

string FileReader::getFilePath()
{
    return filePath;
}

vector<Student> FileReader::readFile()
{
    string currentFilePath = getFilePath();
    const char *filePath = currentFilePath.c_str();

    cout << "Reading file " << filePath << endl;

    ifstream file (filePath);
    string value;

    vector<Student> students;

    while ( file.good() ) // while the file is readable
    {
        std::string line;
        while(std::getline(file, line))
        {
            istringstream s(line);

            vector<string> words; // create a vector for the words
            while (getline(s, line,','))
            {
                words.push_back(line); // adds the line to words
            }
            string name = words[0];
            string surname = words[1];
            string city = words[2];
            string gender = words[3];
            string classID = words[4];

            if(name != "" && surname != "" && city != "" && gender != "" && classID != "")
            {
                Student student = Student(name,surname,city,gender,classID); // create the student object and fill it with the data
                students.push_back(student); // add the students
            }
            students.erase( unique( students.begin(), students.end() ), students.end() );
        }
    }
    cout << "Reading finished" << endl;
    return students;
}
