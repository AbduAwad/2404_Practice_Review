
#include "Student.h"

Student::Student(string name, string num, float g){
    this->name = name;
    number = num;
    gpa = g;
}

Student::Student(Student& student){
    name = student.name;
    number = student.number;
    gpa = student.gpa;
}


string Student::getName(){
    return name;
}

bool Student::honourRoll(){
    return gpa >= 10.0f;
}

bool Student::lessThan(Student& stu){
    return name < stu.name;

}

void Student::print(){
    cout<<endl;
    cout<<"Student name  : "<<name<<endl;
    cout<<"Student number: "<<number<<endl<<endl;

}