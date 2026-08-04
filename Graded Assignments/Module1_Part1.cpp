#include<iostream>
#include<string>
using namespace std;

class Character{
private:
    string name_;
    int health_;

public:
    Character(string name, int health){
        name_ = name;
        health_ = health;
    }

    void displayStatus(){
        cout << "Name of Character: " << name_ << '\n';
        cout << "Health of Character: " << health_ << '\n';
    }
};

int main(){
    Character character1("Alexander", 100);
    Character character2("Bobert", 140);

    character1.displayStatus();
    character2.displayStatus();
    
    return 0;
}