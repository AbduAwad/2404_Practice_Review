#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
    public:
        Animal(const string& name): name(name){}
        void speak() const {cout << name << " speaks!" << endl;}

    private:
        string name;
};

class Dog: public Animal{
    public:
        Dog(const string& name): Animal(name){}
        void speak() const {cout << "Woof!" << endl;}
};


int main(){
    Dog d("Rover");

    d.speak();
    


    return 0;   
}