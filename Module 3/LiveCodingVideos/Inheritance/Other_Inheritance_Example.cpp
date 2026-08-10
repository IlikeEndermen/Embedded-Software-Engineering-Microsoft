#include <iostream>
#include <string>

using namespace std;

class Dog{
private:
    string name_;
public:

    Dog(string name) : name_(name) {}
    void printSpecies(){
        cout << "Canis Lupus Familiaris" << endl;
    }

};

class Poodle : public Dog{ 
public:

    // We made the Dog constructor with the private name_, meaning that we don't
    // have to define it for the constructor of Dog
    Poodle(string name) : Dog(name) {}

};

int main(){

    Poodle fido{"Dawh"};

    return 0;
}