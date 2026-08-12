// Virtual Tables:
// Lookup tables of function pointers that the compiler makes for each class
// that has virtual functions. So it keeps track of all the virtual functions and their
// pointers

// Each object of a polymorphic class has a hidden pointer vptr that points
// to the class's virtual table

// When a virtual function is called, the following happens:

// 1. Lookup: Program follows the object's vptr to find its vtable
// 2. Index: Uses the index in the vtable to find the correct function pointer
// 3. Call: Invokes the function through the pointer

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


// Shape vtable:
// Index 0: pointer to Shape::draw()
// Index 1: pointer to Shape::area()

// Circle vtable:
// Index 0: pointer to Circle::draw()
// Index 1: pointer to Circle::area()


int main(){
    Shape* shapes[2];
    shapes[0] = new Shape();
    shapes[1] = new Circle();
    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw(); 
}
}

// When we call shapes[i] -> draw(), program goes:
// 1. Follow object's vptr to vtable
// 2. Look up index 0
// 3. Call function pointed at that location

// Virtual Tables add the following overhead
// Memory: Each polymorphic object stores an extra pointer
// Runtime: Each virtual function call needs extra indirection through vtable

