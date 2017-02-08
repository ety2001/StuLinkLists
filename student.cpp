// student.cpp
// Implementation for Student class

#include "student.h"
#include "string.h"

Student::Student(char* fisrt, char* last, int id, float gpa){
	strcpy(this->first,first);
	strcpy(this->last,last);
	this->id = id;
	this->gpa = gpa;
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
