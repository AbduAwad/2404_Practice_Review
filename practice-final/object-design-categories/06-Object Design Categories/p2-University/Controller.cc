
#include "Controller.h"
#include "University.h"
#include "View.h"



void Controller::launch(){

    uni = new University("Carleton");
    view = new View;
    int choice = -1;
    
    while (choice != 0){
        view->mainMenu(choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        
        case 2:
            uni->print();
            break;
        }
    }

    delete view;
    delete uni;

}

void Controller::addStudent(){
    string name, number;
    view->getStudentInfo(name, number);
    uni->addStudent(name, number);
}
		
