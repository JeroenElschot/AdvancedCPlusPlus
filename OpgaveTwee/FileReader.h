#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"

using namespace std;

class FileReader
{
    private:
        string filePath;
    public:
        FileReader(string f): filePath(f)
        {

        }

        ~FileReader();

        string getFilePath();
        vector<Student> readFile();

};

#endif // FILEREADER_H
