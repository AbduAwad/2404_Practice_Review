#ifndef LIST_H
#define LIST_H

#define MAX_ARR 64

#include "Student.h"

class List
{
  public:
    List();
    ~List();

    bool add(Student*);
    bool get(string name, Student**);
    bool get(int index, Student**);
    bool remove(string name, Student**);
    void removeUpTo(string name, List& goners);

    // Add all students on the honour roll to hr.
    // This is why we don't delete - students may be in 
    // more than one List. If we delete automatically,
    // when we delete the honour roll all those students 
    // would be lost.
    void getHonourRoll(List& hr);
    inline int getSize(){return size;}
    void print();
    

  private:
    Student** elements;
    int size;
   
};

#endif

