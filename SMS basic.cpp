#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;
    string studentClass;
};

class School
{
public:
    Student students[100];
    int totalStudents = 0;

    
    void addStudent()
    {
        cout << "Enter student name: ";
        cin >> students[totalStudents].name;

        cout << "Enter student age: ";
        cin >> students[totalStudents].age;

        cout << "Enter student class: ";
        cin >> students[totalStudents].studentClass;

        totalStudents++;

        cout << "Student added successfully!";
    }

  
    void viewStudents()
    {
        if (totalStudents == 0)
        {
            cout << "No students found.";
        }
        else
        {
            cout << " STUDENTS ";

            for (int i = 0; i < totalStudents; i++)
            {
                cout << "Student " << i + 1 << endl;
                cout << "Name: " << students[i].name << endl;
                cout << "Age: " << students[i].age << endl;
                cout << "Class: " << students[i].studentClass << endl;
                cout << "-------------------";
            }
        }
    }

   
    void deleteStudent()
    {
        string name;

        cout << "Enter student name to delete: ";
        cin >> name;

        for (int i = 0; i < totalStudents; i++)
        {
            if (students[i].name == name)
            {
                
                for (int j = i; j < totalStudents - 1; j++)
                {
                    students[j] = students[j + 1];
                }

                totalStudents--;

                cout << "Student deleted successfully!\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }
};

int main()
{
 
    School school;

    int choice;

    do
    {
        cout << " SCHOOL MANAGEMENT SYSTEM ";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. View Students\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            school.addStudent();
        }
        else if (choice == 2)
        {
            school.deleteStudent();
        }
        else if (choice == 3)
        {
            school.viewStudents();
        }
        else if (choice == 4)
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
