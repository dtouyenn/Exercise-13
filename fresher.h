#pragma once
#ifndef FRESHER_H
#define FRESHER_H

#include "base.h"
#include "employee.h"
/*
 Đối với nhân viênn Fresher có thêm thuộc tính: 
 Thời gian tốt nghiệp(Graduation_date), 
 Xếp loại tốt nghiệp (Graduation_rank) , 
 Trường tốt nghiệp (Education)
*/
class Fresher : public Employee {
private:
    string _graduationDate; 
    string _graduationRank;
    string _education;
public:
    Fresher();
    //Fresher(string graDate, string graRank, string edu);
    //Fresher(string ID, string fullname, string birthday, string phone, string email, const list<Certificate>& certificate, string graDate, string graRank, string edu);
    ~Fresher();
    static int _fresherCount;
    void inputInfo();
    void showMe();
};

#endif



