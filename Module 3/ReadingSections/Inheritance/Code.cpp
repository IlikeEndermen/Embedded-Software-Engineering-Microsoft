#include<iostream>

// Inheritance creates a natural classification system
// Derived classes inherit properties + behaviors of base classes
// Simplifies code reuse + organization

class Base{
public:
    void show(){
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show(){
        std::cout << "Derived class show function" << std::endl;
    }
};

// Derived inherits Base. Derived overrides the show functions, so we can tailor inherited
// functionality to specific needs. 
// Overriding allows for *Polymorphism*.

// If we make a Base object, and we do obj.show() => outputs "Base class show function."
// If we make a Derived object, and we do obj.show() => outputs "Derived class show function."
// Same function, different outcomes

// Inheritance specifiers:

// Public inheritance:
// Maintains public + protected member's visibility as public + protected in the 
// derived class

// Protected inheritance:
// Converts public + protected members of base class into protected members in the
// derived class

// Private inheritance:
// Demotes public and protected members of base class to private access in the 
// derived class

// Definition:
// The public show of Base becomes private for Derived,
// meaning for future classes that inherit derived, they can't use show from Base


// Order of execution:

// 1. Base Class Constructor
// 2. Derived Class Constructor

// 1. Derived Class Destructor
// 2. Base Class Destructor


class Base {
public:
    Base() { std::cout << "Base Constructor" << std::endl; }
    ~Base() { std::cout << "Base Destructor" << std::endl; }
};
class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor" << std::endl; }
    ~Derived() { std::cout << "Derived Destructor" << std::endl; }
};