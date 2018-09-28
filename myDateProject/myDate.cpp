//Spencer Neveux
// CECS 282 (Project MyDate)
// September 26, 2018

#include "myDate.h"
#include <string>
#include <iostream>

using namespace std;

int Greg2Julian(int month, int day, int year) {
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
	int jd = Greg2Julian(M, D, Y);
	int m1, d1, y1;
	Julian2Greg(jd, m1, d1, y1);
	if (M == m1 && D == d1 && Y == y1) {
		this->month = M;
		this->day = D;
		this->year = Y;
	}
	else {
		this->month = 5;
		this->day = 11;
		this->year = 1959;
	}
}


void myDate::display() {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << months[month - 1] << " " << day << ", " << year;
}


void myDate::increaseDate(int n) {
	int jd = Greg2Julian(month, day, year);
	jd += n;
	Julian2Greg(jd, month, day, year);
}

void myDate::decreaseDate(int n) {
	int jd = Greg2Julian(month, day, year);
	jd -= n;
	Julian2Greg(jd, month, day, year);
}

int myDate::daysBetween(myDate D) {
	int thisJD = Greg2Julian(month, day, year);
	int thatJD = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
	int difference = thatJD - thisJD;
	return difference;
}

int myDate::dayOfYear() {
	int baseJD = Greg2Julian(1, 1, year);
	int thisJD = Greg2Julian(month, day, year);
	int difference = thisJD - baseJD;
	return difference + 1;
}


string myDate::dayName() {
	string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int jd = Greg2Julian(month, day, year);
	int day = jd % 7;
	string result = days[day + 1];
	return result;
}


int main()
{

	// Testing null constructor
	myDate dNull;
	dNull.display();
	cout << endl;

	// Testing valid Date constructor
	myDate d1(9, 27, 2018);
	d1.display();
	cout << endl;

	// Testing invalid date
	myDate d2(13, 1, 1980);
	d2.display();
	cout << endl;

	// Testing increase date
	myDate d3(9, 26, 2018);
	d3.display();
	cout << endl;
	d3.increaseDate(1); // Testing 1 day increase
	d3.display();
	cout << endl;
	d3.increaseDate(20); // Testing increase to next month
	d3.display();
	cout << endl;

	// Testing decrease date
	myDate d4(12, 26, 2018);
	d4.display();
	cout << endl;
	d4.decreaseDate(1); // Testing single day decrease
	d4.display();
	cout << endl;
	d4.decreaseDate(30); // Testing decrease to previous month
	d4.display();
	cout << endl;

	// Testing daysBetween
	myDate d5(1, 1, 2019);
	myDate d6(2, 1, 2019);
	cout << "The days between are: " << d5.daysBetween(d6) << endl; // testing positive difference

	myDate d7(12, 1, 2018);
	cout << "The days between are: " << d5.daysBetween(d7) << endl; // testing negative difference

	// Testing dayOfYear
	myDate d8(1, 1, 2018);
	cout << "The day of year should equal 1: Result = " << d8.dayOfYear() << endl; // testing jan 1

	myDate d9(2, 1, 2018);
	cout << "The day of year should equal 32: Result = " << d9.dayOfYear() << endl; // testing feb 1

	// Testing dayName
	myDate d10(9, 28, 2018);
	cout << d10.dayName() << endl; // should return friday

	myDate d11(3, 1, 1986);
	cout << d11.dayName() << endl; // should return saturday

	myDate d12(4, 13, 2000);
	cout << d12.dayName() << endl; // should return thursday

	d12.increaseDate(1);
	cout << d12.dayName() << endl; // should return friday

	return 0;
}
