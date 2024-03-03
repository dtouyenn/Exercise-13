#pragma once

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef enum
{
	EXPERIENCE = 0,
	FRESHER,
	INTERN
}t_EmployeeType;

class MyException
{
    string _msg;
public:
    MyException(string msg)
    {
        _msg = msg;
    }
    string what()
    {
        return _msg;
    }
};

#endif // !BASE_H
