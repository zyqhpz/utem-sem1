#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iterator>
using namespace std;

struct Subject {
	int subject[8];
	int bahasa;
	int english;
	int history;
	int math;
	int addMath;
	int biology;
	int chemistry;
	int physics;
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
	int subject3[8];
	double totalMarkLH;
	int bahasa3;
	int english3;
	int history3;
	int math3;
	int addMath3;
	int biology3;
	int chemistry3;
	int physics3;
	int rank3;
};

struct Participant3 {
	string name3;
	string icNum3;
	Subject3 mark3;
	double avg3;
};

Participant3 student3[1000];

int numStudent();
int displayMenu();
void getName(int);
void displayName(int);
Participant calculateAverageMark(int);
void displayTotalMark(int);
void displayHtoL(int);
void displayLtoH(int);
void reverseRanks(int);
bool compareLowHigh(Participant3, Participant3);
void resetValue(int);
int selectSubject(string[]);

bool compareBahasa(Participant3, Participant3);
bool compareEnglish(Participant3, Participant3);
bool compareHistory(Participant3, Participant3);
bool compareMath(Participant3, Participant3);
bool compareAddMath(Participant3, Participant3);
bool compareBio(Participant3, Participant3);
bool compareChem(Participant3, Participant3);
bool comparePhy(Participant3, Participant3);

void displayNameWithSubject(int , string[], int);
void compareSubjectMark(int, int);

