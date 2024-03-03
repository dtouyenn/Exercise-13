#include "employee.h"
#include <list>

int Employee::_employeeCount = 0;

Employee::Employee() {
}

void Employee::setID(const string& ID)
{
    this->_ID = ID;
}

void Employee::setName(const string& fullname)
{
    this->_fullName = fullname;
}

void Employee::setBirthDay(const string& birthday)
{
    this->_birthDay = birthday;
}

void Employee::setPhone(const string& phone)
{
    this->_phone = phone;
}

void Employee::setEmail(const string& email)
{
    this->_email = email;
}

void Employee::setEmployeeType(const t_EmployeeType& employee_type)
{
    _employeeType = employee_type;
}
std::string Employee::getID()
{
    return _ID;
}
std::string Employee::getName()
{
    return _fullName;
}

std::string Employee::getBirthDay()
{
    return _birthDay;
}

std::string Employee::getPhone()
{
    return _phone;
}

std::string Employee::getEmail()
{
    return _email;
}

t_EmployeeType Employee::getEmployeeType()
{
    return _employeeType;
}

void Employee::inputCert()
{
    Certificate cert;
    cert.inputCert();
    _listCert.push_back(cert);

    //char temp;
    //cout << " Do you want to continue adding this employee's certificate? [y/n]: ";
    //cin >> temp;

    //if (temp == 'y') {
    //    Employee::inputCert();
    //}
}

void Employee::deleteCert()
{
    string tempIDCert;
    cout << " Which certificate do you want to delete? " << endl;
    cout << " Enter ID certificate: ";
    cin >> tempIDCert;

    for (size_t i = 0; i < _listCert.size(); i++) {
        if (_listCert[i].getCertificateID() == tempIDCert) {
            _listCert.erase(_listCert.begin() + i);
        }
    }
}

void Employee::showCert()
{
    if (_listCert.empty()) {
        cout << " No certificates in the list!" << endl;
        return;
    }
    for (size_t i = 0; i < _listCert.size(); i++) {
        cout << " " << i + 1 << ". " << endl;
        _listCert[i].showCert();
    }
}

bool Employee::checkName(string fullName)
{
    // check syntax for fullname
    try {
        stringstream ss(fullName); //tách từng từ trong full name
        string word;
        while (ss >> word)
        {
            for (char c : word) {
                if (!isalpha(c)) {
                    throw MyException(" Invalid name!");
                }
            }
        }
    }
    catch (MyException& ex1) {
        cout << ex1.what() << endl;
        return false;
    }
    return true;
}

bool Employee::checkDate(string date)
{
    try {
        stringstream ss(date);
        string word;
        
        while (ss >> word) 
        {
            if(word.length() != 10) {
                throw MyException(" Invalid date! - dd/mm/yyyy");
            }
            if(word[2] != '/' || word[5] != '/') {
                throw MyException(" Invalid date! - dd/mm/yyyy");
            }
            for (char c : word) {
                if(c != '/') {
                    if(!isdigit(c)) {
                        throw MyException(" Invalid date! - dd/mm/yyyy");
                    }
                }
            }
        }
        stringstream ss1;
        int day, month, year;
        ss1 << date.substr(0, 2);
        ss1 >> day; ss1.clear();
        ss1 << date.substr(3, 2);
        ss1 >> month; ss1.clear();
        ss1 << date.substr(6, 4);
        ss1 >> year; ss1.clear();
        if ((day < 1) || (day > 31) || (month < 1) || (month > 12)) {
            throw MyException("Incorrect date! Form: dd/mm/yy");
        }
    }
    catch (MyException& ex2) {
        cout << ex2.what() << endl;
        return false;
    }
    return true;
}

bool Employee::checkPhone(string phone)
{
    try {
        stringstream ss(phone);
        string word;
        while (ss >> word)
        { 
            if(word[0] != '0') {
                throw MyException("Invalid phone number!");
            }
            if (word.length() != 10) {
                throw MyException("Invalid phone number!");
            }
            for (char c : word) {
                if (!isdigit(c)) {
                    throw MyException("Invalid phone number!");
                }
            }
        }
    }
    catch (MyException& ex3) {
        cout << ex3.what() << endl;
        return false;
    }
    return true;
}

bool Employee::checkMail(string mail, string mailTail)
{
    try {
        stringstream ss(mail);
        string token;
        string temp = "";
        if (mailTail.length() == 0) {
            return false;
        }
        while (ss >> token)
        {
            if (token.length() < mailTail.length() + 1) {
                throw MyException("Invalid email! Mail form: \"...\" + " + mailTail);
            }
            for (size_t i = token.length() - mailTail.length(); i < token.length(); i++) {
                temp += token[i];
            }
        }
        if (temp != mailTail) {
            throw MyException("Invalid email! Mail form: \"...\" + " + mailTail);
        }
    }
    catch (MyException& ex4) {
        cout << ex4.what() << endl;
        return false;
    }
    return true;
}

void Employee::inputInfo() {
    string tmpName, tmpDate, tmpPhone, tmpMail;
    cout << " Enter ID: "; 
    cin >> this->_ID;
    cin.ignore();

     do {
         cout << " Enter full name: ";
         getline(cin, tmpName);
         if (tmpName == "0") break;
     } while (!checkName(tmpName));
     setName(tmpName);

    do {
        cout << " Enter date of birth (dd/mm/yyyy): ";
        getline(cin, tmpDate);
    } while (!checkDate(tmpDate));
    setBirthDay(tmpDate);

    do {
        cout << " Enter phone: ";
        getline(cin, tmpPhone);
    } while (!checkPhone(tmpPhone));
    setPhone(tmpPhone);

    do {
        cout << " Enter email (...@fpt.com): ";
        getline(cin, tmpMail);
    } while (!checkMail(tmpMail));
    setEmail(tmpMail);
}

void Employee::showInfo()
{
    //cout << " -------------------------------- " << endl;
    //cout << " Employee Information: " << std::endl;
    //cout << " -------------------------------- " << endl;
    cout << " - ID: " << getID() << endl;
    cout << " - Full Name: " << _fullName << endl;
    cout << " - Birth day: " << _birthDay << endl;
    cout << " - Phone: " << _phone << endl;
    cout << " - Email: " << _email << endl;
    cout << " - Employee Type [0-Experience, 1-Fresher, 2-Intern]: " << getEmployeeType() << endl;
    
}


Employee::~Employee() {
}
