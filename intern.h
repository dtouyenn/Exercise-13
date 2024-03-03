#pragma once
#ifndef INTERN_H
#define INTERN_H

#include "base.h"
#include "employee.h"
/*
 Đối với nhân viên Intern có thêm thuộc tính: 
 Chuyên ngành đang học (Majors), 
 Học kì đang học (Semester), 
 Tên trường đang học (University_name)
*/
class Intern : public Employee {
private:
    string _major; 
    string _semester;
    string _uniName;
public:
    Intern();
    //Intern(string major, string semester, string uni);
    //Intern(string ID, string fullname, string birthday, string phone, string email, const list<Certificate>& certificate, string major, string semester, string uni);
    ~Intern();
    static int _internCount;
    void inputInfo();
    void showMe();
};

#endif 
