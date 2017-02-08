// student.cpp
// Implementation for Student class

#include "student.h"
#include "string.h"

Student::Student(char* name, int year){
	strcpy(fullName,name);
	gradYear = year;
};

char* Student::getFirst(){
	return first;
}

char* Student::getLast(){
	return last;
};

int Student::getId(){
	return id;
};

float Student::getGpa(){
	return gpa;
};
