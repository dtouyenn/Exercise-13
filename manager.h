#pragma once
#ifndef MANAGE_H
#define MANAGE_H

#include "experience.h"
#include "fresher.h"
#include "intern.h"


class Manager
{
private:
    vector<Employee*> employeeList;
public:
    Manager();
    ~Manager();
    void addEmployee();
    void showListEmployee(const int&);
    void changeInfo(const string&);
    void deleteEmployee(const string&);
    Employee* findInfo(const string&);
    bool checkSameID();
    void addCertificate(const string&);
    void deleteCertificate(const string&);
    void showCertificate(const string&);
};

#endif // !MANAGE_H
