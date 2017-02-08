// Node.h file from Harish

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <map>

#include "string.h"
#include "student.h"

using namespace std;

class Node {
    
    public:
        Node(Student*); // Constructor
        ~Node(); // Deconstructor
        
        Node* getNext();
        Student* getStudent();
        void setNext(Node*);
    
    protected:
        Student* student;
        Node* node;
    
};

#endif
