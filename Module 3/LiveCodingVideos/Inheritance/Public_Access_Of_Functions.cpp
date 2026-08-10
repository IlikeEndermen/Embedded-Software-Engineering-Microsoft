#include <iostream>

using namespace std;

class Animal{
public:
    void printKingdom(){
        cout << "Kingdom Animalia" << endl;
    }    

};

class Dog : public Animal{
public:
    void printSpecies(){
        cout << "Canis Lupus Familiaris" << endl;
    }

};


// Poodle has access to:
// printKingdom()
// printSpecies()
// since the Dog class publicly inherits Animal

class Poodle : public Dog{ 
private:
    const string name_;

public:
    Poodle(string name) : name_(name){}
        void printName() {
            cout << name_ << endl;
        }

};

class Beagle : public Dog{
private:
    const string name_;

public:
    Beagle(string name) : name_(name){}
        void printName() {
            cout << name_ << endl;
        }
};

int main(){

    Poodle fido{"Dawh"};
    Beagle spot{"Doggy"};

    fido.printName();
    fido.printSpecies();
    fido.printKingdom();

    return 0;
}