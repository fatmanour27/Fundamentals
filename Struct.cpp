#include <iostream>
using namespace std;

struct Student
{
    char name[40];
    int age;
    float anatomy;
    float histology;
    float physiology;
};

//Add student(1)
void Add_new_student(int location, Student* ptr)
{
    cout << "Enter the name of student: ";
    cin >> ptr[location].name;

    cout << "Enter the age of student: ";
    cin >> ptr[location].age;

    cout << "Enter degree of (Anatomy): ";
    cin >> ptr[location].anatomy;

    cout << "Enter degree of (Histology): ";
    cin >> ptr[location].histology;

    cout << "Enter degree of (Physiology): ";
    cin >> ptr[location].physiology;
}
//List all students(2)
void List_student(int total, Student* ptr)
{
    for (int i = 0; i < total; i++)
    {
        cout << "The name of student:" << ptr[i].name << endl;
        cout << "The age of student:" << ptr[i].age << endl;
        cout << "The degree of Anatomy: " << ptr[i].anatomy << endl;
        cout << "The degree of histology: " << ptr[i].histology << endl;
        cout << "The degree of physiology: " << ptr[i].physiology << endl;
    }
}
//Calculate percentage for each student(3)
void Calc_percent(int total, Student* ptr)
{
    int mark = 100;

    for (int i = 0; i < total; i++)
    {
        float percentA = (ptr[i].anatomy / mark) * 100;
        float percentPy = (ptr[i].physiology / mark) * 100;
        float percentH = (ptr[i].histology / mark) * 100;

        cout << "Percentage of Anatomy: " << percentA << "%" << endl;
        cout << "Percentage of Histology: " << percentH << "%" << endl;
        cout << "percentage of Physiology: " << percentPy << "%" << endl;
    }
}
//Get student with height percentage(4)
//logic: compare the percentage of first student as the highest percentage with another students 
void Highest_percent(int total, Student* ptr)
{
    int student_index = 0;
    float highest_percentage = (ptr[0].anatomy + ptr[0].histology + ptr[0].physiology) / 3.0;

    for (int i = 1; i < total; i++)
    {
        float percentage = (ptr[i].anatomy + ptr[i].histology + ptr[i].physiology) / 3.0;

        if (percentage > highest_percentage)
        {
            highest_percentage = percentage;
            student_index = i;
        }
    }
    cout << "The name of student with highest percentage: " << ptr[student_index].name << endl;
    cout << "Percentage of this student= " << highest_percentage << " %" << endl;
}
//Calculate average percentage for each student(5)
void Calc_average(int total, Student* ptr)
{
    for (int i = 0; i < total; i++)
    {

        float percentage = (ptr[i].anatomy + ptr[i].histology + ptr[i].physiology) / 3.0;

        cout << "  Name: " << ptr[i].name << endl;
        cout << "  Percentage: " << percentage << "%" << endl;
    }

}
//Get passed or failure students in specific subject or all subjects
void Passed(int total, Student* ptr)
{

    for (int i = 0; i < total; i++)
    {
        bool passAnatomy = ptr[i].anatomy >= 50;
        bool passHistology = ptr[i].histology >= 50;
        bool passPhysio = ptr[i].physiology >= 50;

        cout << "Name of student: " << ptr[i].name << endl;

        if (passAnatomy && passHistology && passPhysio)
        {
            cout << "Student passed in all subjects" << endl;
        }
        else
        {
            if (!passAnatomy)
            {
                cout << "Failed in Anatomy" << endl;
            }
            if (!passPhysio)
            {
                cout << "Failed in Physiology" << endl;
            }
            if (!passHistology)
            {
                cout << "Failed in Histology" << endl;
            }
            else if (!passAnatomy && !passPhysio && !passHistology)
            {
                cout << "Failed in all subjects" << endl;
            }
        }
    }
}
//count students passed
void Count(int total, Student* ptr)
{
    int pass = 0;
    int fail = 0;

    for (int i = 0; i < total; i++)
    {
        float average = (ptr[i].anatomy + ptr[i].physiology + ptr[i].histology) / 3.0;

        if (average >= 50)
        {
            pass++;
        }
        else
        {
            fail++;
        }
    }
    cout << "Passed students: " << pass << endl;
    cout << "Failures: " << fail << endl;

}
//List passed students
void list_passed_students(int total, Student* ptr)
{

    for (int i = 0; i < total; i++)
    {
        bool percentage = (ptr[i].anatomy + ptr[i].histology + ptr[i].physiology) / 3.0 >= 50;

        if (percentage)
        {
            cout << "Student:" << ptr[i].name << " passed" << endl;
        }
        else
        {
            cout << "Student: " << ptr[i].name << " failed" << endl;
        }
    }

}

int main()
{
    int total;
    cout << "Enter total number of students: ";
    cin >> total;

    Student* ptr = new Student[total];

    int choice = -1;
    int Additional_student = 0;
    int percentage;

    while (choice != 0)
    {
        cout << "Enter 1 to add new student" << endl;
        cout << "Enter 2 to list all students" << endl;
        cout << "Enter 3 to print percentage of each student" << endl;
        cout << "Enter 4 to get students with highest percentage" << endl;
        cout << "Enter 5 to get the average of percentage" << endl;
        cout << "Enter 6 to get passed or failure students in specific subject or all subjects" << endl;
        cout << "Enter 7 to know how many passed students" << endl;
        cout << "Enter 8 to get the name of passed and failed student" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice; //to avoid infinite loop.

        switch (choice)
        {
        case 1:
            if (Additional_student == total)
            {
                cout << "The list is full!" << endl;
            }
            else
            {
                Add_new_student(Additional_student, ptr);
                Additional_student++;
            }
            break;

        case 2:
            List_student(Additional_student, ptr);
            break;

        case 3:
            Calc_percent(Additional_student, ptr);
            break;

        case 4:
            Highest_percent(Additional_student, ptr);
            break;

        case 5:
            Calc_average(Additional_student, ptr);
            break;
        case 6:
            Passed(Additional_student, ptr);
            break;
        case 7:
            Count(Additional_student, ptr);
            {

            }
        case 8:
            list_passed_students(Additional_student, ptr);

        case 0:
            cout << "Exiting" << endl;
            break;
        }
    }

    delete[] ptr;

    return 0;
}
