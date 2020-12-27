#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int numStudent();
int displayMenu();
void nameList(string &matricN, double &q1, double &q2, double &q3, double &total);
void displayNameWithMark(string[], string[], double[], int);
void displayName(string[], string[], int);

int main() {

	int n = numStudent(),choice;

	string *matricNumber = new string[n];
	string *studentName = new string[n];
	double *quiz1 = new double[n];
	double *quiz2 = new double[n];
	double *quiz3 = new double[n];
	double *totalMarks = new double[n];

	for (int i = 0; i < n; i++) {
		cin.ignore();
		cout << endl << "Student name: ";
		getline(cin, studentName[i]);
		cout << "Matric number: ";
		getline(cin, matricNumber[i]);
		cout << "Enter Quiz 1 mark: ";
		cin >> quiz1[i];
		cout << "Enter Quiz 2 mark: ";
		cin >> quiz2[i];
		cout << "Enter Quiz 3 mark: ";
		cin >> quiz3[i];

		totalMarks[i] = (quiz1[i] + quiz2[i] + quiz3[i]) / 3;
		//round of 2 decimal places
		totalMarks[i] = ceil(totalMarks[i] * 100.0) / 100.0;

		cout << "Total Marks : " << totalMarks[i] << endl;
	}

	do {
		choice = displayMenu();

		if (choice == 0) {
			cout << "Program Terminated" << endl;
			break;
		}
		else if (choice == 1)
			displayName(studentName, matricNumber, n);
		else if (choice == 2)
			displayNameWithMark(studentName, matricNumber, totalMarks, n);
		else if (choice == 3)
			cout << "highest mark";
		else if (choice == 4)
			cout << "lowest";
		else if (choice == 5)
			cout << "search";
		else
			cout << "invalid input";

		cout << endl;
	} while (choice > -1 || choice < 6);
	return 0;
}

int displayMenu() {
	int choice;
		cout << "=====================================================================================================" << endl;
		cout << "|" << setw(100) << "|" << endl;
		cout << "|" << setw(100) << "|" << endl;
		cout << "|" << setw(73) << "******* STUDENTS' MARKS RECORD SYSTEM *******" << setw(27) << "|" << endl;
		cout << "|" << setw(100) << "|" << endl;
		cout << "|" << setw(100) << "|" << endl;
		cout << "=====================================================================================================" << endl;
		cout << "|" << setw(55) << "MAIN MENU" << setw(45) << "|" << endl;
		cout << "=====================================================================================================" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "1 - Namelist" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "2 - Final Mark" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "3 - Highest Mark" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "4 - Lowest Mark" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "5 - Search with Specific Mark" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "0 - Exit" << right << setw(39) << "|" << endl;
		cout << "|" << setw(100) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "Please enter 0/1/2/3/4/5 to choose." << right << setw(34) << "|" << endl;
		cout << "=====================================================================================================" << endl << endl;

		cout << "What do you want to display? : ";
		cin >> choice;

		return choice;
}

int numStudent() {
	int n;
	cout << "Enter total number of student that want to be entered: ";
	cin >> n;
	return n;
}

void displayNameWithMark(string nList[], string mList[], double fMarks[], int size) {
	cout << endl << "\tName\tMatric Number\tFinal Mark" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << nList[i] << "\t" << mList[i] << "\t\t" << fMarks[i] << endl;
	}

}

void displayName(string nList[], string mList[], int size) {
	cout << endl << "\tName\tMatric Number" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << nList[i] << "\t" << mList[i] << endl;
	}
}