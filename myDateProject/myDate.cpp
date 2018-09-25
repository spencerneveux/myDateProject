// myDateProject.cpp : Defines the entry point for the console application.
//

#include "myDate.h"
#include <string>
#include <iostream>

using namespace std;

int Greg2Julian(int year, int month, int day) {
	int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 
		* (month - 2 - (month - 14) / 12 * 12) / 12 - 3 
		* ((year + 4900 + (month - 14) / 12) / 100) / 4;
	return JD;
}

void Julian2Greg(int JD, int & month, int & day, int & year) {
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

myDate::myDate() {
	this->month = 5;
	this->day = 11;
	this->year = 1959;
}

myDate::myDate(int M, int D, int Y) {
	this->month = M;
	this->day = D;
	this->year = Y;
}


void myDate::display() {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << months[month - 1] << " " << day << ", " << year;
}

/*
void myDate::increaseDate(int n) {

}

void myDate::decreaseDate(int n) {

}

int myDate::daysBetween(myDate D) {

}

int myDate::dayOfYear() {
	
}

string myDate::dayName() {

}

*/

int main()
{
	myDate myDate;
	cout << "Testing display with null constructor: ";
	myDate.display();
	cout << endl;

	int jdResult = Greg2Julian(1970, 3, 1);
	cout << "The JD result is " << jdResult << endl;
	int month = 1;
	int day = 1;
	int year = 1970;
	Julian2Greg(jdResult, month, day, year);
	cout << month << " " << day << ", " << year << endl;
	return 0;
}

