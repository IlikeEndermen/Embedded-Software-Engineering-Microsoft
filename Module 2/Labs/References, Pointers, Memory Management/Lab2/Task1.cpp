#include<iostream>
#include<string>

struct Node {
    std::string itemName; //Data
    Node* next; // Pointer to the next node
};

void addItem(Node* &head, const std::string &item){
    Node* newNode = new Node{item, head};
    head = newNode;
}

int countNodes(Node* head){
    int count = 0;
    Node* curr = head;

    while(curr != nullptr){
        count ++;
        curr = curr->next;
    }

    return count;
}

class Character{
private:
    int health_;
    int level_;
    int experience;
    Node* inventory;
    std::string name_;

public:
    Character(std::string name, int health, int level) : 
    name_(name), health_(health), level_(level), inventory(nullptr) {}

    // This is made to showcase that a copy is made when making the function parameters
    // without making a reference.
    Character(const Character& other) : 
    name_(other.name_), health_(other.health_), level_(other.level_){
        std::cout << name_ << " Copied. " << std::endl;
    }

    ~Character(){
        Node* curr = inventory;
        while (curr != nullptr){
            Node* toDelete = curr;
            curr = curr->next;
            delete toDelete;
        }
    }

    // Generally not for ints, but for larger data types we do a constant reference
    // Prevents the caller from making changes to the reference.
    // Allows the reference to be provided to the caller, with no extra copies.
    const int& getLevel(){ 
        return level_;
    }

    void levelUp(Character& charRef){
    charRef.experience += 100;
    charRef.level_++;
    }

    void itemPickup(const std::string& item){
        addItem(inventory, item);
    }

    bool removeItem(const std::string& item){
        Node* curr = inventory;
        Node* prev = nullptr;

        while(curr != nullptr){
            if(curr->itemName == item){
                if(prev == nullptr) inventory = curr->next;
                else prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void displayInventory(){
        Node* curr = inventory;

        while(curr != nullptr){
            std::cout << "- Item: " << curr->itemName << " found in inventory!" << std::endl;
            curr = curr->next;
        }
    }

    int* createScoreArray(int initialSize){
        int* scores = new int[initialSize];
        for (int i = 0; i < initialSize; i++){
            scores[i] = 0;
        }
        return scores;
    }

    int* resizeScoreArray(int* oldScores, int oldSize, int newSize){
        if(oldScores == nullptr) return nullptr;
        
        int* newScores = new int[newSize];
        for (int i = 0; i < newSize; i++){
            newScores[i] = (i < oldSize) ? oldScores[i] : 0; // copy old vals, zerofill rest
        }

        delete[] oldScores;
        return newScores;

    }

    void deleteScoreArray(int*& scores){
        if (scores != nullptr){
            delete[] scores;
            scores = nullptr;
        }
    }

};