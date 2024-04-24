#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
    public:
        Animal(const string& name, const string& noise): name(name), noise(noise){}
        void speak() const {cout << name << " says" <<noise<<"!"<< endl;}

    private:
        string name;
        string noise;
};

class BarnYard{
    public:
        BarnYard(const string& name): name(name){}
        

    private:
        string name;
        vector<Animal*> animals;
};




int main(){
    

    BarnYard by("Old MacDonald");

    // by.addAnimal("Dog", "Woof");
    // by.addAnimal("Cat", "Meow");
    // by.addAnimal("Horse", "Neigh");
    // by.addAnimal("Cow", "Moo");

    // by.harmony();



    return 0;   
}