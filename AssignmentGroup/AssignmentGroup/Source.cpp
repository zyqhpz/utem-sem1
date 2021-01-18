#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
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
	int science;
	int geography;
	double totalMark;
	int rank;
};

struct Participant {
	string name;
	string icNumber;
	Subject mark;
	double averageMark;
};
struct Class {
	string className[4];
	Participant student[1000];
};

Class F5[10];
Class F4[10];
Class F3[10];
Class F2[10];
Class F1[10];

struct Subject3 {
	int subject3[8];
	double totalMark3;
	int bahasa3;
	int english3;
	int history3;
	int math3;
	int addMath3;
	int biology3;
	int chemistry3;
	int physics3;
	int science3;
	int geography3;
	int rank3;
};

struct Participant3 {
	string name3;
	string icNum3;
	Subject3 mark3;
	double avg3;
};

struct Class3 {
	string className3[100];
	Participant3 student3[1000];
};

Class3 F5_3[10];
Class3 F4_3[10];
Class3 F3_3[10];
Class3 F2_3[10];
Class3 F1_3[10];

struct Form {
	string name;
	string ic;
	double totalM;
	double avg;
	int rank;
};

Form form5[1000];
Form form4[1000];
Form form3[1000];
Form form2[1000];
Form form1[1000];

int numClass();
int numStudent();
int displayMenu();
int* getNameF5(int);
void displayName(int[], int);
Participant calculateAverageMark(int[], int, int);
void displayTotalMark(int[], int, int);
void displayHtoL(int[], int, int);
void displayLtoH(int[], int, int);
void reverseRanks(int, int[], int);
void sortRanks(int, int[], int);
bool compareLowHigh(Participant3, Participant3);
bool compareHighLow(Participant3, Participant3);
void resetValue(int[], int, int);
int selectSubject(string[]);

bool compareBahasa(Participant3, Participant3);
bool compareEnglish(Participant3, Participant3);
bool compareHistory(Participant3, Participant3);
bool compareMath(Participant3, Participant3);
bool compareAddMath(Participant3, Participant3);
bool compareBio(Participant3, Participant3);
bool compareChem(Participant3, Participant3);
bool comparePhy(Participant3, Participant3);

void displayNameWithSubject(int, string[], int[], int, int);
void compareSubjectMark(int[], int, int, int);

bool compareNameAZ(Participant3, Participant3);
bool compareNameZA(Participant3, Participant3);
void displayNameSorted(int[], int, int);
void loadNameList(int[], int, int);

bool compareAllName(Form, Form);
void mergeData(int, int[], int&);

//Function Prototypes for Form 4(new data)
int* getNameF4(int);
void mergeDataF4(int, int n_F4[], int &);
int selectSubjectLower(string subject[]);

int* getNameF3(int);
void mergeDataF3(int, int n_F3[], int&);
int selectSubjectLower(string subject[]);

int* getNameF2(int);
void mergeDataF2(int, int n_F2[], int&);
int selectSubjectLower(string subject[]);

int* getNameF1(int);
void mergeDataF1(int, int n_F1[], int&);
int selectSubjectLower(string subject[]);

Participant calculateAverageMarkLower(int[], int, int);

void displayAllName(int[], int, int, int);
void displayMainMenu();
int formSelection();

