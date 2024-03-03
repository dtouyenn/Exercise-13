#include "experience.h"

int Experience::_experienceCount = 0;
Experience::Experience(){
    _experienceCount++;
}
void Experience::inputInfo()
{
    //cin.ignore();
    Employee::inputInfo();
    cout << " Enter experience in year: ";
    cin >> _expInYear;
    cin.ignore();
    cout << " Enter professional skill: ";
    getline(cin, _proSkill);
}

void Experience::showMe() {
    Employee::showInfo();
    std::cout << " - Experience in years: " << _expInYear << std::endl;
    std::cout << " - Professional skill: " << _proSkill << std::endl;
    cout << endl;
}
Experience::~Experience()
{
}