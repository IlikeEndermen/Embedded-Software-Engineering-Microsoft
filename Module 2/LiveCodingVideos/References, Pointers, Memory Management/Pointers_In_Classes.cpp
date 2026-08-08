#include<iostream>
#include<string>

class Character{
private:
    int health_;
    int level_;

public:
    Character(std::string name, int health, int level) : 
    name_(name), health_(health), level_(level) {}

    // This is made to showcase that a copy is made when making the function parameters
    // without making a reference.
    Character(const Character& other) : 
    name_(other.name_), health_(other.health_), level_(other.level_){
        std::cout << name_ << " Copied. " << std::endl;
    }

    const std::string name_;

    // Generally not for ints, but for larger data types we do a constant reference
    // Prevents the caller from making changes to the reference.
    // Allows the reference to be provided to the caller, with no extra copies.
    const int& getLevel(){ 
        return level_;
    }
};

void printCharacterLevelWithoutReference(Character character){
    std::cout << character.name_ << ": Level " << character.getLevel() << std::endl;
}

void printCharacterLevelWithReference(Character& character){
    std::cout << character.name_ << ": Level " << character.getLevel() << std::endl;
}

void printCharacterLevelWithPointers(Character* character){
    std::cout << character->name_ << ": Level " << character->getLevel() << std::endl;
}

int main() {
    
    Character knight("Bitch", 25, 1); // local var, lives in local memory

    Character* wizard;
    {
        // Character knight("Bitch2", 25, 1); // Not in same scope as the fcts
        // Its memory information can't be used

        // Dynamic allocation of the memory using the pointer outside, then specifying it
        // in this new scope. Not too hard.
        wizard = new Character{"Bitch2", 25, 1};
    }
    printCharacterLevelWithPointers(wizard);

    delete wizard;
    wizard = nullptr;


    // We make a copy of the
    // character whenever we call a function without a reference in its parameter.
    // That is why we make a reference in the parameter.
    // The more in depth the class is, the worse the circumstances.
    

    std::cout << "\n======= Printing without reference =======" << std::endl;
    printCharacterLevelWithoutReference(knight); 
    std::cout << "\n======= Printing with reference =======" << std::endl;
    printCharacterLevelWithReference(knight); 
    std::cout << "\n======= Printing with pointers =======" << std::endl;
    printCharacterLevelWithPointers(&knight); 
    

    return 0;
}
