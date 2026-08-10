#include<iostream>
#include<memory>

// Shared pointers are used to manage complex interconnections

// Question: What happens when you access an expired weak_ptr?

// Answer:
// lock() — returns an empty shared_ptr if expired; no crash, no exception.
// Check with if (auto sp = wp.lock()).

// expired() — returns true/false (equivalent to use_count() == 0);
// just a status check, gives no access to the object.

// Direct shared_ptr construction from the weak_ptr — throws std::bad_weak_ptr if expired.

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
    std::weak_ptr<Player> player;
    ~Inventory(){
        std::cout << "Inventory destructor called!" << std::endl;
    }
};

int main(){
    {
        // This code is fine, since they don't circularly call eachother
        auto player = std::make_shared<Player>();
        auto inventory = std::make_shared<Inventory>();
        
        // weak pointers are created from a shared pointer, but doesn't increase the
        // reference count
        std::weak_ptr<Player> converted{player};

        // Circular reference: DON'T DO THIS!!!! Can lead to memory leaks
        // Player uses the shared pointer of the inventory
        player->inventory = inventory;

        // Inventory uses the shared pointer of the player
        inventory->player = converted;
        // Since converted is now a weak pointer, and it's not going to increase the reference
        // counter, we can finally escape with all the resources from the scope and 
        // end the whole program. No more infinite loops + memory leaks.
    }
}