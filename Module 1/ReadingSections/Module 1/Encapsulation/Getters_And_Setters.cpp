class BankAccount{
private:
    double balance;

public:

    // Getters allow code outside of the class without getting to see any of the private data
    double GetBalance() const {
        return balance;
    }

    // Setters allow outside code to modify values that are private, without getting to touch
    // the actual variable, so they can only work on their own values with a level of abstraction
    // that does not fully divulge how a private variable functions in the code
    double deposit(double amount){
        if (amount > 0){
            balance += amount;
        }
    }

    // Friend functions:
    // Not a class method, they are just included, and can access private data from the class
    // Lets external code bypass normal encapsulation when needed

    // External variables can use the friend function to access the private data of an object
    // of a class, without itself being in the class.

    friend unsigned int friendBalance(const BankAccount& account){
        return account.balance;
    }
};

int main(){

    BankAccount account;

    account.deposit(100);
    
    // non-BankAccount balance gets to access the balance of the BankAccount object, without
    // itself being a BankAccount object.
    auto balance = friendBalance(account);


    return 0;
}