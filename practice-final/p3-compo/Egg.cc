#include "Egg.h"

Egg::Egg(const string& s) : size(s) { cout << "--- Egg ctor" << endl; }

Egg::~Egg() { cout << "--- Egg dtor" << endl; }

string Egg::getSize() const { return size; }