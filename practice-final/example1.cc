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

int main(){
    Animal a("Dog");
    Animal b("Cat");
    Animal c("Cow");
    Animal d("Horse");
    return 0;   
}