// main by Fatin
int main() {

	// This is a latest coding after lab submission on 7/1/2021 !

	string subjectUpper[8] = { "Bahasa Melayu", "English", "History", "Mathematics", "Additional Mathematics", "Biology", "Chemistry", "Physics" };
	string subjectLower[8] = { "Bahasa Melayu", "English", "History", "Mathematics", "Science", "Geography" };
	string f5Class[4] = { "5 Alchemilla", "5 Begonia", "5 Calendula", "5 Dahlia" };

	//					UPPER		LOWER
	// BM -				0			0		
	// English -		1			1
	// History -		2			2
	// Math -			3			3
	// AddMath -		4
	// Bio -			5	
	// Chem -			6
	// Physics -		7
	// Science -					4		
	// Geography -					5 			

	int c_F5 = 0, numOfClassF5, c_F4 = 0, numOfClassF4, c_F3 = 0, numOfClassF3, c_F2 = 0, numOfClassF2, c_F1 = 0, numOfClassF1;
	int* n_F5 = 0, *n_F4 = 0, *n_F3 = 0, *n_F2 = 0, *n_F1 = 0;

	int choice, selectSub, selectOperation, selectSubLow;
	int numStudentF5 = 0, numStudentF4 = 0, numStudentF3 = 0, numStudentF2 = 0, numStudentF1 = 0;

	Participant averageF5, averageF4, averageF3, averageF2, averageF1;
	cout << "=====================================================================================================" << endl;
	cout << "|                                                                                                   |" << endl;
	cout << "|                                   STUDENT MARK RECORD SYSTEM                                      |" << endl;
	cout << "|                                                                                                   |" << endl;
	int selectForm = formSelection();

	//int noOfClass = numClass();
	//int c = noOfClass;
	//int* n = getNameF5(noOfClass);

	if (selectForm == 5) {
		do {
			cout << "\n\n1. Enter new data.\n2. Display existing data.\n3. Back to Main Menu.\n0. End Program.\n\nYour choice: ";
			cin >> selectOperation;
			if (selectOperation == 1) {
				numOfClassF5 = numClass();
				c_F5 = numOfClassF5;
				n_F5 = getNameF5(numOfClassF5);
			}
			else if (selectOperation == 2) {
				loadNameList(n_F5, c_F5, selectForm);

				averageF5 = calculateAverageMark(n_F5, c_F5, selectForm);

				do {
					choice = displayMenu();

					if (choice == 0) {
						break;
					}
					else if (choice == 1)
						displayNameSorted(n_F5, c_F5, selectForm);
					//displayName(n, c);
					else if (choice == 2) {
						displayTotalMark(n_F5, c_F5, selectForm);
						displayAllName(n_F5, c_F5, numStudentF5, selectForm);
					}
					else if (choice == 3)
						displayHtoL(n_F5, c_F5, selectForm);
					else if (choice == 4)
						displayLtoH(n_F5, c_F5, selectForm);
					else if (choice == 5) {
						selectSub = selectSubject(subjectUpper);
						displayNameWithSubject(selectSub, subjectUpper, n_F5, c_F5, selectForm);
					}
					else
						cout << "Invalid choice";

					cout << endl;
				} while (choice != 0);
			}
			else if (selectOperation == 3)
				int selectForm = formSelection();
			else if (selectOperation == 0) {
				cout << "Program Terminated.";
				break;
			}
			else
				cout << "Invalid input" << endl;
		} while (selectOperation != 0);
	}
	else if (selectForm == 4) {
		do {
			cout << "\n\n1. Enter new data.\n2. Display existing data.\n3. Back to Main Menu.\n0. End Program.\n\nYour choice: ";
			cin >> selectOperation;
			if (selectOperation == 1) {
				numOfClassF4 = numClass();
				c_F4 = numOfClassF4;
				n_F4 = getNameF4(numOfClassF4);
			}
			else if (selectOperation == 2) {
				loadNameList(n_F4, c_F4, selectForm);

				averageF4 = calculateAverageMark(n_F4, c_F4, selectForm);

				do {
					choice = displayMenu();

					if (choice == 0) {
						break;
					}
					else if (choice == 1)
						displayNameSorted(n_F4, c_F4, selectForm);
					//displayName(n, c);
					else if (choice == 2) {
						displayTotalMark(n_F4, c_F4, selectForm);
						displayAllName(n_F4, c_F4, numStudentF4, selectForm);
					}
					else if (choice == 3)
						displayHtoL(n_F4, c_F4, selectForm);
					else if (choice == 4)
						displayLtoH(n_F4, c_F4, selectForm);
					else if (choice == 5) {
						selectSub = selectSubject(subjectUpper);
						displayNameWithSubject(selectSub, subjectUpper, n_F4, c_F4, selectForm);
					}
					else
						cout << "Invalid choice";

					cout << endl;
				} while (choice != 0);
			}
			else if (selectOperation == 3)
				int selectForm = formSelection();
			else if (selectOperation == 0) {
				cout << "Program Terminated.";
				break;
			}
			else
				cout << "Invalid input" << endl;
		} while (selectOperation != 0);
	}
	else if (selectForm == 3) {
		do {
			cout << "\n1. Enter new data.\n2. Display existing data.\n3. Back to Main Menu.\n0. End Program.\n\nYour choice: ";
			cin >> selectOperation;
				if (selectOperation == 1) {
					numOfClassF3 = numClass();
					c_F3 = numOfClassF3;
					n_F3 = getNameF3(numOfClassF3);
				}
				else if (selectOperation == 2) {

					averageF3 = calculateAverageMarkLower(n_F3, c_F3, selectForm);

					do {
						choice = displayMenu();

						if (choice == 0) {
							break;
						}
						else if (choice == 1)
							displayNameSorted(n_F3, c_F3, selectForm);
						//displayName(n, c);
						else if (choice == 2) {
							displayTotalMark(n_F3, c_F3, selectForm);
							displayAllName(n_F3, c_F3, numStudentF3, selectForm);
						}
						else if (choice == 3)
							displayHtoL(n_F3, c_F3, selectForm);
						else if (choice == 4)
							displayLtoH(n_F3, c_F3, selectForm);
						else if (choice == 5) {
							selectSubLow = selectSubjectLower(subjectLower);
							displayNameWithSubject(selectSubLow, subjectLower, n_F3, c_F3, selectForm);
						}
						else
							cout << "Invalid choice";
							cout << endl;
					} while (choice != 0);
				}
			else if (selectOperation == 3)
				int selectForm = formSelection();
			else if (selectOperation == 0) {
				cout << "Program Terminated.";
				break;
				}
			else
				cout << "Invalid input" << endl;
		} while (selectOperation != 0);
	}
	else if (selectForm == 2) {
	do {
		cout << "\n1. Enter new data.\n2. Display existing data.\n3. Back to Main Menu.\n0. End Program.\n\nYour choice: ";
		cin >> selectOperation;
		if (selectOperation == 1) {
			numOfClassF2 = numClass();
			c_F2 = numOfClassF2;
			n_F2 = getNameF2(numOfClassF2);
		}
		else if (selectOperation == 2) {

			averageF2 = calculateAverageMarkLower(n_F2, c_F2, selectForm);

			do {
				choice = displayMenu();

				if (choice == 0) {
					break;
				}
				else if (choice == 1)
					displayNameSorted(n_F2, c_F2, selectForm);
				//displayName(n, c);
				else if (choice == 2) {
					displayTotalMark(n_F2, c_F2, selectForm);
					displayAllName(n_F2, c_F2, numStudentF3, selectForm);
				}
				else if (choice == 3)
					displayHtoL(n_F2, c_F2, selectForm);
				else if (choice == 4)
					displayLtoH(n_F2, c_F2, selectForm);
				else if (choice == 5) {
					selectSubLow = selectSubjectLower(subjectLower);
					displayNameWithSubject(selectSubLow, subjectLower, n_F2, c_F2, selectForm);
				}
				else
					cout << "Invalid choice";
				cout << endl;
			} while (choice != 0);
		}
		else if (selectOperation == 3)
			int selectForm = formSelection();
		else if (selectOperation == 0) {
			cout << "Program Terminated.";
			break;
		}
		else
			cout << "Invalid input" << endl;
	} while (selectOperation != 0);
	}
	else if (selectForm == 1) {
		do {
			cout << "\n1. Enter new data.\n2. Display existing data.\n3. Back to Main Menu.\n0. End Program.\n\nYour choice: ";
			cin >> selectOperation;
			if (selectOperation == 1) {
				numOfClassF1 = numClass();
				c_F3 = numOfClassF1;
				n_F3 = getNameF1(numOfClassF1);
			}
			else if (selectOperation == 2) {

				averageF1 = calculateAverageMarkLower(n_F1, c_F1, selectForm);

				do {
					choice = displayMenu();

					if (choice == 0) {
						break;
					}
					else if (choice == 1)
						displayNameSorted(n_F1, c_F1, selectForm);
					//displayName(n, c);
					else if (choice == 2) {
						displayTotalMark(n_F1, c_F1, selectForm);
						displayAllName(n_F1, c_F1, numStudentF1, selectForm);
					}
					else if (choice == 3)
						displayHtoL(n_F1, c_F1, selectForm);
					else if (choice == 4)
						displayLtoH(n_F1, c_F1, selectForm);
					else if (choice == 5) {
						selectSubLow = selectSubjectLower(subjectLower);
						displayNameWithSubject(selectSubLow, subjectLower, n_F1, c_F1, selectForm);
					}
					else
						cout << "Invalid choice";
					cout << endl;
				} while (choice != 0);
			}
			else if (selectOperation == 3)
				int selectForm = formSelection();
			else if (selectOperation == 0) {
				cout << "Program Terminated.";
				break;
			}
			else
				cout << "Invalid input" << endl;
		} while (selectOperation != 0);
	}
	return 0;
}

// Kak Lok
int numClass() {
	int c;
	cout << "Enter the number of class that want to be entered: ";
	cin >> c;
	return c;
}

// get number of student in class by Haziq
int numStudent() {
	int n;
	cout << "Enter total number of student that want to be entered: ";
	cin >> n;
	return n;
}

// get input function by Haziq 
int* getNameF5(int c) {
	static int n[1000];
	ofstream writeFile("studentDataF5.txt", ios::out | ios::app);

	for (int a = 0; a < c; a++) {
		cout << "\n*********************" << endl;
		cout << "For Class " << a + 1 << endl;
		//num[a] = numStudent(c);
		cout << "Enter total number of student that want to be entered: ";
		cin >> n[a];
		for (int i = 0; i < n[a]; i++) {
			cin.ignore();
			F5[a].student[i].mark.totalMark = 0;
			cout << endl << "Enter student name: ";
			getline(cin, F5[a].student[i].name);
			cout << "Enter student's IC number: ";
			getline(cin, F5[a].student[i].icNumber);

			cout << "Enter mark for Bahasa Melayu: ";
			cin >> F5[a].student[i].mark.bahasa;
			cout << "Enter mark for English: ";
			cin >> F5[a].student[i].mark.english;
			cout << "Enter mark for History: ";
			cin >> F5[a].student[i].mark.history;
			cout << "Enter mark for Mathematics: ";
			cin >> F5[a].student[i].mark.math;
			cout << "Enter mark for Additional Mathematics: ";
			cin >> F5[a].student[i].mark.addMath;
			cout << "Enter mark for Biology: ";
			cin >> F5[a].student[i].mark.biology;
			cout << "Enter mark for Chemistry: ";
			cin >> F5[a].student[i].mark.chemistry;
			cout << "Enter mark for Physics: ";
			cin >> F5[a].student[i].mark.physics;
			cout << endl;

			writeFile
				<< F5[a].student[i].name << endl
				<< F5[a].student[i].icNumber << endl
				<< F5[a].student[i].mark.bahasa << endl
				<< F5[a].student[i].mark.english << endl
				<< F5[a].student[i].mark.history << endl
				<< F5[a].student[i].mark.math << endl
				<< F5[a].student[i].mark.addMath << endl
				<< F5[a].student[i].mark.biology << endl
				<< F5[a].student[i].mark.chemistry << endl
				<< F5[a].student[i].mark.physics << endl;
		}
	}
	cout << endl;
	writeFile.close();
	return n;
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
	cout << "|\t\t\t" << left << setw(40) << "0 - Previous Menu" << right << setw(37) << "|" << endl;
	cout << "|" << setw(100) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(30) << "Please enter 0/1/2/3/4/5/6 to choose." << right << setw(32) << "|" << endl;
	cout << "=====================================================================================================" << endl << endl;

	cout << "What do you want to display? : ";
	cin >> choice;
	return choice;
}

