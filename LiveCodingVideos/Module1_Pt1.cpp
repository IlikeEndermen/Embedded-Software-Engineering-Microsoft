#include<iostream>
#include<string>
using namespace std;

// Making a "Game" with C++ to get used to the syntax of C++ and basic OOP bullshit

// A way of solving the issue and create an object is to use struct in C++
// We keep all values specific to a Character in 1 place

// struct Character{
//     int health;
//     string name;
//     int level;
// };

// By using the struct, we can't control when and where we can modify a value of the object


// So, we switch the struct to a class, to be able to ensure that for an object in class Character
// the Character behaves in a way that is intended by us, so we write functions in classes,
// since structures can't have functions inside of themselves.

// class can also be made into a different file
class Character{
private: // class specific data, can't be used outside
    int health_; // We add '_' to differentiate between the parameters of the fct, and the actual values
    string name_;
    int level_;

    // The function then turns into this, and needs to be used inside the class
public: // This allows the function to be used outside the class

    
    // This is a constructor, it is a class that is mandatory, because it allows an object of
    // class knight to be created, and for it to not use the private information directly
    Character(int health, string name, int level){
        health_ = health;
        name_ = name;
        level_ = level;
    }

    void displayCharacterInfo(){
    cout << "Character: " << name_ << '\n';
    cout << "Health: " << health_ << '\n';
    cout << "Level: " << level_ << '\n';
    }

    void takeDamage(int damage){
        health_ -= damage;
        cout << name_ << " takes " << damage << " damage! " << '\n';
    }
    
};

// Generic function for character info with health, name, level of char
/*
void displayCharacterInfo(int health, string name, int level){
    cout << "Character: " << name << '\n';
    cout << "Health: " << health << '\n';
    cout << "Level: " << level << '\n';
}
*/

int main(){
    Character knight(100, "Bitch", 1);
    Character wizard(80, "Faggot", 10);

    knight.displayCharacterInfo();
    wizard.displayCharacterInfo();

    wizard.takeDamage(10);

    wizard.displayCharacterInfo();

    return 0;
}