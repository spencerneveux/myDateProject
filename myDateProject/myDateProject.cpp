// myDateProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myDate.h"
#include <string>
#include <iostream>

using namespace std;

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

}

void myDate::increaseDate(int n) {

}

void myDate::decreaseDate(int n) {

}

int myDate::daysBetween(myDate D) {

}

int myDate::getMonth() {
	return month;
}

int myDate::getDay() {
	return day;
}

int myDate::getYear() {
	return year;
}

int myDate::dayOfYear() {
	
}

string myDate::dayName() {

}
