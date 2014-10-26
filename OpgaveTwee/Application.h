#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class Application
{
    private:
        const string filePath;
        vector<Student> students;
    public:
        Application(const string fp) : filePath(fp){}
        ~Application();

        const string getFilePath() const
        {
            return filePath;
        }

        vector<Student> getStudents()
		{
			return students;
		}

        void showMenu();
        bool fillStudents();
        void removeDuplicates();
        void eachStudent (Student student);
        void exportXML();

        void addStudent(Student student)
        {
            students.push_back(student);
        }
};

#endif // APPLICATION_H
