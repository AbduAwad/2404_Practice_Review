#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

class University {
		
	public:
		//constructors
		University(string name);
		
		
		bool addStudent(string name, string number);
		
		void print();
	
	private:
		string name;
		List students;
	
};
#endif