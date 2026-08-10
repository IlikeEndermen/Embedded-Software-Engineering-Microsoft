#include <iostream>

class Animal {
public:
    Animal() {
        std::cout << "Animal constructor called" << std::endl;
    }

    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }

    virtual void speak() {
        std::cout << "Animal speaks: generic sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog constructor called" << std::endl;
    }

    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }

    void speak() override {
        std::cout << "Dog speaks: Woof!" << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Dog object ---" << std::endl;
    Dog myDog;

    std::cout << "--- Calling speak() ---" << std::endl;
    myDog.speak();

    std::cout << "--- End of scope, destruction begins ---" << std::endl;
    return 0;
}