// display namelist by Kak Lok
void displayName(int n[], int c) {
	//resetValue(size);
	for (int a = 0; a < c; a++) {
		cout << "\nClass " << a + 1;
		cout << endl << left << setw(25) << "\tName" << "\tIC Number" << endl;
		for (int i = 0; i < n[a]; i++) {
			cout << i + 1 << ".\t" << left << setw(25) << F5[a].student[i].name << "\t" << F5[a].student[i].icNumber << endl;
		}
	}
}

// calculate average by Kak Lok
Participant calculateAverageMark(int n[], int c, int form) {
	Participant average;
	
	if (form == 5) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F5[a].student[i].mark.totalMark = F5[a].student[i].mark.bahasa + F5[a].student[i].mark.english + F5[a].student[i].mark.history + F5[a].student[i].mark.math
					+ F5[a].student[i].mark.addMath + F5[a].student[i].mark.biology + F5[a].student[i].mark.chemistry + F5[a].student[i].mark.physics;
				F5[a].student[i].averageMark = F5[a].student[i].mark.totalMark / 8;
			}
		}
	}
	else if (form == 4) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F4[a].student[i].mark.totalMark = F4[a].student[i].mark.bahasa + F4[a].student[i].mark.english + F4[a].student[i].mark.history + F4[a].student[i].mark.math
					+ F4[a].student[i].mark.addMath + F4[a].student[i].mark.biology + F4[a].student[i].mark.chemistry + F4[a].student[i].mark.physics;
				F4[a].student[i].averageMark = F4[a].student[i].mark.totalMark / 8;
			}
		}
	}
	else if (form == 3) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F3[a].student[i].mark.totalMark = F3[a].student[i].mark.bahasa + F3[a].student[i].mark.english + F3[a].student[i].mark.history + F3[a].student[i].mark.math
					+ F3[a].student[i].mark.addMath + F3[a].student[i].mark.biology + F3[a].student[i].mark.chemistry + F3[a].student[i].mark.physics;
				F3[a].student[i].averageMark = F3[a].student[i].mark.totalMark / 8;
			}
		}
	}
	else
		cout << "f3";
	return average;
}

// display namelist with mark by Kak Lok
void displayTotalMark(int n[], int c, int form) {
	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "TOTAL AND AVERAGE MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================";

	if (form == 5) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F5[a].student[i].name << "\t" << F5[a].student[i].icNumber << "\t\t"
					<< static_cast<int>(F5[a].student[i].mark.totalMark) << "\t\t" << fixed << setprecision(1) << F5[a].student[i].averageMark << endl;
			}
		}
	}
	else if (form == 4) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F4[a].student[i].name << "\t" << F4[a].student[i].icNumber << "\t\t"
					<< static_cast<int>(F4[a].student[i].mark.totalMark) << "\t\t" << fixed << setprecision(1) << F4[a].student[i].averageMark << endl;
			}
		}
	}
	else if (form == 3) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F3[a].student[i].name << "\t" << F3[a].student[i].icNumber << "\t\t"
					<< static_cast<int>(F3[a].student[i].mark.totalMark) << "\t\t" << fixed << setprecision(1) << F3[a].student[i].averageMark << endl;
			}
		}
	}
	else if (form == 2) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F2[a].student[i].name << "\t" << F2[a].student[i].icNumber << "\t\t"
					<< static_cast<int>(F2[a].student[i].mark.totalMark) << "\t\t" << fixed << setprecision(1) << F2[a].student[i].averageMark << endl;
			}
		}
	}
	else {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F1[a].student[i].name << "\t" << F1[a].student[i].icNumber << "\t\t"
					<< static_cast<int>(F1[a].student[i].mark.totalMark) << "\t\t" << fixed << setprecision(1) << F1[a].student[i].averageMark << endl;
			}
		}
	}
	cout << endl;
}

bool compareHighLow(Participant3 a, Participant3 b) {
	if (a.mark3.totalMark3 != b.mark3.totalMark3)
		return a.mark3.totalMark3 > b.mark3.totalMark3;
	else
		return 0;
}

// function to modify data lowest to highest by Haziq
void sortRanks(int a, int n[], int form) {
	if (form == 5) {
		sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareHighLow);
		for (int i = 0; i < n[a]; i++)
			F5_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else if (form == 4) {
		sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareHighLow);
		for (int i = 0; i < n[a]; i++)
			F4_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else if (form == 3) {
		sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareHighLow);
		for (int i = 0; i < n[a]; i++)
			F3_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else if (form == 2) {
		sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareHighLow);
		for (int i = 0; i < n[a]; i++)
			F2_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else {
		sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareHighLow);
		for (int i = 0; i < n[a]; i++)
			F1_3[a].student3[i].mark3.rank3 = i + 1;
	}
}

// modify data highest to lowest by Kak Lok
void displayHtoL(int n[], int c, int form) {
	resetValue(n, c, form);
	for (int a = 0; a < c; a++)
		sortRanks(a, n, form);

	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "HIGHEST MARK TO LOWEST MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================";


	if (form == 5) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++)
				cout << i + 1 << ".\t" << left << setw(25) << F5_3[a].student3[i].name3 << "\t" << F5_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F5_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F5_3[a].student3[i].avg3 << endl;
			cout << endl;
		}
	}
	else if (form == 4) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++)
				cout << i + 1 << ".\t" << left << setw(25) << F4_3[a].student3[i].name3 << "\t" << F4_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F4_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F4_3[a].student3[i].avg3 << endl;
			cout << endl;
		}
	}
	else if (form == 3) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++)
				cout << i + 1 << ".\t" << left << setw(25) << F3_3[a].student3[i].name3 << "\t" << F3_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F3_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F3_3[a].student3[i].avg3 << endl;
			cout << endl;
		}
	}
	else if (form == 2) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F2_3[a].student3[i].name3 << "\t" << F2_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F2_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F2_3[a].student3[i].avg3 << endl;
			}
		}
	}
	else {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F1_3[a].student3[i].name3 << "\t" << F1_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F1_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F1_3[a].student3[i].avg3 << endl;
			}
		}
	}
}

