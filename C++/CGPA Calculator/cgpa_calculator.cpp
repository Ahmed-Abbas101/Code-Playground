#include<iostream>
using namespace std;

void inputCourseDetails(int& courses, double*& grade, int*& crdt);
double* calculateGradePoints(int courses, double*& g, int*& c);
double calculateGPA(int courses, double* gradePoints, int* crdt);
void displayCourses(int courses, double* grade, int* crdt);

int main() {
	int courses;
	cout << "Enter the number of courses enrolled this semester: ";
	cin >> courses;

	int* crdt = new int[courses];
	double* grade = new double[courses];
	double gpa, cgpa;

	inputCourseDetails(courses, grade, crdt);
	double* gradepts = calculateGradePoints(courses, grade, crdt);
	gpa = calculateGPA(courses, gradepts, crdt);

	double previousCgpa, prevCreditHrs;
	cout << "Enter previous CGPA: ";
	cin >> previousCgpa;
	cout << "Enter total credit hours completed before this semester: ";
	cin >> prevCreditHrs;

	int currentCredits = 0;
	for (int i = 0; i < courses; i++) {
		currentCredits += *(crdt + i);
	}

	cgpa = ((previousCgpa * prevCreditHrs) + (gpa * currentCredits)) / (prevCreditHrs + currentCredits);

	displayCourses(courses, grade, crdt);
	cout << "GPA for the semester: " << gpa << endl;
	cout << "Updated CGPA: " << cgpa << endl;

	delete[] crdt;
	delete[] grade;
	delete[] gradepts;

	return 0;
}


void inputCourseDetails(int& courses, double*& grade, int*& crdt) {
	for (int i = 0; i < courses; i++) {
		cout << "Enter the grade for Course " << i + 1 << ": ";
		cin >> *(grade + i);
		cout << "Enter the credit hours for Course " << i + 1 << ": ";
		cin >> *(crdt + i);
	}
}

double* calculateGradePoints(int courses, double*& g, int*& c) {
	double* gradePoints = new double[courses];
	for (int i = 0; i < courses; i++) {
		*(gradePoints + i) = (*(g + i)) * (*(c + i));
	}
	return gradePoints;
}

double calculateGPA(int courses, double* gradePoints, int* crdt) {
	double totalGradePoints = 0;
	double totalCredits = 0;
	for (int i = 0; i < courses; i++) {
		totalGradePoints += *(gradePoints + i);
		totalCredits += *(crdt + i);
	}
	return totalGradePoints / totalCredits;
}

void displayCourses(int courses, double* grade, int* crdt) {
	cout << "\t\t--Displaying All Courses--\n";
	for (int i = 0; i < courses; i++) {
		cout << "Course " << i + 1 << ":\n";
		cout << "Grade: " << *(grade + i) << endl;
		cout << "Credit Hours: " << *(crdt + i) << endl;
		cout << endl;
	}
}
