#include<iostream>
#include<memory>

// Shared pointers are used to manage complex interconnections

class Inventory;

// This code creates a memory leak if the inventory references player, and player references
// inventory, none of the shared pointers ever reach 0 references. They just call 
// eachother in a constant loop

// Player needs to manage an inventory object
class Player{
public:
    std::shared_ptr<Inventory> inventory;
    ~Player(){
        std::cout << "Player destructor called!" << std::endl;
    }
};

// Inventory needs to reference a player object
class Inventory{
public:
    std::shared_ptr<Player> player;
    ~Inventory(){
        std::cout << "Inventory destructor called!" << std::endl;
    }
};

int main(){
    {
        // This code is fine, since they don't circularly call eachother
        auto player = std::make_shared<Player>();
        auto inventory = std::make_shared<Inventory>();
        
        // Circular reference: DON'T DO THIS!!!! Can lead to memory leaks
        // Player uses the shared pointer of the inventory
        player->inventory = inventory;

        // Inventory uses the shared pointer of the player
        inventory->player = player;
        // These resources are never released
    }
}