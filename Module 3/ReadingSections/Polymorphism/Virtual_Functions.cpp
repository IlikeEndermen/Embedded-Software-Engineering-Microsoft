#include<iostream>

using namespace std;

// Virtual Functions
// Member function declared with virtual in front in a *base class*
// Allows for it to be overwritten in derived classes. The following declaration allows
// for late binding, the function that gets executed is determined during runtime
// instead of compile time.

class Shape{
public:

    // virtual draw function
    virtual void draw() const {
        cout << "Drawing a shape!" << endl;
    }
};

class Circle : public Shape{

    // Circle overrides the virtual draw function completely
    void draw() const override{
        cout << "Drawing a circle!" << endl;
    }
};

// At runtime, the program decides which version of draw() to execute based
// on the object's type.


int main(){
// Dynamic Binding
// The function to be called at runtime based on actual object type
// rather than typoe of the reference/pointer

Shape* shapes[2];
shapes[0] = new Shape();
shapes[1] = new Circle();
for (int i = 0; i < 2; ++i) {
    shapes[i]->draw(); 
    // first, the shape draw is called and run
    // 1. Drawing a shape!
    // second, the circle draw is called and run
    // 2. Drawing a circle!
}

}