// function to modify data lowest to highest by Haziq
bool compareLowHigh(Participant3 a, Participant3 b) {
	if (a.mark3.totalMark3 != b.mark3.totalMark3)
		return a.mark3.totalMark3 < b.mark3.totalMark3;
	else
		return 0;
}

// function to modify data lowest to highest by Haziq
void reverseRanks(int a, int n[], int form) {
	if (form == 5) {
		sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareLowHigh);
		for (int i = 0; i < n[a]; i++)
			F5_3[a].student3[i].mark3.rank3 = i - 1;
	}
	else if (form == 4) {
		sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareLowHigh);
		for (int i = 0; i < n[a]; i++)
			F4_3[a].student3[i].mark3.rank3 = i - 1;
	}
	else if (form == 3) {
		sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareLowHigh);
			for (int i = 0; i < n[a]; i++)
				F3_3[a].student3[i].mark3.rank3 = i - 1;
	}
	else if (form == 2) {
		sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareLowHigh);
		for (int i = 0; i < n[a]; i++)
			F2_3[a].student3[i].mark3.rank3 = i - 1;
	}
	else {
		sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareLowHigh);
		for (int i = 0; i < n[a]; i++)
			F1_3[a].student3[i].mark3.rank3 = i - 1;
	}
}

// function to display data lowest to highest by Haziq
void displayLtoH(int n[], int c, int form) {

	resetValue(n, c, form);
	for (int a = 0; a < c; a++)
		reverseRanks(a, n, form);

	cout << "\n=====================================================================================================" << endl;
	cout << "|" << setw(60) << "LOWEST MARK TO HIGHEST MARK" << setw(40) << "|" << endl;
	cout << "=====================================================================================================";
	
	if (form == 5) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++)
				cout << i + 1 << ".\t" << left << setw(25) << F5_3[a].student3[i].name3 << "\t" << F5_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F5_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F5_3[a].student3[i].avg3 << endl;
			cout << endl;
		}
	}
	else if (form == 4) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++)
				cout << i + 1 << ".\t" << left << setw(25) << F4_3[a].student3[i].name3 << "\t" << F4_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F4_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F4_3[a].student3[i].avg3 << endl;
			cout << endl;
		}
	}
	else if (form == 3) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++)
				cout << i + 1 << ".\t" << left << setw(25) << F3_3[a].student3[i].name3 << "\t" << F3_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
				static_cast<int>(F3_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F3_3[a].student3[i].avg3 << endl;
			cout << endl;
		}
	}
	else if (form == 2) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F2_3[a].student3[i].name3 << "\t" << F2_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
					static_cast<int>(F2_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F2_3[a].student3[i].avg3 << endl;
			}
		}
	}
	else {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\tTotal Mark\tAverage Mark" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F1_3[a].student3[i].name3 << "\t" << F1_3[a].student3[i].icNum3 << "\t\t" << fixed << setprecision(1) <<
					static_cast<int>(F1_3[a].student3[i].mark3.totalMark3) << "\t\t" << fixed << setprecision(1) << F1_3[a].student3[i].avg3 << endl;
			}
		}
	}
	cout << endl;
}

// function to reset value in new Structure by Haziq
void resetValue(int n[], int c, int form) {

	if (form == 5) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F5_3[a].student3[i].name3 = F5[a].student[i].name;
				F5_3[a].student3[i].icNum3 = F5[a].student[i].icNumber;
				F5_3[a].student3[i].avg3 = F5[a].student[i].averageMark;
				F5_3[a].student3[i].mark3.totalMark3 = F5[a].student[i].mark.totalMark;
				F5_3[a].student3[i].mark3.bahasa3 = F5[a].student[i].mark.bahasa;
				F5_3[a].student3[i].mark3.english3 = F5[a].student[i].mark.english;
				F5_3[a].student3[i].mark3.history3 = F5[a].student[i].mark.history;
				F5_3[a].student3[i].mark3.math3 = F5[a].student[i].mark.math;
				F5_3[a].student3[i].mark3.addMath3 = F5[a].student[i].mark.addMath;
				F5_3[a].student3[i].mark3.biology3 = F5[a].student[i].mark.biology;
				F5_3[a].student3[i].mark3.chemistry3 = F5[a].student[i].mark.chemistry;
				F5_3[a].student3[i].mark3.physics3 = F5[a].student[i].mark.physics;
			}
		}
	}

	else if (form == 4) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F4_3[a].student3[i].name3 = F4[a].student[i].name;
				F4_3[a].student3[i].icNum3 = F4[a].student[i].icNumber;
				F4_3[a].student3[i].avg3 = F4[a].student[i].averageMark;
				F4_3[a].student3[i].mark3.totalMark3 = F4[a].student[i].mark.totalMark;
				F4_3[a].student3[i].mark3.bahasa3 = F4[a].student[i].mark.bahasa;
				F4_3[a].student3[i].mark3.english3 = F4[a].student[i].mark.english;
				F4_3[a].student3[i].mark3.history3 = F4[a].student[i].mark.history;
				F4_3[a].student3[i].mark3.math3 = F4[a].student[i].mark.math;
				F4_3[a].student3[i].mark3.addMath3 = F4[a].student[i].mark.addMath;
				F4_3[a].student3[i].mark3.biology3 = F4[a].student[i].mark.biology;
				F4_3[a].student3[i].mark3.chemistry3 = F4[a].student[i].mark.chemistry;
				F4_3[a].student3[i].mark3.physics3 = F4[a].student[i].mark.physics;
			}
		}
	}

	else if (form == 3) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F3_3[a].student3[i].name3 = F3[a].student[i].name;
				F3_3[a].student3[i].icNum3 = F3[a].student[i].icNumber;
				F3_3[a].student3[i].avg3 = F3[a].student[i].averageMark;
				F3_3[a].student3[i].mark3.totalMark3 = F3[a].student[i].mark.totalMark;
				F3_3[a].student3[i].mark3.bahasa3 = F3[a].student[i].mark.bahasa;
				F3_3[a].student3[i].mark3.english3 = F3[a].student[i].mark.english;
				F3_3[a].student3[i].mark3.history3 = F3[a].student[i].mark.history;
				F3_3[a].student3[i].mark3.math3 = F3[a].student[i].mark.math;
				F3_3[a].student3[i].mark3.science3 = F3[a].student[i].mark.science;
				F3_3[a].student3[i].mark3.geography3 = F3[a].student[i].mark.geography;
			}
		}
	}

	else if (form == 2) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F2_3[a].student3[i].name3 = F2[a].student[i].name;
				F2_3[a].student3[i].icNum3 = F2[a].student[i].icNumber;
				F2_3[a].student3[i].avg3 = F2[a].student[i].averageMark;
				F2_3[a].student3[i].mark3.totalMark3 = F2[a].student[i].mark.totalMark;
				F2_3[a].student3[i].mark3.bahasa3 = F2[a].student[i].mark.bahasa;
				F2_3[a].student3[i].mark3.english3 = F2[a].student[i].mark.english;
				F2_3[a].student3[i].mark3.history3 = F2[a].student[i].mark.history;
				F2_3[a].student3[i].mark3.math3 = F2[a].student[i].mark.math;
				F2_3[a].student3[i].mark3.science3 = F2[a].student[i].mark.science;
				F2_3[a].student3[i].mark3.geography3 = F2[a].student[i].mark.geography;
			}
		}
	}

	else {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F1_3[a].student3[i].name3 = F1[a].student[i].name;
				F1_3[a].student3[i].icNum3 = F1[a].student[i].icNumber;
				F1_3[a].student3[i].avg3 = F1[a].student[i].averageMark;
				F1_3[a].student3[i].mark3.totalMark3 = F1[a].student[i].mark.totalMark;
				F1_3[a].student3[i].mark3.bahasa3 = F1[a].student[i].mark.bahasa;
				F1_3[a].student3[i].mark3.english3 = F1[a].student[i].mark.english;
				F1_3[a].student3[i].mark3.history3 = F1[a].student[i].mark.history;
				F1_3[a].student3[i].mark3.math3 = F1[a].student[i].mark.math;
				F1_3[a].student3[i].mark3.science3 = F1[a].student[i].mark.science;
				F1_3[a].student3[i].mark3.geography3 = F1[a].student[i].mark.geography;
			}
		}
	}
}

