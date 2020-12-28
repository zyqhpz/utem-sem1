#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Mark {
	int quiz1;
	int quiz2;
	int quiz3;
	double totalMarks;
};

struct Participant {
	string name;
	string matricNumber;
	Mark test;
};

Participant student[1000];

int numStudent();
int displayMenu();
void getName(int);
void displayNameWithMark(int);
void displayName(int);

int main() {

	int num = numStudent(), choice;

	const int n = num;

	getName(n);

	do {
		choice = displayMenu();

		if (choice == 0) {
			cout << "Program Terminated" << endl;
			break;
		}
		else if (choice == 1)
			displayName(n);
		else if (choice == 2)
			displayNameWithMark(n);
		else if (choice == 3)
			cout << "highest mark";
		else if (choice == 4)
			cout << "lowest";
		else if (choice == 5)
			cout << "highest lowest each quiz";
		else if (choice == 6)
			cout << "search";

		else
			cout << "invalid input";

		cout << endl;
	} while (choice > -1 || choice < 7);

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
		cout << "|\t\t\t\t" << left << setw(30) << "5 - Highest and Lowest each quiz" << right << setw(37) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "6 - Search with Specific Mark" << right << setw(39) << "|" << endl;
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

void displayNameWithMark(int size) {
	cout << endl << "\tName\tMatric Number\tFinal Mark" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << student[i].name << "\t" << student[i].matricNumber << "\t\t" << student[i].test.totalMarks << endl;
	}
}

void displayName(int size) {
	cout << endl << "\tName\tMatric Number" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << student[i].name << "\t" << student[i].matricNumber << endl;
	}
}

void getName(int n) {
	for (int i = 0; i < n; i++) {
		cin.ignore();
		student[i].test.totalMarks = 0;
		cout << endl << "Student name: ";
		getline(cin, student[i].name);
		cout << "Matric number: ";
		getline(cin, student[i].matricNumber);
		cout << "Enter Quiz 1 mark: ";
		cin >> student[i].test.quiz1;
		student[i].test.totalMarks += student[i].test.quiz1;
		cout << "Enter Quiz 2 mark: ";
		cin >> student[i].test.quiz2;
		student[i].test.totalMarks += student[i].test.quiz2;
		cout << "Enter Quiz 3 mark: ";
		cin >> student[i].test.quiz3;
		student[i].test.totalMarks += student[i].test.quiz3;

		//round of 2 decimal places

		cout << "Total Marks : " << student[i].test.totalMarks << endl;
	}
}