// main by Fatin
int main() {

	string subject[8] = { "Bahasa Melayu", "English", "History", "Mathematics", "Additional Mathematics", "Biology", "Chemistry", "Physics" };
	string f5Class[4] = { "5 Alchemilla", "5 Begonia", "5 Calendula", "5 Dahlia" };

	// BM - 0
	// English - 1
	// History - 2
	// Math - 3
	// AddMath - 4
	// Bio - 5
	// Chem - 6
	// Physics - 7

	int num = numStudent(), choice, select;

	const int n = num;

	getName(n);

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
		else if (choice == 5) {
			select = selectSubject(subject);
			displayNameWithSubject(select, subject, n);
		}
		else if (choice == 6)
			cout << "Program is not ready yet";
		else
			cout << "Invalid choice";

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
void getName(int n) {
	for (int i = 0; i < n; i++) {
		cin.ignore();
		student[i].mark.totalMark = 0;
		cout << endl << "Enter student name: ";
		getline(cin, student[i].name);
		cout << "Enter student's IC number: ";
		getline(cin, student[i].icNumber);

		cout << "Enter mark for Bahasa Melayu: ";
		cin >> student[i].mark.bahasa;
		cout << "Enter mark for English: ";
		cin >> student[i].mark.english;
		cout << "Enter mark for History: ";
		cin >> student[i].mark.history;
		cout << "Enter mark for Mathematics: ";
		cin >> student[i].mark.math;
		cout << "Enter mark for Additional Mathematics: ";
		cin >> student[i].mark.addMath;
		cout << "Enter mark for Biology: ";
		cin >> student[i].mark.biology;
		cout << "Enter mark for Chemistry: ";
		cin >> student[i].mark.chemistry;
		cout << "Enter mark for Physics: ";
		cin >> student[i].mark.physics;
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
	cout << "|\t\t\t" << left << setw(40) << "3 - Highest to Lowest Total and Average Mark" << right << setw(33) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "4 - Lowest to Highest Total and Average Mark" << right << setw(33) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "5 - Highest to Lowest for Each Subject" << right << setw(37) << "|" << endl;
	cout << "|\t\t\t" << left << setw(40) << "6 - Search certain mark in certain subject" << right << setw(35) << "|" << endl;
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
		student[i].mark.totalMark = student[i].mark.bahasa + student[i].mark.english + student[i].mark.history + student[i].mark.math
			+ student[i].mark.addMath + student[i].mark.biology + student[i].mark.chemistry + student[i].mark.physics;
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

// function to display data lowest to highest by Haziq
void displayLtoH(int n) {

	resetValue(n);
	reverseRanks(n);

	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "LOWEST MARK TO HIGHEST MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================" << endl;

	cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;

	for (int i = 0; i < n; i++)
		cout << i + 1 << ".\t" << left << setw(25) << student3[i].name3 << "\t" << student3[i].icNum3 << "\t\t" << fixed << setprecision(1) << student3[i].mark3.totalMarkLH << "\t\t" << fixed << setprecision(1) << student3[i].avg3 << endl;
	cout << endl;
}

// select subject by Fatin
int selectSubject(string subject[]) {
	int select;
	cout << "List of subject:" << endl;
	for (int i = 1; i <= 8; i++) {
		cout << i << ". " << subject[i - 1] << endl;
	}
	cout << "\nSelect subject: ";
	cin >> select;
	return select - 1;
}

// function to compare marks between students to arrange mark in array by Haziq
bool compareBahasa(Participant3 a, Participant3 b) {
	if (a.mark3.bahasa3 != b.mark3.bahasa3)
		return a.mark3.bahasa3 > b.mark3.bahasa3;
	else
		return 0;
}

bool compareEnglish(Participant3 a, Participant3 b) {
	if (a.mark3.english3 != b.mark3.english3)
		return a.mark3.english3 > b.mark3.english3;
	else
		return 0;
}

bool compareHistory(Participant3 a, Participant3 b) {
	if (a.mark3.history3 != b.mark3.history3)
		return a.mark3.history3 > b.mark3.history3;
	else
		return 0;
}

bool compareMath(Participant3 a, Participant3 b) {
	if (a.mark3.math3 != b.mark3.math3)
		return a.mark3.math3 > b.mark3.math3;
	else
		return 0;
}

bool compareAddMath(Participant3 a, Participant3 b) {
	if (a.mark3.addMath3 != b.mark3.addMath3)
		return a.mark3.addMath3 > b.mark3.addMath3;
	else
		return 0;
}

bool compareBio(Participant3 a, Participant3 b) {
	if (a.mark3.biology3 != b.mark3.biology3)
		return a.mark3.biology3 > b.mark3.biology3;
	else
		return 0;
}

bool compareChem(Participant3 a, Participant3 b) {
	if (a.mark3.chemistry3 != b.mark3.chemistry3)
		return a.mark3.chemistry3 > b.mark3.chemistry3;
	else
		return 0;
}

bool comparePhy(Participant3 a, Participant3 b) {
	if (a.mark3.physics3 != b.mark3.physics3)
		return a.mark3.physics3 > b.mark3.physics3;
	else
		return 0;
}

//function to sort array by Fatin
void compareSubjectMark(int n, int choice) {

	if (choice == 0)
		sort(student3, student3 + n, compareBahasa);
	else if (choice == 1)
		sort(student3, student3 + n, compareEnglish);
	else if (choice == 2)
		sort(student3, student3 + n, compareHistory);
	else if (choice == 3)
		sort(student3, student3 + n, compareMath);
	else if (choice == 4)
		sort(student3, student3 + n, compareAddMath);
	else if (choice == 5)
		sort(student3, student3 + n, compareBio);
	else if (choice == 6)
		sort(student3, student3 + n, compareChem);
	else
		sort(student3, student3 + n, comparePhy);

	for (int i = 0; i < n; i++)
		student3[i].mark3.rank3 = i + 1;
}

// display name with highest to lowest mark in certain subject by Fatin
void displayNameWithSubject(int choice, string subject[], int size) {
	resetValue(size);

	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "HIGHEST MARK TO LOWEST MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================" << endl;

	cout << endl << "\tName\tIC Number\t" << subject[choice] << endl;
	compareSubjectMark(size, choice);
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\t" << student3[i].name3 << "\t" << student3[i].icNum3 << "\t\t";

		if (choice == 0)
			cout << student3[i].mark3.bahasa3;
		else if (choice == 1)
			cout << student3[i].mark3.english3;
		else if (choice == 2)
			cout << student3[i].mark3.history3;
		else if (choice == 3)
			cout << student3[i].mark3.math3;
		else if (choice == 4)
			cout << student3[i].mark3.addMath3;
		else if (choice == 5)
			cout << student3[i].mark3.biology3;
		else if (choice == 6)
			cout << student3[i].mark3.chemistry3;
		else
			cout << student3[i].mark3.physics3;

		cout << endl;
	}
}

// function to reset value in new Structure by Haziq
void resetValue(int n) {
	for (int i = 0; i < n; i++) {
		student3[i].name3 = student[i].name;
		student3[i].icNum3 = student[i].icNumber;
		student3[i].avg3 = student[i].averageMark;
		student3[i].mark3.totalMarkLH = student[i].mark.totalMark;
		student3[i].mark3.bahasa3 = student[i].mark.bahasa;
		student3[i].mark3.english3 = student[i].mark.english;
		student3[i].mark3.history3 = student[i].mark.history;
		student3[i].mark3.math3 = student[i].mark.math;
		student3[i].mark3.addMath3 = student[i].mark.addMath;
		student3[i].mark3.biology3 = student[i].mark.biology;
		student3[i].mark3.chemistry3 = student[i].mark.chemistry;
		student3[i].mark3.physics3 = student[i].mark.physics;
	}
}