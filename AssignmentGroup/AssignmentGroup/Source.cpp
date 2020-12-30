#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iterator>
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
	int rank;
};

struct Participant {
	string name;
	string icNumber;
	Subject mark;
	double averageMark;
};

Participant student[1000];

struct Subject3 {
	double totalMarkLH;
	int rank3;
};

struct Participant3 {
	string nameLH;
	string icNumLH;
	Subject3 mark3;
	double avgLH;
};

Participant3 student3[1000];

int numStudent();
int displayMenu();
void getName(string[], int);
void displayName(int);
Participant calculateAverageMark(int);
void displayTotalMark(int);
void displayHtoL(int);
void displayLtoH(int);
void reverseRanks(int);
bool compareLowHigh(Participant3, Participant3);


// main by Fatin
int main() {

	string subject[8] = { "Bahasa Melayu", "English", "History", "Mathematics", "Additional Mathematics", "Biology", "Chemistry", "Physics" };
	string f5Class[4] = { "5 Alchemilla", "5 Begonia", "5 Calendula", "5 Dahlia" };

	int num = numStudent(), choice;

	const int n = num;

	getName(subject, n);

	Participant average;
	average = calculateAverageMark(n);

	do {
		choice = displayMenu();

		if (choice == 0) {
			cout << "Program Terminated" << endl;
			break;
		}
		else if (choice == 1)
			displayName(n);
		else if (choice == 2)
			displayTotalMark(n);
		else if (choice == 3)
			displayHtoL(n);
		else if (choice == 4) 
			displayLtoH(n);
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

// get number of student in class by Haziq
int numStudent() {
	int n;
	cout << "Enter total number of student that want to be entered: ";
	cin >> n;
	return n;
}

// get input function by Haziq
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
			cin >> student[i].mark.subject[j];
		}
	}
}

// display menu function by KaK Lok
int displayMenu() {
	int choice;
	cout << endl;
	cout << "=====================================================================================================" << endl;
	cout << "|                                           MAIN MENU                                               |" << endl;
	cout << "=====================================================================================================" << endl;
	cout << "|\t\t\t" << left << setw(40) << "1 - Namelist" << right << setw(37) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "2 - Total and Average mark" << right << setw(37) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "3 - Highest Mark to Lowest Mark" << right << setw(37) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "4 - Lowest Mark to Highest Mark" << right << setw(37) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "5 - Highest and Lowest each subject" << right << setw(37) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "6 - Search highest and lowest mark for specific subject" << right << setw(22) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "0 - Exit" << right << setw(37) << "|" << endl;
	cout << "|" << setw(100) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(30) << "Please enter 0/1/2/3/4/5/6 to choose." << right << setw(32) << "|" << endl;
	cout << "=====================================================================================================" << endl << endl;

	cout << "What do you want to display? : ";
	cin >> choice;
	return choice;
}

// display namelist by Kak Lok
void displayName(int size) {
	cout << endl << "\tName\tIC Number" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << student[i].name << "\t" << student[i].icNumber << endl;
	}
}

// calculate average by Kak Lok
Participant calculateAverageMark(int n) {
	Participant average;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 8; j++) 
			student[i].mark.totalMark += student[i].mark.subject[j];
		student[i].averageMark = student[i].mark.totalMark / 8;
	}
	return average;
}

// display namelist with mark by Kak Lok
void displayTotalMark(int n) {
	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "TOTAL AND AVERAGE MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================" << endl;

	cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ".\t" << left << setw(25) << student[i].name << "\t" << student[i].icNumber << "\t\t"
			<< static_cast<int>(student[i].mark.totalMark) << "\t\t" << fixed << setprecision(1) << student[i].averageMark << endl;
	}
	cout << endl;
}

// modify data highest to lowest by Kak Lok
void displayHtoL(int n) {
	struct ParticipantHtoL {
		string name2;
		string icNumber2;
		double averageMark2;
		double totalMark2;
	};
	ParticipantHtoL student2[1000];

	for (int i = 0; i < n; i++)
	{
		student2[i].name2 = student[i].name;
		student2[i].icNumber2 = student[i].icNumber;
		student2[i].averageMark2 = student[i].averageMark;
		student2[i].totalMark2 = student[i].mark.totalMark;
	}

	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "HIGHEST MARK TO LOWEST MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================" << endl;
	double tempAvg, tempTotal;
	string tempName, tempIC;
	cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (student2[i].averageMark2 > student2[j].averageMark2)
			{
				tempAvg = student2[i].averageMark2;
				student2[i].averageMark2 = student2[j].averageMark2;
				student2[j].averageMark2 = tempAvg;

				tempName = student2[i].name2;
				student2[i].name2 = student2[j].name2;
				student2[j].name2 = tempName;

				tempIC = student2[i].icNumber2;
				student2[i].icNumber2 = student2[j].icNumber2;
				student2[j].icNumber2 = tempIC;
				
				tempTotal = student2[i].totalMark2;
				student2[i].totalMark2 = student2[j].totalMark2;
				student2[j].totalMark2 = tempTotal;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << i + 1 << ".\t" << left << setw(25) << student2[i].name2 << "\t" << student2[i].icNumber2
		<< "\t\t" << fixed << student2[i].totalMark2
		<< "\t\t" << fixed << setprecision(1) << student2[i].averageMark2 << endl;
	cout << endl;
}

// function to modify data lowest to highest by Haziq
bool compareLowHigh(Participant3 a, Participant3 b) {
	if (a.mark3.totalMarkLH != b.mark3.totalMarkLH)
		return a.mark3.totalMarkLH < b.mark3.totalMarkLH;
	else
		return 0;
}

// function to modify data lowest to highest by Haziq
void reverseRanks(int n) {
	sort(student3, student3 + n, compareLowHigh);
	for (int i = 0; i < n; i++)
		student3[i].mark3.rank3 = i - 1;
}

// modify data lowest to highest by Haziq
void displayLtoH(int n) {

	for (int i = 0; i < n; i++) {
		student3[i].nameLH = student[i].name;
		student3[i].icNumLH = student[i].icNumber;
		student3[i].avgLH = student[i].averageMark;
		student3[i].mark3.totalMarkLH = student[i].mark.totalMark;
	}

	reverseRanks(n);

	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "LOWEST MARK TO HIGHEST MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================" << endl;

	cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;

	for (int i = 0; i < n; i++)
		cout << i + 1 << ".\t" << left << setw(25) << student3[i].nameLH << "\t" << student3[i].icNumLH << "\t\t" << fixed << setprecision(1) << student3[i].mark3.totalMarkLH << "\t\t" << fixed << setprecision(1) << student3[i].avgLH << endl;
	cout << endl;
}