// select subject by Fatin
int selectSubject(string subject[]) {
	int select;
	cout << "\n=====================================================================================================" << endl;
	cout << "|                              HIGHEST MARK TO LOWEST FOR EACH SUBJECT                              |" << endl;
	cout << "=====================================================================================================" << endl;
	cout << "List of subject:" << endl;
	for (int i = 1; i <= 8; i++) {
		cout << i << ". " << subject[i - 1] << endl;
	}
	do {
		cout << "\nSelect subject: ";
		cin >> select;
		if (select < 1 || select > 8)
			cout << "Invalid choice. Try again.\n";
	} while (select < 1 || select > 8);
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
bool compareSci(Participant3 a, Participant3 b) {
	if (a.mark3.science3 != b.mark3.science3)
		return a.mark3.science3 > b.mark3.science3;
	else
		return 0;
}
bool compareGeo(Participant3 a, Participant3 b) {
	if (a.mark3.geography3 != b.mark3.geography3)
		return a.mark3.geography3 > b.mark3.geography3;
	else
		return 0;
}

//function to sort array by Fatin
void compareSubjectMark(int n[], int a, int choice, int form) {

	if (form == 5) {
		if (choice == 0)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareBahasa);
		else if (choice == 1)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareEnglish);
		else if (choice == 2)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareHistory);
		else if (choice == 3)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareMath);
		else if (choice == 4)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareAddMath);
		else if (choice == 5)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareBio);
		else if (choice == 6)
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareChem);
		else
			sort(F5_3[a].student3, F5_3[a].student3 + n[a], comparePhy);

		for (int i = 0; i < n[a]; i++)
			F5_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else if (form == 4) {
		if (choice == 0)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareBahasa);
		else if (choice == 1)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareEnglish);
		else if (choice == 2)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareHistory);
		else if (choice == 3)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareMath);
		else if (choice == 4)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareAddMath);
		else if (choice == 5)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareBio);
		else if (choice == 6)
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareChem);
		else
			sort(F4_3[a].student3, F4_3[a].student3 + n[a], comparePhy);

		for (int i = 0; i < n[a]; i++)
			F4_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else if (form == 3) {
		if (choice == 0)
			sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareBahasa);
		else if (choice == 1)
			sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareEnglish);
		else if (choice == 2)
			sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareHistory);
		else if (choice == 3)
			sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareMath);
		else if (choice == 4)
			sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareSci);
		else
			sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareGeo);

		for (int i = 0; i < n[a]; i++)
			F3_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else if (form == 2) {
		if (choice == 0)
			sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareBahasa);
		else if (choice == 1)
			sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareEnglish);
		else if (choice == 2)
			sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareHistory);
		else if (choice == 3)
			sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareMath);
		else if (choice == 4)
			sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareSci);
		else
			sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareGeo);

		for (int i = 0; i < n[a]; i++)
			F2_3[a].student3[i].mark3.rank3 = i + 1;
	}
	else {
		if (choice == 0)
			sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareBahasa);
		else if (choice == 1)
			sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareEnglish);
		else if (choice == 2)
			sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareHistory);
		else if (choice == 3)
			sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareMath);
		else if (choice == 4)
			sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareSci);
		else
			sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareGeo);

		for (int i = 0; i < n[a]; i++)
			F1_3[a].student3[i].mark3.rank3 = i + 1;
	}
}

// display name with highest to lowest mark in certain subject by Fatin
void displayNameWithSubject(int choice, string subject[], int n[], int c, int form) {

	resetValue(n, c, form);
	for (int a = 0; a < c; a++)
		compareSubjectMark(n, a, choice, form);

	if (form == 5) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\t" << subject[choice] << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F5_3[a].student3[i].name3 << "\t" << F5_3[a].student3[i].icNum3 << "\t\t";

				if (choice == 0)
					cout << F5_3[a].student3[i].mark3.bahasa3;
				else if (choice == 1)
					cout << F5_3[a].student3[i].mark3.english3;
				else if (choice == 2)
					cout << F5_3[a].student3[i].mark3.history3;
				else if (choice == 3)
					cout << F5_3[a].student3[i].mark3.math3;
				else if (choice == 4)
					cout << F5_3[a].student3[i].mark3.addMath3;
				else if (choice == 5)
					cout << F5_3[a].student3[i].mark3.biology3;
				else if (choice == 6)
					cout << F5_3[a].student3[i].mark3.chemistry3;
				else
					cout << F5_3[a].student3[i].mark3.physics3;

				cout << endl;
			}
		}
	}
	else if (form == 4) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\t" << subject[choice] << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F4_3[a].student3[i].name3 << "\t" << F4_3[a].student3[i].icNum3 << "\t\t";

				if (choice == 0)
					cout << F4_3[a].student3[i].mark3.bahasa3;
				else if (choice == 1)
					cout << F4_3[a].student3[i].mark3.english3;
				else if (choice == 2)
					cout << F4_3[a].student3[i].mark3.history3;
				else if (choice == 3)
					cout << F4_3[a].student3[i].mark3.math3;
				else if (choice == 4)
					cout << F4_3[a].student3[i].mark3.addMath3;
				else if (choice == 5)
					cout << F4_3[a].student3[i].mark3.biology3;
				else if (choice == 6)
					cout << F4_3[a].student3[i].mark3.chemistry3;
				else
					cout << F4_3[a].student3[i].mark3.physics3;

				cout << endl;
			}
		}
	}
	else if (form == 3) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\t" << subject[choice] << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F3_3[a].student3[i].name3 << "\t" << F3_3[a].student3[i].icNum3 << "\t\t";

				if (choice == 0)
					cout << F3_3[a].student3[i].mark3.bahasa3;
				else if (choice == 1)
					cout << F3_3[a].student3[i].mark3.english3;
				else if (choice == 2)
					cout << F3_3[a].student3[i].mark3.history3;
				else if (choice == 3)
					cout << F3_3[a].student3[i].mark3.math3;
				else if (choice == 4)
					cout << F3_3[a].student3[i].mark3.science3;
				else if (choice == 5)
					cout << F3_3[a].student3[i].mark3.geography3;

				cout << endl;
			}
		}
	}
	else if (form == 2) {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\t" << subject[choice] << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F2_3[a].student3[i].name3 << "\t" << F2_3[a].student3[i].icNum3 << "\t\t";

				if (choice == 0)
					cout << F2_3[a].student3[i].mark3.bahasa3;
				else if (choice == 1)
					cout << F2_3[a].student3[i].mark3.english3;
				else if (choice == 2)
					cout << F2_3[a].student3[i].mark3.history3;
				else if (choice == 3)
					cout << F2_3[a].student3[i].mark3.math3;
				else if (choice == 4)
					cout << F2_3[a].student3[i].mark3.science3;
				else if (choice == 5)
					cout << F2_3[a].student3[i].mark3.geography3;

				cout << endl;
			}
		}
	}
	else {
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number\t" << subject[choice] << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F1_3[a].student3[i].name3 << "\t" << F1_3[a].student3[i].icNum3 << "\t\t";

				if (choice == 0)
					cout << F1_3[a].student3[i].mark3.bahasa3;
				else if (choice == 1)
					cout << F1_3[a].student3[i].mark3.english3;
				else if (choice == 2)
					cout << F1_3[a].student3[i].mark3.history3;
				else if (choice == 3)
					cout << F1_3[a].student3[i].mark3.math3;
				else if (choice == 4)
					cout << F1_3[a].student3[i].mark3.science3;
				else if (choice == 5)
					cout << F1_3[a].student3[i].mark3.geography3;

				cout << endl;
			}
		}
	}
}

