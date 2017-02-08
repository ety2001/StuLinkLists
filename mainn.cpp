// main.cpp
// Test program for creating a linked list with 10 students and their graduation years
// Prints student list in reverse order

//#include "student.h"
#include "node.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;


Node* addRec(Node* studentList, Student* student){
	if(studentList == NULL){
		Node* newStudent = new Node(student);
		newStudent->setNext(NULL);
		return newStudent;
	}
	else if(student->getId() <= studentList->getStudent()->getId()){
		Node* newStudent = new Node(student);
		newStudent->setNext(studentList);
		return newStudent;
	}
	else{
		Node* firstStudent = studentList;
		firstStudent->setNext(addRec(studentList->getNext(), student));
		return firstStudent;
	}
};

Node* add(Node* studentList, char* first, char* last, int id, float gpa){
	Student* student = new Student(first, last, id, gpa);
	return addRec(studentList, student);
};

void printRec(Node* studentList){
	if(studentList!=NULL){
		cout << studentList->getStudent()->getFirst() << " "
			<< studentList->getStudent()->getLast() << ", "
			<< studentList->getStudent()->getId() << ", "
			<< setprecision(2) << fixed
			<< studentList->getStudent()->getGpa() << endl;
		printRec(studentList->getNext());
	}
};

Node* delRec(Node* studentList, int id){
	if(studentList == NULL){
		cout << "No student with ID " << id << endl;
		return studentList;
	}
	else if(studentList->getStudent()->getId() == id){
		Node* firstStudent = studentList;
		studentList = studentList->getNext();
		firstStudent->setNext(NULL);
		delete firstStudent;
		cout << "Student deleted." << endl;
		return studentList;
	}
	else{
		Node* firstStudent = studentList;
		firstStudent->setNext(delRec(studentList->getNext(), id));
		return firstStudent;
	}
};

void average(Node* studentList){
	float sum = 0;
	int count = 0;
	while(studentList!=NULL){
		sum += studentList->getStudent()->getGpa();
		count++;
		studentList = studentList->getNext();
	}
	if(count>0){
		cout << setprecision(2) << fixed << sum/count << endl;
	}
	else{
		cout << 0.00 << endl;
	}
};

int main(){
	Node* studentList = NULL;
	bool go = true;
	while(go == true){
		cout << "What is your command? Enter ADD DELETE PRINT AVERAGE or QUIT"<< endl;
		char input[7];
		cin >> input;
		char first[20];
		char last[20];
		int id;
		float gpa;
		if(input[1] == 'D'){
			cout << "Enter first name" << endl;
			cin >> first;
			cout << "Enter last name" << endl;
			cin >> last;
			cout << "Enter ID" << endl;
			cin >> id;
			cout << "Enter GPA" << endl;
			cin >> gpa;
			studentList = add(studentList, first, last, id, gpa);
			cout << "Student added." << endl;
		}
		if(input[1] == 'E'){
			cout << "Enter ID" << endl;
			cin >> id;
			studentList = delRec(studentList, id);
		}
		else if(input[1] == 'R'){
			printRec(studentList);
		}
		else if(input[1] == 'V'){
			average(studentList);
		}
		else if(input[1] == 'U'){
			go = false;
		}
	}
}
	
