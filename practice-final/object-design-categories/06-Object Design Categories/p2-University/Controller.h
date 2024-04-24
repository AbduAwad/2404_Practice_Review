#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>

class View;
class University;

using namespace std;

class Controller {
		
	public:
			
		void launch();
	
	private:

		void addStudent();

		View* view;
		University* uni;
	
};
#endif