bool compareNameAZ(Participant3 a, Participant3 b) {
	if (a.name3 != b.name3)
		return a.name3 < b.name3;
	else
		return 0;
}

bool compareNameZA(Participant3 a, Participant3 b) {
	if (a.name3 != b.name3)
		return a.name3 > b.name3;
	else
		return 0;
}

// function to sort name by Haziq
void displayNameSorted(int n[], int c, int form) {
	int choice, ch;
	resetValue(n, c, form);
	if (form == 5) {
		cout << "Select to display in: \n1.\tAscending\n2.\tDescending\nChoose: ";
		cin >> choice;
		ch = choice;
		for (int a = 0; a < c; a++) {
			if (choice == 1)
				sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareNameAZ);
			if (choice == 2)
				sort(F5_3[a].student3, F5_3[a].student3 + n[a], compareNameZA);
		}
		if (choice == 1) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (ASCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		if (choice == 2) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (DESCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F5_3[a].student3[i].name3 << "\t" << F5_3[a].student3[i].icNum3 << endl;
			}
		}
	}
	else if (form == 4) {
		cout << "Select to display in: \n1.\tAscending\n2.\tDescending\nChoose: ";
		cin >> choice;
		ch = choice;
		for (int a = 0; a < c; a++) {
			if (choice == 1)
				sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareNameAZ);
			if (choice == 2)
				sort(F4_3[a].student3, F4_3[a].student3 + n[a], compareNameZA);
		}
		if (choice == 1) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (ASCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		if (choice == 2) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (DESCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F4_3[a].student3[i].name3 << "\t" << F4_3[a].student3[i].icNum3 << endl;
			}
		}
	}
	else if (form == 3) {
		cout << "Select to display in: \n1.\tAscending\n2.\tDescending\nChoose: ";
		cin >> choice;
		ch = choice;
		for (int a = 0; a < c; a++) {
			if (choice == 1)
				sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareNameAZ);
			if (choice == 2)
				sort(F3_3[a].student3, F3_3[a].student3 + n[a], compareNameZA);
		}
		if (choice == 1) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (ASCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		if (choice == 2) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (DESCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F3_3[a].student3[i].name3 << "\t" << F3_3[a].student3[i].icNum3 << endl;
			}
		}
	}
	else if (form == 2) {
		cout << "Select to display in: \n1.\tAscending\n2.\tDescending\nChoose: ";
		cin >> choice;
		ch = choice;
		for (int a = 0; a < c; a++) {
			if (choice == 1)
				sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareNameAZ);
			if (choice == 2)
				sort(F2_3[a].student3, F2_3[a].student3 + n[a], compareNameZA);
		}
		if (choice == 1) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (ASCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		if (choice == 2) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (DESCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F2_3[a].student3[i].name3 << "\t" << F2_3[a].student3[i].icNum3 << endl;
			}
		}
	}
	else {
		cout << "Select to display in: \n1.\tAscending\n2.\tDescending\nChoose: ";
		cin >> choice;
		ch = choice;
		for (int a = 0; a < c; a++) {
			if (choice == 1)
				sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareNameAZ);
			if (choice == 2)
				sort(F1_3[a].student3, F1_3[a].student3 + n[a], compareNameZA);
		}
		if (choice == 1) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (ASCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		if (choice == 2) {
			cout << "\n*****************************************************************************************************" << endl;
			cout << "|" << setw(60) << "NAMELIST (DESCENDING)" << setw(40) << "|" << endl;
			cout << "*****************************************************************************************************";
		}
		for (int a = 0; a < c; a++) {
			cout << "\nClass " << a + 1;
			cout << endl << left << setw(25) << "\tName" << "\tIC Number" << endl;
			for (int i = 0; i < n[a]; i++) {
				cout << i + 1 << ".\t" << left << setw(25) << F1_3[a].student3[i].name3 << "\t" << F1_3[a].student3[i].icNum3 << endl;
			}
		}
	}
}

void loadNameList(int n[], int c, int form) {
	string nameStu;
	int noIC, bahasa, english, history, math, addMath, bio, chem, phy;
	int count = 1;

	if (form == 5) {
		ifstream readFileF5("studentDataF5.txt", ios::in);
		if (!readFileF5.is_open())
			cout << "File doesn't exist.\n";
		else {
			//cout << "--------Namelist-------\n";
			while (readFileF5 >> nameStu >> noIC >> bahasa >> english >> history >> math >> addMath >> bio >> chem >> phy) {
				for (int a = 0; a < c; a++) {
					for (int i = 0; i < n[i]; i++) {
						F5[a].student[i].name = nameStu;
						F5[a].student[i].icNumber = noIC;
						F5[a].student[i].mark.bahasa = bahasa;
						F5[a].student[i].mark.english = english;
						F5[a].student[i].mark.history = history;
						F5[a].student[i].mark.math = math;
						F5[a].student[i].mark.addMath = addMath;
						F5[a].student[i].mark.biology = bio;
						F5[a].student[i].mark.chemistry = chem;
						F5[a].student[i].mark.physics = phy;
					}
				}
			}
		}
	}
	if (form == 4) {
		ifstream readFileF4("studentDataF4.txt", ios::in);
		if (!readFileF4.is_open())
			cout << "File doesn't exist.\n";
		else {
			//cout << "--------Namelist-------\n";
			while (readFileF4 >> nameStu >> noIC >> bahasa >> english >> history >> math >> addMath >> bio >> chem >> phy) {
				for (int a = 0; a < 2; a++) {
					for (int i = 0; i < 4; i++) {
						F4[a].student[i].name = nameStu;
						F4[a].student[i].icNumber = noIC;
						F4[a].student[i].mark.bahasa = bahasa;
						F4[a].student[i].mark.english = english;
						F4[a].student[i].mark.history = history;
						F4[a].student[i].mark.math = math;
						F4[a].student[i].mark.addMath = addMath;
						F4[a].student[i].mark.biology = bio;
						F4[a].student[i].mark.chemistry = chem;
						F4[a].student[i].mark.physics = phy;
					}
				}
			}
		}
	}
}

bool compareAllName(Form a, Form b) {
	if (a.totalM != b.totalM)
		return a.totalM > b.totalM;
	else
		return 0;
}

void mergeData(int a, int n[], int &i) {

	for (int k = 0; k < n[a]; k++)
	{
		form5[i].name = F5[a].student[k].name;
		form5[i].ic = F5[a].student[k].icNumber;
		form5[i].totalM = F5[a].student[k].mark.totalMark;
		form5[i].avg = F5[a].student[k].averageMark;
		i++;
	}
}

