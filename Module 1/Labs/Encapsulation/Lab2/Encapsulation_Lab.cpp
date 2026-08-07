#include<iostream>
#include<string>

// BLAH BLAH BLAH, can't be fucked to do it, but the tasks from the first lab cover this greatly
// I just don't wanna think of all the logic of what I want to add as functionality.


class vulnerableCharacter {
private:
    std::string name;
    int hitPoints;
    int attackStrength;

public:

    std::string getCharacterName(){return name;}
    int getHitPoints(){return hitPoints;}
    int getAttackStrength(){return attackStrength;}

    bool setCharacterName(std::string customName){
        if(customName.length() != 0){
            name = customName;
            return true;
        }
        return false;
    }

    bool setHitPoints(int points){
        if(points > 0){
            hitPoints = points;
            return true;
        }
        return false;
    }

    void displayInfo() {
        std::cout << "Name: " << name << ", HP: " << hitPoints
                  << ", Attack: " << attackStrength << std::endl;
    }
};