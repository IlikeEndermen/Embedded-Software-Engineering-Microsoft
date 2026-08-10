#include <iostream>

using namespace std;

class Animal{
protected:
    void printKingdom(){
        cout << "Kingdom Animalia" << endl;
    }    

};

class Dog : public Animal{
protected:
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
        void printInformation() {
            cout << name_ << endl;
            this -> printSpecies();
            this -> printKingdom();
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

    fido.printInformation();

    return 0;
}