void displayAllName(int n[], int c, int numS, int form) {
	if (form == 5) {
		for (int a = 0; a < c; a++)
			mergeData(a, n, numS);
		sort(form5, form5 + numS, compareAllName);
		cout << "\nFORM 5 STUDENTS\n";
		cout << "Name\tAverage Mark\n";
		for (int j = 0; j < numS; j++)
			cout << form5[j].name << "\t" << fixed << setprecision(1) << form5[j].avg << "\n";
	}
	if (form == 4) {
		for (int a = 0; a < c; a++)
			mergeDataF4(a, n, numS);
		sort(form4, form4 + numS, compareAllName);
		cout << "\nFORM 4 STUDENTS\n";
		cout << "Name\tAverage Mark\n";
		for (int j = 0; j < numS; j++)
			cout << form4[j].name << "\t" << fixed << setprecision(1) << form4[j].avg << "\n";
	}
	if (form == 3) {
		for (int a = 0; a < c; a++)
			mergeDataF3(a, n, numS);
		sort(form3, form3 + numS, compareAllName);
		cout << "\nFORM 3 STUDENTS\n";
		cout << "Name\tAverage Mark\n";
		for (int j = 0; j < numS; j++)
			cout << form3[j].name << "\t" << fixed << setprecision(1) << form3[j].avg << "\n";
	}
	if (form == 2) {
		for (int a = 0; a < c; a++)
			mergeDataF2(a, n, numS);
		sort(form2, form2 + numS, compareAllName);
		cout << "\nFORM 2 STUDENTS\n";
		cout << "Name\tAverage Mark\n";
		for (int j = 0; j < numS; j++)
			cout << form2[j].name << "\t" << fixed << setprecision(1) << form2[j].avg << "\n";
	}
	if (form == 1) {
		for (int a = 0; a < c; a++)
			mergeDataF1(a, n, numS);
		sort(form1, form1 + numS, compareAllName);
		cout << "\nFORM 1 STUDENTS\n";
		cout << "Name\tAverage Mark\n";
		for (int j = 0; j < numS; j++)
			cout << form1[j].name << "\t" << fixed << setprecision(1) << form1[j].avg << "\n";
	}
}

void displayMainMenu() {
	cout << "=====================================================================================================" << endl;
	cout << "|                                           MAIN MENU                                               |" << endl;
	cout << "=====================================================================================================" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "Select which to form to enter" << right << setw(29) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "1 - Form 1" << right << setw(29) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "2 - Form 2" << right << setw(29) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "3 - Form 3" << right << setw(29) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "4 - Form 4" << right << setw(29) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "5 - Form 5" << right << setw(29) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(40) << "0 - Exit" << right << setw(29) << "|" << endl;
	cout << "|" << setw(100) << "|" << endl;
	cout << "|\t\t\t\t" << left << setw(30) << "Please enter 0/1/2/3/4/5 to choose." << right << setw(34) << "|" << endl;
	cout << "=====================================================================================================" << endl << endl;
}

int formSelection() {
	displayMainMenu();
	int select;
	do {
		cout << "Your choice: ";
		cin >> select;
		if (select < 0 || select > 5)
			cout << "Invalid choice";
	} while (select < 0 || select > 5);
	return select;
}

//FORM 4
int* getNameF4(int c_F4) {
	static int n_F4[1000];
	ofstream writeFile("studentDataF4.txt", ios::out | ios::app);

	for (int a = 0; a < c_F4; a++) {
		cout << "\n*********************" << endl;
		cout << "For Class " << a + 1 << endl;
		//num[a] = numStudent(c);
		cout << "Enter total number of student that want to be entered: ";
		cin >> n_F4[a];
		for (int i = 0; i < n_F4[a]; i++) {
			cin.ignore();
			F4[a].student[i].mark.totalMark = 0;
			cout << endl << "Enter student name: ";
			getline(cin, F4[a].student[i].name);
			cout << "Enter student's IC number: ";
			getline(cin, F4[a].student[i].icNumber);

			cout << "Enter mark for Bahasa Melayu: ";
			cin >> F4[a].student[i].mark.bahasa;
			cout << "Enter mark for English: ";
			cin >> F4[a].student[i].mark.english;
			cout << "Enter mark for History: ";
			cin >> F4[a].student[i].mark.history;
			cout << "Enter mark for Mathematics: ";
			cin >> F4[a].student[i].mark.math;
			cout << "Enter mark for Additional Mathematics: ";
			cin >> F4[a].student[i].mark.addMath;
			cout << "Enter mark for Biology: ";
			cin >> F4[a].student[i].mark.biology;
			cout << "Enter mark for Chemistry: ";
			cin >> F4[a].student[i].mark.chemistry;
			cout << "Enter mark for Physics: ";
			cin >> F4[a].student[i].mark.physics;

			writeFile
				<< F4[a].student[i].name << endl
				<< F4[a].student[i].icNumber << endl
				<< F4[a].student[i].mark.bahasa << endl
				<< F4[a].student[i].mark.english << endl
				<< F4[a].student[i].mark.history << endl
				<< F4[a].student[i].mark.math << endl
				<< F4[a].student[i].mark.addMath << endl
				<< F4[a].student[i].mark.biology << endl
				<< F4[a].student[i].mark.chemistry << endl
				<< F4[a].student[i].mark.physics << endl;
		}
	}
	writeFile.close();
	return n_F4;
}
void mergeDataF4(int a, int n_F4[], int &i) {

	for (int k = 0; k < n_F4[a]; k++)
	{
		form4[i].name = F4[a].student[k].name;
		form4[i].ic = F4[a].student[k].icNumber;
		form4[i].totalM = F4[a].student[k].mark.totalMark;
		form4[i].avg = F4[a].student[k].averageMark;
		i++;
	}
}
// FORM 3
int* getNameF3(int c_F3) {
	static int n_F3[1000];
	ofstream writeFile("studentDataF3.txt", ios::out | ios::app);

	for (int a = 0; a < c_F3; a++) {
		cout << "\n*********************" << endl;
		cout << "For Class " << a + 1 << endl;
		//num[a] = numStudent(c);
		cout << "Enter total number of student that want to be entered: ";
		cin >> n_F3[a];
		for (int i = 0; i < n_F3[a]; i++) {
			cin.ignore();
			F3[a].student[i].mark.totalMark = 0;
			cout << endl << "Enter student name: ";
			getline(cin, F3[a].student[i].name);
			cout << "Enter student's IC number: ";
			getline(cin, F3[a].student[i].icNumber);

			cout << "Enter mark for Bahasa Melayu: ";
			cin >> F3[a].student[i].mark.bahasa;
			cout << "Enter mark for English: ";
			cin >> F3[a].student[i].mark.english;
			cout << "Enter mark for History: ";
			cin >> F3[a].student[i].mark.history;
			cout << "Enter mark for Mathematics: ";
			cin >> F3[a].student[i].mark.math;
			cout << "Enter mark for Science: ";
			cin >> F3[a].student[i].mark.science;
			cout << "Enter mark for Geography: ";
			cin >> F3[a].student[i].mark.geography;
			cout << endl;

			writeFile
				<< F3[a].student[i].name << endl
				<< F3[a].student[i].icNumber << endl
				<< F3[a].student[i].mark.bahasa << endl
				<< F3[a].student[i].mark.english << endl
				<< F3[a].student[i].mark.history << endl
				<< F3[a].student[i].mark.math << endl
				<< F3[a].student[i].mark.science << endl
				<< F3[a].student[i].mark.geography << endl;
		}
	}
	cout << endl;
	writeFile.close();
	return n_F3;
}

