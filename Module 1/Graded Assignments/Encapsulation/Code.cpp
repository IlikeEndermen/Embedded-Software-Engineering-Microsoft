#include <iostream>

class BankAccount {
private:
    int balance; // private: cannot be accessed directly from outside the class

public:
    // Constructor to initialize balance safely
    BankAccount(int initialBalance = 0) {
        if (initialBalance < 0) {
            balance = 0;
        } else {
            balance = initialBalance;
        }
    }

    // Getter: read-only access to balance
    int getBalance() const {
        return balance;
    }

    // Setter: validates before modifying balance
    bool setBalance(int newBalance) {
        if (newBalance < 0) {
            std::cerr << "Error: Balance cannot be negative.\n";
            return false; // reject invalid change
        }
        balance = newBalance;
        return true;
    }

    // Convenience methods for gameplay actions
    bool deposit(int amount) {
        if (amount < 0) {
            std::cerr << "Error: Cannot deposit a negative amount.\n";
            return false;
        }
        balance += amount;
        return true;
    }

    bool spend(int amount) {
        if (amount < 0 || amount > balance) {
            std::cerr << "Error: Invalid or insufficient gold to spend.\n";
            return false;
        }
        balance -= amount;
        return true;
    }
};

int main() {
    BankAccount playerGold(100);

    playerGold.deposit(50);          // balance -> 150
    playerGold.spend(30);            // balance -> 120
    playerGold.setBalance(-20);      // rejected, balance stays 120
    std::cout << "Current gold: " << playerGold.getBalance() << "\n";

    return 0;
}