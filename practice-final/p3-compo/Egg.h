#ifndef EGG_H
#define EGG_H

#include <iostream>
#include <string>
using namespace std;

class Egg{
    public:
        Egg(const string& = "mini");
        ~Egg();
        string getSize() const;

    private:
        string size;
};


#endif
