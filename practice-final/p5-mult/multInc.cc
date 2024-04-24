#include <iostream>
using namespace std;
#include <string>

class Animal{
  public:
    Animal(const string& n):name(n){cout<<"Animal "<<name <<" constructed"<<endl;}
    ~Animal(){cout<<"Animal "<<name <<" destructed"<<endl;}
    string name;
};


class Human: virtual public Animal{
  public:
    Human(const string& name, int num = 2): Animal(name), numArms(num){
      cout<<"Human "<<name<<" constructed"<<endl;
    }
  private:
    int numArms;
};


class Horse: virtual public Animal{
  public:
    Horse(const string& name, int num = 4): Animal(name), numLegs(num){
      cout<<"Horse "<<name<<" constructed"<<endl;
    }
  private:
    int numLegs;
};

class Centaur: public Human, public Horse{
  public:
    Centaur(const string& name): Human(name, 2), Horse(name, 4), Animal(name){}
};





int main()
{

  Centaur phil("Phil");

  cout<<endl<<"Human name: "<<phil.name<<endl;
  cout<<endl<<"Horse name: "<<phil.name<<endl<<endl;

  phil.name = "Mr. Ed";

  cout<<endl<<"Human name: "<<phil.name<<endl;
  cout<<endl<<"Horse name: "<<phil.name<<endl<<endl;
  // cout<<bob.Human::name<<endl;
  // cout<<bob.Horse::name<<endl;

  // bob.Horse::name = "Mr Ed";
  
  // cout<<"Bob's names:"<<endl;
  // cout<<bob.Animal::name<<endl;
  // cout<<bob.Horse::name<<endl;
  
  // cout<<bob.name<<endl;
  // cout<<phil.name<<endl;


  
  return 0;
}
