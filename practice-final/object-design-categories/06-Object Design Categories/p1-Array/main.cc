#include <iostream>
using namespace std;

#include "List.h"
#include "Student.h"


int main()
{
  List list;
  Student* s;

  s = new Student("Zeek","1", 10.1);
  
  list.add(s);

  s = new Student("Cindy","2", 12);
  list.add(s);

  s = new Student("Bob","3",5);
  list.add(s);

  s = new Student("Alice","4",6);
  list.add(s);

   s = new Student("Zzzzz","5",11);
  list.add(s);

  list.print();

  cout<<"Getting student Cindy..."<<endl;
  
  Student* cindy;
  list.get("Cindy", &cindy);

  cout<<"Printing Cindy: "<<endl;

  cindy->print();

  list.print();
  cout<<"Removing Cindy: "<<endl;


  list.remove("Cindy", &cindy);
  list.print();
  
  cout<<"Deleting Cindy"<<endl;
  delete cindy;

  

  List* hr = new List;
  cout<<"Return students on the honour roll"<<endl;
  list.getHonourRoll(*hr);

  cout<<"Print students on the honour roll"<<endl;

  hr->print();

  cout<<"Deleting honour roll and printing class list:"<<endl;
  delete hr;
  list.print();

  List goners;
  cout << "Remove up to Drake" <<endl;
  list.removeUpTo("Drake", goners);

  cout<<"Printing goners: "<<endl;
  goners.print();
  cout<<"Printing remaining students: "<<endl;
  list.print();

  cout<<"Deleting students:"<<endl;
  for (int i = 0; i < list.getSize(); ++i){
      list.get(i, &s);
      cout<<"Deleting: "<<endl;
      s->print();
      delete s;
  }

  for (int i = 0; i < goners.getSize(); ++i){
      goners.get(i, &s);
      cout<<"Deleting: "<<endl;
      s->print();
      delete s;
  }

  return 0;
}

