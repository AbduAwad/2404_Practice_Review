#include <iostream>
using namespace std;
#include <string>

class Animal
{
  public:
    Animal(const string& n) : name(n) { cout<<"In animal ctor: "<<name<<endl; }
    string name;
};

class Human: virtual public Animal
{
  public:
    Human(const string& n, int numArms) : Animal(n), numArms(numArms) { 
      cout<<"In human ctor: "<<name<<endl; }

  private:
    int numArms;
};


class Horse: virtual public Animal
{
  public:
    Horse(const string& n, int numLegs) : Animal(n), numLegs(numLegs) { 
      cout<<"In horse ctor: "<<name<<endl; }

  private:
    int numLegs;
};

class Centaur: public Human, public Horse{
  public:
   Centaur(const string& n, int numArms,int numLegs):
    Human(n,numArms), Horse(n, numLegs), Animal(n){

  }
};





int main()
{
  // Centaur bane(2, 4, "Bane");

  // Human bob("Bob", 2);
  // Horse stan("Stan", 4);

  // cout<<"Human named "<<bob.name<<endl;
  // cout<<"Horse named "<<stan.name<<endl;

  Centaur steve("Steve", 2, 4);

  steve.Horse::name = "Ed";

  cout<<"Centaur's human name: "<<steve.name<<endl;
  cout<<"Centaur's horse name: "<<steve.Animal::name<<endl;



  return 0;
}
