#include "intern.h"

int Intern::_internCount = 0;
Intern::Intern() {
	_internCount++;
}
Intern::~Intern() {
}

void Intern::inputInfo()
{
	Employee::inputInfo();
	cout << " Enter major:";
	getline(cin, _major);
	cout << " Enter semester: ";
	getline(cin, _semester);
	cout << " Enter university: ";
	getline(cin, _uniName);
}

void Intern::showMe()
{
	Employee::showInfo();
	std::cout << " - Major: " << _major << std::endl;
	std::cout << " - Semester: " << _semester << std::endl;
	std::cout << " - University: " << _uniName << std::endl;
	cout << endl;
}
