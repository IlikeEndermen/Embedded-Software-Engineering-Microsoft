#include<iostream>

class GameCharacter{
private:
    int health_;
    int max_health_;

public:
    GameCharacter(int health) : health_(health), max_health_(health) {}
    void printInfo(){
        std::cout << "Health: " << health_ << "/" << max_health_ << std::endl;
    }

};

class Knight : public GameCharacter{
    int strength_;
public:
    Knight(int health, int strength) : GameCharacter(health), strength_(strength) {}

    // Print info was overwritten for this class
    void printInfo(){

        // print the knight's health/max_health
        GameCharacter::printInfo();

        std::cout << "Strength: " << strength_ << std::endl;
    }

};

int main(){

    Knight hero(100, 10);
    hero.printInfo();

    return 0;
}