#include<iostream>
#include<string>
#include<memory>

using namespace std;

// super classes should always have a virtual destructor when running poly code
// resources get released correctly
class GameCharacter{
private:
    const string name_;

public:
    GameCharacter(string name) : name_(name) {}
    
    string getName(){
        return name_;
    }

    // CRITICAL!!! to include
    virtual ~GameCharacter() = default;


    // At runtime, we decide which version of specialAbility we run
    virtual void specialAbility(GameCharacter& target){
        cout << name_ << " prepares for battle!" << endl;
    }
};

class Knight : public GameCharacter{
public:
    Knight(string name) : GameCharacter(name) {}
    
    // We override the virtual function from the base class
    // We also make it virtual, to allow for subclasses of knight to have their
    // own versions of the special ability, like protecting from fire damage, or magic damage
    // etc.

    // override ensures that we get the correct/expected behaviour
    virtual void specialAbility(GameCharacter& target) override{
        cout << getName() << " defends " << target.getName() << "!" << endl;
    }
};

class Dragon : public GameCharacter{
public:
    Dragon(string name) : GameCharacter(name) {}

    virtual void specialAbility(GameCharacter& target) override{
        cout << getName() << " breathes fire at " << target.getName() << "!" << endl;
    }
};

class Wizard : public GameCharacter{
public:
    Wizard(string name) : GameCharacter(name) {}    

    virtual void specialAbility(GameCharacter& target) override{
        cout << getName() << " casts a spell at " << target.getName() << "!" << endl;
    }

    // Now, we want one of the classes to have their own method
    // Wizard specifc method be like:
    void readScroll(){
        cout << getName() << " reads a magic scroll." << endl;
    }

};

int main(){
    
    std::unique_ptr<GameCharacter> character[3] = {
        std::make_unique<Knight>("Knight"),
        std::make_unique<Wizard>("Wizard"),
        std::make_unique<Dragon>("Dragon")
    };

    character[2]->specialAbility(*character[1]);
    character[0]->specialAbility(*character[1]);
    character[1]->specialAbility(*character[2]);

    // output:
    // With no overriding

    // This is the base functionality of the program, it's cool
    // Dragon prepares for battle!
    // Knight prepares for battle!
    // Wizard prepares for battle!

    // With knight special ability override
    // Dragon prepares for battle!
    // Knight defends Wizard!
    // Wizard prepares for battle!

    // With all special abilities overridden
    // Dragon breathes fire at Wizard!
    // Knight defends Wizard!
    // Wizard casts a spell at Dragon!


    // This doesn't work because the vector is of GameCharacter, not Wizard
    // character[1]->readScroll();

    // Solution to the code above
    // Add dynamic_cast to allow the GameCharacter to use code from the Wizard class

    GameCharacter* possible_wizard = character[1].get(); // unique_ptr -> standard pointer
    // called possible_wizard because we assume it's a wizard, not 100% certain it is a wizard
    // Turns this mf into a wizard to call readScroll
    dynamic_cast<Wizard*>(possible_wizard)->readScroll();
    Wizard* wizard = dynamic_cast<Wizard*>(possible_wizard);

    // Example where we fuckup a possible wizard
    GameCharacter* possible_wizard1 = character[0].get(); // it's the knight one
    Wizard* wizard1 = dynamic_cast<Wizard*>(possible_wizard1);

    // Example of dynamic_cast working with references

    GameCharacter& possible_wizard2 = *character[2]; // This throws the bad_cast exception
    dynamic_cast<Wizard&>(possible_wizard2).readScroll();
    
    // This is a check to see if the possible_wizard was converted to a Wizard type
    // If it was, readScroll() runs
    // Else, wizard becomes nullptr because dynamic_cast can't convert it
    if(wizard != nullptr){
        wizard->readScroll();
    }
    if(wizard1 != nullptr){
        wizard1->readScroll();
    } else {
        cout << "This is not a wizard, and wizard1 = nullptr now" << endl;
    }

    return 0;
}