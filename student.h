// student.h
// Student class that holds a name and a graduation year

class Student{
	private:
		char first[20];
		char last[20];
		int id;
		float gpa;
	public:
		Student(char*, char*, int, float);
		char* getFirst();
		char* getLast();
		int getId();
		float getGpa();
};
