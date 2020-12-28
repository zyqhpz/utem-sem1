#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Subject {
	int subject[8];
	/*
	int bahasa;
	int english;
	int history;
	int math;
	int addMath;
	int biology;
	int chemistry;
	int physics;
	*/
	double totalMark;
	double averageMark;
};

struct Participant {
	string name;
	string icNumber;
	Subject mark;
};

Participant student[1000];

int numStudent();
int displayMenu();
void getName(string[], int);
void displayNameWithMark(int);
void displayName(int);

int main() {

	string subject[8] = { "Bahasa Melayu", "English", "History", "Mathematics", "Additional Mathematics", "Biology", "Chemistry", "Physics" };
	string f5Class[4] = { "5 Alchemilla", "5 Begonia", "5 Calendula", "5 Dahlia" };

	int num = numStudent(), choice;

	const int n = num;

	getName(subject, n);

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
			cout << "highest to lowest";
		else if (choice == 4)
			cout << "lowest to highest";
		else if (choice == 5)
			cout << "highest lowest each subject";
		else if (choice == 6)
			cout << "search specific subject and display highest and lowest";
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
		cout << "|\t\t\t\t" << left << setw(30) << "2 - Namelist with total and average mark" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "3 - Namelist from Highest to Lowest" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "4 - Namelist from Lowest to Highest" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "5 - Highest and Lowest each subject" << right << setw(37) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "6 - Search highest and lowest mark for specific subject" << right << setw(39) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "0 - Exit" << right << setw(39) << "|" << endl;
		cout << "|" << setw(100) << "|" << endl;
		cout << "|\t\t\t\t" << left << setw(30) << "Please enter 0/1/2/3/4/5/6 to choose." << right << setw(34) << "|" << endl;
		cout << "======================================================================================================" << endl << endl;

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
	cout << endl << "\tName\tIC Number\tTotal Mark" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << student[i].name << "\t" << student[i].icNumber << "\t\t" << student[i].mark.totalMark << endl;
	}
}

void displayName(int size) {
	cout << endl << "\tName\tIC Number" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << student[i].name << "\t" << student[i].icNumber << endl;
	}
}

void getName(string subject[], int n) {
	for (int i = 0; i < n; i++) {
		cin.ignore();
		student[i].mark.totalMark = 0;
		cout << endl << "Enter student name: ";
		getline(cin, student[i].name);
		cout << "Enter student's IC number: ";
		getline(cin, student[i].icNumber);
		for (int j = 0; j < 8; j++) {
			cout << "Enter mark for " << subject[j] << ": ";
			cin >> student[i].mark.subject[i];
		}
	}
}