#include<iostream>
#include<typeinfo>
using namespace std;

class Shape {
public:
    virtual void draw() const { /* implementation */ }
    virtual void area() const { /* implementation */ }
};
class Circle : public Shape {
public:
    void draw() const override { /* Circle's implementation */ }
    void area() const override { /* Circle's implementation */ }
};

// RTTI is specific in C++: Enables type determination during program execution.
// Safely executes type-specific operations.



int main(){

    // RTTI typeid example
    // typeid: Retrieves actual type of an object at runtime

    Shape* shape = new Circle();
    cout << typeid(*shape).name() << endl; // Output: Circle

    // dynamic_cast:
    // Safely casts pointers to derived types, verifying at runtime that the cast is valid

    Circle* circlePtr = dynamic_cast<Circle*>(shape);
    if (circlePtr) {
        circlePtr->draw(); // Call Circle's draw() safely
    }
}