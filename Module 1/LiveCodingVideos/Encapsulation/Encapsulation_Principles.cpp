#include<iostream>

// Think of this analogy when it comes to the restaurant example

// The customer orders food, meaning that they have public access to the restaurant class,
// meaning that order_from_menu() needs to be public to be accessed by outsiders

// Then, in the kitchen, the food is prepared, meaning that the public can't access the process
// of cooking the food, meaning that they can't mess it up.
// That's why make_food() needs to be private, to not be accessed by the public.

// Example 1: Restaurant

class Restaurant{

private:
    void make_food(){

    }

public:
    void order_from_menu(){

    }
};

// Example 2: BankAccount

class BankAccount{
private:

    unsigned int balance;
    std::string account_holder;

public:

    // Getters/Setters
    // Getter only => Read Only
    // Setter only => Write Only
    // Getter + Setter => Read/Write


    // Customer gets the balance, but they can't access the balance variable directly
    // If they could, they could give themselves infinite money, which is something we don't
    // want.
    unsigned int getBalance(){
        return balance;
    }

    std::string getAccountHolder(){
        return account_holder;
    }

    // Read-only accountholder, since we don't have a setter fct.

    // Sets the balance to a given value, just a very easy/generic function to showcase the logic

    void setBalance(unsigned int value){
        balance = value;
    }

    // Setters allow for a lot of things to be done in the class instead of outside of it
    // Thus, making some functionality built into the class, without needing a new custom
    // function.

    void makeWithdrawal(unsigned int value){
        int difference = balance - value;

        if (std::abs(difference) <= 50){
            balance = value;
        }
    }

    void makePayment(){

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

    Restaurant restaurant;

    restaurant.order_from_menu();

    BankAccount account;

    account.setBalance(100);
    
    // non-BankAccount balance gets to access the balance of the BankAccount object, without
    // itself being a BankAccount object.
    auto balance = friendBalance(account);


    return 0;
}