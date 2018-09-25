﻿// myDateProject.cpp : Defines the entry point for the console application.
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
	// Testing null constructor and display method
	myDate myDate;
	cout << "Testing display with null constructor: ";
	myDate.display();
	cout << endl << endl;

	// Testing if pass by reference works and changes value stored at address of...
	int jdResult = Greg2Julian(1970, 3, 1);
	cout << "The JD result is " << jdResult << endl;
	int month = myDate.getMonth();
	int day = myDate.getDay();
	int year = myDate.getYear();
	cout << "Initially the month, day, year = " << month << ", " << day << ", " << year << endl;
	Julian2Greg(jdResult, month, day, year);
	cout << "The newly assigned month, day, and year = " << month << ", " << day << ", " << year << endl;
	cout << endl;

	// Testing to see if date is valid or not. Case 1 not valid. Case 2 valid.
	// Case 1
	cout << "Checking for invalid date" << endl;
	cout << "Value is month = 13, day = 1, year = 1970 " << endl;
	int monthTest = 13;
	int dayTest = 1;
	int yearTest = 1970;
	int jdTestValidity = Greg2Julian(yearTest, monthTest, dayTest);
	Julian2Greg(jdTestValidity, monthTest, dayTest, yearTest);
	cout << monthTest << " " << dayTest << " " << yearTest << endl;
	cout << endl;

	// Case 2
	cout << "Checking for valid date" << endl;
	cout << "Value is month = 12, day = 25, year = 1970 " << endl;
	int monthTest2 = 12;
	int dayTest2 = 25;
	int yearTest2 = 1970;
	int jdTestValidity2 = Greg2Julian(yearTest2, monthTest2, dayTest2);
	Julian2Greg(jdTestValidity2, monthTest2, dayTest2, yearTest2);
	cout << monthTest2 << " " << dayTest2 << " " << yearTest2 << endl;

	return 0;
}

