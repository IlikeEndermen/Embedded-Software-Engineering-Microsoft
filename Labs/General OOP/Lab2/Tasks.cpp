#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Item{
private:
    string name_;
    int damage_;
    int durability_;
    bool alive; // If the durability is bigger than 0

public:
    Item(string name, int damage, int durability){
        name_ = name;
        damage_ = damage;
        durability_ = durability;
        alive = false;
    }

    void use(){
        if (durability_ >= 0){
        durability_ -= name_.length();
        damage_ -= 1;
        }
        else {
            alive = true;
        }
    }

    void repair(){
        durability_ += 10;
        damage_ += 1; 
    }

    void displayItemInfo(){
        cout << "Name of item: " << name_ << '\n';
        cout << "Damage: " << damage_ << '\n';
        cout << "Durability " << durability_ << '\n';
        cout << "Is the item broken?: " << (alive ? "YES" : "NO") << '\n';
        cout << "------------------------" << endl;
    }
};

int main(){

    Item item1("Sword", 10, 100);
    Item item2("Big Fucking Staff", 25, 100);

    item2.displayItemInfo();

    item2.use();
    item2.use();
    item2.use();
    item2.use();
    item2.use();
    item2.use();
    item2.use();

    item2.displayItemInfo();

    return 0;
}