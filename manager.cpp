#include "manager.h"

Manager::Manager() {}

Manager::~Manager() {
    if(!employeeList.empty()) {
        for(Employee* i : employeeList) {
            delete i;
        }
    }
}

void Manager::addEmployee()
{
    int type;
    
    cout << "\n Enter employee type [0-Experience, 1-Fresher, 2-Intern]: ";
    cin >> type;
    switch (type)
    {
    case EXPERIENCE: {
        Employee* exp = new Experience;     //up-casting
        exp->inputInfo();
        exp->setEmployeeType(EXPERIENCE);
        employeeList.push_back(exp);
        break;
    }
    case FRESHER: {
        Employee* fre = new Fresher;
        fre->inputInfo();
        fre->setEmployeeType(FRESHER);
        employeeList.push_back(fre);
        break;
    }
    case INTERN: {
        Employee* intern = new Intern;
        intern->inputInfo();
        intern->setEmployeeType(INTERN);
        employeeList.push_back(intern);
        break;
    }
    default:
        cout << " Incorrect value! Please enter 0, 1 or 2" << endl;
        break;
    }
    if (Manager::checkSameID()) {
        Employee* temp = employeeList[employeeList.size() - 1];
        employeeList.pop_back();
        delete(temp);
    }
    char temp;
    cout << " Do you want to continue adding employee? [y/n]: ";
    cin >> temp;

    if (temp == 'y') {
        Manager::addEmployee();
    }
}

void Manager::showListEmployee(const int& type)
{
    if (employeeList.empty()) {
        cout << " No employees in the list!" << endl;
        cout << " Do you want to add new employee? [y/n]: ";
        char temp;
        do
        {
            cin >> temp; cin.ignore();
            if (temp == 'y')
            {
                Manager::addEmployee();
            }
            else if (temp == 'n')
                return;
            else
                cout << " Incorrect value! Please re-enter!" << endl;
        } while ((temp != 1) && (temp != 0));
    }
    if (type == 0) { //show all 
        cout << " Total Employees: " << Employee::_employeeCount << endl;
        for (size_t i = 0; i < employeeList.size(); i++) {
            cout << " " << i + 1<< ". " << endl;
            if (employeeList[i]->getEmployeeType() == EXPERIENCE) {
                Experience* exp = dynamic_cast<Experience*>(employeeList[i]);
                //Employee* exp = (*Experience)employeeList[i];
                if (exp != nullptr) {
                    exp->showMe();
                }
            }

            if (employeeList[i]->getEmployeeType() == FRESHER) {
                Fresher* fre = dynamic_cast<Fresher*>(employeeList[i]);
                if (fre != nullptr) {
                    fre->showMe();
                }
            }

            if (employeeList[i]->getEmployeeType() == INTERN) {
                Intern* intern = dynamic_cast<Intern*>(employeeList[i]);
                if (intern != nullptr) {
                    intern->showMe();
                }
            }
        }
    }
    else if (type == 1) {
        cout << " Total Experiences: " << Experience::_experienceCount << endl;
        for (size_t i = 0; i < employeeList.size(); i++) {
            if (employeeList[i]->getEmployeeType() == EXPERIENCE)
            {
                cout << " " << i + 1 << ": " << endl;
                Experience* p = dynamic_cast<Experience*>(employeeList[i]);
                if (p != nullptr)
                {
                    p->showMe();
                }
            }
        }
        if (Experience::_experienceCount == 0) { cout << " No Experiences in the list!" << endl; }
    }

    else if (type == 2) {
        cout << " Total Freshers: " << Fresher::_fresherCount << endl;
        for (size_t i = 0; i < employeeList.size(); i++) {
            if (employeeList[i]->getEmployeeType() == FRESHER)
            {
                cout << " " << i + 1 << ": " << endl;
                Fresher* p = dynamic_cast<Fresher*>(employeeList[i]);
                if (p != nullptr)
                {
                    p->showMe();
                }
            }
        }
        if (Fresher::_fresherCount == 0) { cout << " No Freshers in the list!" << endl; }
    }

    else if (type == 3) {
        cout << " Total Interns: " << Intern::_internCount << endl;
        for (size_t i = 0; i < employeeList.size(); i++) {
            if (employeeList[i]->getEmployeeType() == INTERN) {
                cout << " " << i + 1 << ": " << endl;
                Intern* p = dynamic_cast<Intern*>(employeeList[i]);
                if (p != nullptr)
                {
                    p->showMe();
                }
            }
        }
        if (Intern::_internCount == 0) { cout << " No Interns in the list!" << endl; }
    }
}

