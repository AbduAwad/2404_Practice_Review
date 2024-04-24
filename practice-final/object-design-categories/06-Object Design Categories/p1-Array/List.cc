#include <iostream>
using namespace std;

#include "List.h"

List::List(){
    size = 0;
    elements = new Student*[MAX_ARR];
}

/*
    Usually bad form to delete elements in a list,
    since they may be stored in more than one list.
    However, we can delete the List.
*/
List::~List(){
    delete [] elements;
}

bool List::add(Student* s){
    if (size >= MAX_ARR)return false;

    for (int i = size; i > 0 ; --i){
        if (s->lessThan(*elements[i-1])){
            //keep making space by copying elements
            //one location to the right
            elements[i]=elements[i-1];
        }else{
            //we have found where s should go
            elements[i] = s;
            ++size;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    elements[0] = s;
    ++size;
    return true;
    
}


bool List::get(string name, Student** stu){
    for (int i = 0; i < size; ++i){
        if (name == elements[i]->getName()){
            *stu = elements[i];
            return true;
        }
    }
    return false;
}

bool List::get(int index, Student** stu){
    if (index < 0 || index >= size) return false;
    *stu = elements[index];
    return true;
}

bool List::remove(string name, Student** stu){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (name != elements[index]->getName()&& index < size){
        ++index;
    }

    //did we fall off the end of the List?
    if (index == size) return false;

    //we have found what we wanted to remove,
    //assign the output value
    *stu = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return true;

}

void List::removeUpTo(string name, List& arr){
    //find index of the first Student who comes after name
    int index = 0;

    while (name >= elements[index]->getName()&& index < size){
        //return them to the calling function
        arr.add(elements[index++]);
    }

    //the number of items to remove
    int toRemove = index;
    while(index < size){
        elements[index - toRemove] = elements[index];
        ++index;
    }

    size -= toRemove;
}

void List::getHonourRoll(List& hr){
    for (int i = 0; i < size; ++i){
        if (elements[i]->honourRoll()){
            hr.add(elements[i]);
        }
    }
}

void List::print()
{
  cout << endl << endl << "Students:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}