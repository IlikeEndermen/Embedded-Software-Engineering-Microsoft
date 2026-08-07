// The constructors are essential to creating objects without using the data inside of the class
// directly, but making a reference to it. There are 3 main types, apparently

#include<iostream>
#include<string>

class Instrument{

private:
    std::string name;
    int volume;

public:
    // 1. Default Constructors
    // Initiates objects without any specific data, just an object with nothing inside

    Instrument() { // More to see if the class works or smth, idk why you'd use this
        std::cout << "Instrument created!" << '\n';
    }

    // 2. Parametrized Constructors
    // Has the value parameters inside to be able to create an object with data inside of it
    // Allows for personalization.

    Instrument(std::string name, int volume) : name(name), volume(volume) {
        std::cout << "Instrument " << name << " created with volume " << volume << '\n';
    }

    // It's the same logic as the following, which I personally prefer
    
    /*Instrument(std::string name, int volume){
        name_ = name; // Different names are given to the private values of the class
        volume_ = volume;
        std::cout << "Instrument " << name << " created with volume " << volume << '\n';
    }*/

    // 3. Copy Constructors
    // Mimics existing objects, the new instance keeps the original's state integrity
    // It allows me to make an exact copy of an object, without modifying the original's 
    // data. It references the source object with &other, and const ensures the constructor
    // won't modify the original object.

    // Example:
    // Instrument instrument1("Sax", 50);
    // Instrument instrument1_copy(instrument1);

    Instrument(const Instrument &other) : name(other.name), volume(other.volume) {
        std::cout << "Instrument " << name << " copied!" << '\n';
    }

    // 4. Deconstructor
    // Frees the resources that the object is using
    // Crucial for resource intensive apps, to ensure that resources are used efficiently
    // Use the logic from OS, the deconstructor reallocates the memory that was used by
    // that object to any new objects that are created.

    ~Instrument(){
        std::cout << "Instrument destroyed!" << '\n';
    }

    // The deconstructor is not called specifically, it gets called for objects that are
    // no longer being used. For example

    /*
    void run(){
        Instrument instrument1;
        Instrument instrument2;
    } // instrument2's deconstructor runs first, then instrument1's
     */
};