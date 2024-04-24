
#include "University.h"

University::University(string name){
    this->name = name;
}


bool University::addStudent(string name, string number){
    Student* stu = new Student(name, number);
    if (students.add(stu))return true;
    //adding a Student has failed - delete the Student object 
    //to prevent memory leaks
    delete stu;
    return false;
}


void University::print() {
    cout<<name<<endl<<endl;
    cout<<"All students:"<<endl<<endl;
    Student* stu;
    for (int i = 0; i < students.getSize(); ++i){
        students.get(i, &stu);
        stu->print();
    }
}