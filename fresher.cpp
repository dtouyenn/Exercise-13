#include "fresher.h"

int Fresher::_fresherCount = 0;
Fresher::Fresher(){
    _fresherCount++;
}

//Fresher::Fresher(string graDate, string graRank, string edu) {
//    this->_graduationDate = graDate;
//    this->_graduationRank = graRank;
//    this->_education = edu;
//}
//
//Fresher::Fresher(string ID, string fullname, string birthday, string phone, string email, const list<Certificate>& certificate, string graDate, string graRank, string edu)
//:Employee(ID, fullname, birthday, phone, email, certificate, 1), _graduationDate(graDate), _graduationRank(graRank), _education(edu)
//{
//    
//}


void Fresher::inputInfo()
{
    
    Employee::inputInfo();
    cout << " Enter graduation date: " ;
    getline(cin, _graduationDate);
    cout << " Enter graduation rank: " ;
    getline(cin, _graduationRank);
    cout << " Enter education: " ;
    getline(cin, _education);
}

void Fresher::showMe()
{
    Employee::showInfo();
    std::cout << " - Graduation date: " << _graduationDate << std::endl;
    std::cout << " - Graduation rank: " << _graduationRank << std::endl;
    std::cout << " - Education: " << _education << std::endl;
    cout << endl;
}

Fresher::~Fresher() {
}