void Manager::changeInfo(const string& ID) {
    for (auto i : employeeList) {
        if (ID == i->getID()) {
            i->inputInfo();
        }
        break;
    }
}

void Manager::deleteEmployee(const string& ID)
{
    if (employeeList.empty()) {
        cout << " No employees in the list!" << endl;
        cout << " Do you want to add new employee? [y/n]: ";
        char temp;
        do
        {
            cin >> temp; cin.ignore();
            if (temp == 'y')
            {
                Manager::addEmployee();
            }
            else if (temp == 'n')
                return;
            else
                cout << " Incorrect value! Please re-enter!" << endl;
        } while ((temp != 1) && (temp != 0));
    }

    for (size_t i = 0; i < employeeList.size(); i++) {
        if(employeeList[i]->getID() == ID) {
            employeeList[i]->showInfo();
            char temp;
            while (true) {
                cout << " Do you want to delete this employee? [y/n]: ";
				cin >> temp;
				if (temp == 'y') {
					employeeList.erase(employeeList.begin() + i);
                    Employee::_employeeCount--;
					cout << " Delete succesfully!!! " << endl;
					break;
				}
				else if (temp == 'n') {
					cout << " Delete fail!!! " << endl;
					break;
				}
				else {
					cout << " ERROR: wrong syntax!!! " << endl;
				}
            }
            return;
        }
        else cout << " Employee's ID does not exist!" << endl;
    }

}
Employee* Manager::findInfo(const string& ID)
{
    if (employeeList.empty()) {
        cout << " No employees in the list!" << endl;
        cout << " Do you want to add new employee? [y/n]: ";
        char temp;
        do
        {
            cin >> temp; cin.ignore();
            if (temp == 'y')
            {
                Manager::addEmployee();
            }
            else if (temp == 'n')
                break;
                //return nullptr;
            else
                cout << " Incorrect value! Please re-enter!" << endl;
        } while ((temp != 1) && (temp != 0));
    }

    for (auto i : employeeList) {
        if (i->getID() == ID) {
            i->showInfo();
            return i;
        }
        else cout << " Employee's ID does not exist!" << endl;
        return nullptr;
    }
    
}

bool Manager::checkSameID()
{
    try {
        if (employeeList.size() > 1)
        {
            for (size_t i = 0; i < employeeList.size() - 1; i++)
            {
                if (employeeList[i]->getID() == employeeList[employeeList.size() - 1]->getID())
                {
                    throw MyException(" ID already exists. Please re-enter!");
                }
            }
        }
    }
    catch (MyException& e)
    {
        cout << e.what() << endl;
        return true;
    }

    return false;
}

void Manager::addCertificate(const string& employeeID)
{
    Employee* emp = findInfo(employeeID);
    if (emp == nullptr) {
        cout << " Employee's ID does not exist!" << endl;
        return;
    }
    emp->showCert();
    emp->inputCert();
}


void Manager::deleteCertificate(const string& employeeID)
{
    Employee* emp = findInfo(employeeID);
    if (emp == nullptr) {
        cout << " Employee's ID does not exist!" << endl;
        return;
    }
    emp->showCert();
    char temp;
    while (true) {
        cout << " Do you want to delete this employee's certificate? [y/n]: ";
        cin >> temp;
        if (temp == 'y') {
            emp->deleteCert();
            cout << " Delete certificate succesfully!!! " << endl;
            break;
        }
        else if (temp == 'n') {
            cout << " Delete certificate fail!!! " << endl;
            break;
        }
        else {
            cout << " ERROR: wrong syntax!!! " << endl;
        }
    }
    return;
}

void Manager::showCertificate(const string& employeeID)
{
    Employee* emp = findInfo(employeeID);
    if (emp == nullptr) {
        cout << " Employee's ID does not exist!" << endl;
        return;
    }
    emp->showCert();
}
