#include<iostream>

class Example{
private:
    int data_;

public:
    Example(){
        std::cout << "Constructor Called." << '\n';
    }

    Example(int data){
        data_ = data;
        std::cout << "Parametrized Constructor Called." << '\n';
    }

    Example(const Example &other){
        std::cout << "Copy Constructor Called" << '\n';
    }

    // The copy assignment operator exists in order to allow for
    // an already existing object to copy a different object without calling a constructor
    Example& operator = (const Example& other){
        std::cout << "Copy Assignment Operator Called." << '\n';
        return *this; // pointer to the object for which I am calling the method
    }

    ~Example(){
        std::cout << "Destructor Called" << '\n';
    }

};

int main(){
    {
        Example obj1;
        Example obj2(1);
        Example obj3(2);
        Example obj4 = obj3;

        obj1 = obj2;
    }

    return 0;
}