#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "base.h"
#include "certificate.h"

class Employee {
private:
    string _ID;
    string _fullName;
    string _birthDay;
    string _phone;
    string _email;
    t_EmployeeType _employeeType;
    vector<Certificate> _listCert;

public:
    Employee() ;
    //Employee(string ID, string fullname, string birthday, string phone, string email, const list<Certificate>& certificate, int employeeType);
    
    void setID(const string&);
    void setName(const string&);
    void setBirthDay(const string&);
    void setPhone(const string&);
    void setEmail(const string&);
    void setEmployeeType(const t_EmployeeType&);
    string getID();
    string getName();
    string getBirthDay();
    string getPhone();
    string getEmail();
    t_EmployeeType getEmployeeType();

    void inputCert();
    void deleteCert();
    void showCert();

    bool checkName(string name);
    bool checkDate(string date);
    bool checkPhone(string phone);
    bool checkMail(string mail, string mailTail = "@fpt.com");

    static int _employeeCount;
    
    virtual void inputInfo();
    void showInfo(); // abstract method
    ~Employee();
};

#endif // EMPLOYEE_H

