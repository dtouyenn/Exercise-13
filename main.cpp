#include "manager.h"

int main() {
	Manager m;

	while (true)
	{
		cout << endl;
		cout << "=============================================================================" << endl;
		cout << "                              Human Resources Manager                       " << endl;
		cout << "=============================================================================" << endl;
		cout << " Enter 1 to add new employee." << endl;
		cout << " Enter 2 to delete employee." << endl;
		cout << " Enter 3 to find employee." << endl;
		cout << " Enter 4 to show employee list." << endl;
		cout << " Enter 5 to add employee's certificate." << endl;
		cout << " Enter 6 to delete employee's certificate." << endl;
		cout << " Enter 7 to show employee's certificate."<< endl;
		cout << " Enter 0 to exit. " << endl;
		cout << "=============================================================================" << endl;
		int option;
		cout << "\n -> Enter option [0-6]: " ;
		cin >> option;
		cin.ignore();
		cout << endl;

		switch (option)
		{
		case 0:
			cout << "\n Do you want to exit the program [y/n]: ";
			
			char temp;
			cin >> temp;
			if (temp == 'y') return 0;
			else continue;
		case 1: {
			m.addEmployee();
			break;
		}
		case 2: {
			string temp;
			cout << " Enter employee's ID: ";
			getline(cin, temp);
			m.deleteEmployee(temp);
			break;
		}
		case 3: {
			string temp;
			cout << " Enter employee's ID: ";
			getline(cin, temp);
			m.findInfo(temp);
			break;
		}
		case 4: {
			int temp;
			cout << " Enter type [1 - Experience, 2 - Fresher, 3 - Intern, 0 - ALL]: ";
			cin >> temp;
			m.showListEmployee(temp);
			break;
		}
		case 5: {
			string temp;
			cout << " Enter employee's ID: ";
			getline(cin, temp);
			m.addCertificate(temp);
			break;
		}
		case 6: {
			string temp;
			cout << " Enter employee's ID: ";
			getline(cin, temp);
			m.deleteCertificate(temp);
			break;
		}
		case 7: {
			string temp;
			cout << " Enter employee's ID: ";
			getline(cin, temp);
			m.showCertificate(temp);
			break;
		}
		default:
			cout << " Invalid value. Please enter a number from 0 to 6." << endl;
			break;
		}
	}
	
	return 0;
}