void mergeDataF3(int a, int n_F3[], int &i) {
	for (int k = 0; k < n_F3[a]; k++)
	{
		form3[i].name = F3[a].student[k].name;
		form3[i].ic = F3[a].student[k].icNumber;
		form3[i].totalM = F3[a].student[k].mark.totalMark;
		form3[i].avg = F3[a].student[k].averageMark;
		i++;
	}
}

int* getNameF2(int c_F2) {
	static int n_F2[1000];
	//ofstream writeFile("studentDataF3.txt", ios::out | ios::app);

	for (int a = 0; a < c_F2; a++) {
		cout << "\n*********************" << endl;
		cout << "For Class " << a + 1 << endl;
		cout << "Enter total number of student that want to be entered: ";
		cin >> n_F2[a];
		for (int i = 0; i < n_F2[a]; i++) {
			cin.ignore();
			F2[a].student[i].mark.totalMark = 0;
			cout << endl << "Enter student name: ";
			getline(cin, F2[a].student[i].name);
			cout << "Enter student's IC number: ";
			getline(cin, F2[a].student[i].icNumber);

			cout << "Enter mark for Bahasa Melayu: ";
			cin >> F2[a].student[i].mark.bahasa;
			cout << "Enter mark for English: ";
			cin >> F2[a].student[i].mark.english;
			cout << "Enter mark for History: ";
			cin >> F2[a].student[i].mark.history;
			cout << "Enter mark for Mathematics: ";
			cin >> F2[a].student[i].mark.math;
			cout << "Enter mark for Science: ";
			cin >> F2[a].student[i].mark.science;
			cout << "Enter mark for Geography: ";
			cin >> F2[a].student[i].mark.geography;
			cout << endl;

	/*		writeFile
				<< F3[a].student[i].name << endl
				<< F3[a].student[i].icNumber << endl
				<< F3[a].student[i].mark.bahasa << endl
				<< F3[a].student[i].mark.english << endl
				<< F3[a].student[i].mark.history << endl
				<< F3[a].student[i].mark.math << endl
				<< F3[a].student[i].mark.science << endl
				<< F3[a].student[i].mark.geography << endl;
		*/
		}
	}
	cout << endl;
	//writeFile.close();
	return n_F2;
}

void mergeDataF2(int a, int n_F3[], int &i) {
	for (int k = 0; k < n_F3[a]; k++)
	{
		form2[i].name = F2[a].student[k].name;
		form2[i].ic = F2[a].student[k].icNumber;
		form2[i].totalM = F2[a].student[k].mark.totalMark;
		form2[i].avg = F2[a].student[k].averageMark;
		i++;
	}
}
int* getNameF1(int c_F1) {
	static int n_F1[1000];
	//ofstream writeFile("studentDataF3.txt", ios::out | ios::app);

	for (int a = 0; a < c_F1; a++) {
		cout << "\n*********************" << endl;
		cout << "For Class " << a + 1 << endl;
		cout << "Enter total number of student that want to be entered: ";
		cin >> n_F1[a];
		for (int i = 0; i < n_F1[a]; i++) {
			cin.ignore();
			F1[a].student[i].mark.totalMark = 0;
			cout << endl << "Enter student name: ";
			getline(cin, F1[a].student[i].name);
			cout << "Enter student's IC number: ";
			getline(cin, F1[a].student[i].icNumber);

			cout << "Enter mark for Bahasa Melayu: ";
			cin >> F1[a].student[i].mark.bahasa;
			cout << "Enter mark for English: ";
			cin >> F1[a].student[i].mark.english;
			cout << "Enter mark for History: ";
			cin >> F1[a].student[i].mark.history;
			cout << "Enter mark for Mathematics: ";
			cin >> F1[a].student[i].mark.math;
			cout << "Enter mark for Science: ";
			cin >> F1[a].student[i].mark.science;
			cout << "Enter mark for Geography: ";
			cin >> F1[a].student[i].mark.geography;
			cout << endl;

			/*		writeFile
						<< F3[a].student[i].name << endl
						<< F3[a].student[i].icNumber << endl
						<< F3[a].student[i].mark.bahasa << endl
						<< F3[a].student[i].mark.english << endl
						<< F3[a].student[i].mark.history << endl
						<< F3[a].student[i].mark.math << endl
						<< F3[a].student[i].mark.science << endl
						<< F3[a].student[i].mark.geography << endl;
				*/
		}
	}
	cout << endl;
	//writeFile.close();
	return n_F1;
}

void mergeDataF1(int a, int n_F3[], int &i) {
	for (int k = 0; k < n_F3[a]; k++)
	{
		form1[i].name = F1[a].student[k].name;
		form1[i].ic = F1[a].student[k].icNumber;
		form1[i].totalM = F1[a].student[k].mark.totalMark;
		form1[i].avg = F1[a].student[k].averageMark;
		i++;
	}
}

Participant calculateAverageMarkLower(int n[], int c, int form) {
	Participant averageL;

	if (form == 3) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F3[a].student[i].mark.totalMark =
					+F3[a].student[i].mark.bahasa
					+ F3[a].student[i].mark.english
					+ F3[a].student[i].mark.history
					+ F3[a].student[i].mark.math
					+ F3[a].student[i].mark.science
					+ F3[a].student[i].mark.geography;
				F3[a].student[i].averageMark = F3[a].student[i].mark.totalMark / 6;
			}
		}
	}
	else if (form == 2) {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F2[a].student[i].mark.totalMark =
					+ F2[a].student[i].mark.bahasa
					+ F2[a].student[i].mark.english
					+ F2[a].student[i].mark.history
					+ F2[a].student[i].mark.math
					+ F2[a].student[i].mark.science
					+ F2[a].student[i].mark.geography;
				F2[a].student[i].averageMark = F2[a].student[i].mark.totalMark / 6;
			}
		}
	}
	else {
		for (int a = 0; a < c; a++) {
			for (int i = 0; i < n[a]; i++) {
				F1[a].student[i].mark.totalMark =
					+ F1[a].student[i].mark.bahasa
					+ F1[a].student[i].mark.english
					+ F1[a].student[i].mark.history
					+ F1[a].student[i].mark.math
					+ F1[a].student[i].mark.science
					+ F1[a].student[i].mark.geography;
				F1[a].student[i].averageMark = F1[a].student[i].mark.totalMark / 6;
			}
		}
	}
	return averageL;
}

int selectSubjectLower(string subjectL[]) {
	int select;
	cout << "\n=====================================================================================================" << endl;
	cout << "|                              HIGHEST MARK TO LOWEST FOR EACH SUBJECT                              |" << endl;
	cout << "=====================================================================================================" << endl;
	cout << "List of subject:" << endl;
	for (int i = 1; i <= 6; i++) {
		cout << i << ". " << subjectL[i - 1] << endl;
	}
	do {
		cout << "\nSelect subject: ";
		cin >> select;
		if (select < 1 || select > 6)
			cout << "Invalid choice. Try again.\n";
	} while (select < 1 || select > 6);
	return select - 1;
}