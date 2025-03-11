#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <cctype> //for isalpha function
#include <iomanip>
#include <sstream> //for string stream class

using namespace std;

class Employee {
private:
    //Private Functionalities
    fstream file;
    bool isExist(string f, string id);
    bool validateId(string id);
    bool validateAlphabetic(string n);
    bool validateSalaryAndBonus(string sal);
    void variableLength(string t[], string atr[], int maxLength[], int size);
    bool isEmpty(string s);
    
public:
    //Public Functionalities
    void addEmployee();
    void showSpecificEmployee(string id);
    void deleteEmployee(string id);
    
};
#endif

