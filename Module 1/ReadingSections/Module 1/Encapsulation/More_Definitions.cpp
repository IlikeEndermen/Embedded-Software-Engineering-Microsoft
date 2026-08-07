#include<iostream>
#include<string>

class Vehicle{

// Protected:
// Less restrictive than private, classes that are derived from this class have access to
// the data that is stored under protected. If Car was a subclass of Vehicle, it could get
// access to the licensePlate data.

protected:
    std::string licensePlate;
};


class Car{

// Private:
// Most restrictions, only members/functions in the same class can use the data that is stored
// under the private tag.

private:
    int fuelLevel;

// Public:
// The content that is labeled under public can be accessed by anywhere in the code, so all
// of the code that is outside of the class can use what's inside of the public domain.

public:
    void startEngine(){
        std::cout << "Engine started!" << '\n';
    }

};