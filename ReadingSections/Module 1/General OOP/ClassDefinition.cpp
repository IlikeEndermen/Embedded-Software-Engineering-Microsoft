#include<iostream>
#include<string>

class Student{
public:
    
    // Data Members: Attributes that store values
    std::string name; // Holds the name of student
    int age; // Age of student

    // Member functions: Functions that use the data that was introduced already
    void introduce(){ // Student introduces themselves
        std::cout << "Hello, my name is " << name << " and I am " << age << " years old." << '\n';
    }

};


// I guess it's the same as struct like before
union Data {
    int integer;
    float decimal;
    char character;
};

int main(){
    Student student1;

    student1.name = "A";
    student1.age = 100;

    student1.introduce();

    Data data;

    data.integer = 42;
    data.decimal = 15.334;
    
    std::cout << data.integer << '\n';
    std::cout << data.decimal << '\n';

    return 0;
}