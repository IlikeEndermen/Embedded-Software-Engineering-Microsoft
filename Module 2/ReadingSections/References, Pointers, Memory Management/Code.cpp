#include<iostream>

// References:
// Pretty much another name for a variable. It's an alias for that variable, which allows for
// efficient data management for big objects (used in Module 1 before as well)
// So the reference is not a duplicate, it just directs the logic to use the value variable
// References are: immutable => guaranteed safety.



// References vs. Pointers

// Both references and pointers manipulate variable memory,
// yet they tout unique benefits:

// References: Are stable and user-friendly. They initiate at declaration and
// provide a foolproof way to alias variables, ideal for parameter passing without
// the complexity of pointers.

// Pointers: Boast flexibility, able to point to various memory locations or 
// remain null until needed. With their power comes necessary caution, as improper
// handling can lead to pitfalls like memory leaks or dangling pointers.



int value = 10;
int& refValue = value; // Reference declaration

// Changing refValue changes value
// Changing value changes refValue

void modifyValue(int& input){
    input += 5;
}

void modifyValueNoRef(int input){
    input += 5;
}


// Final example explained in more depth:
void Example(){
    int value = 42; // stored at 0x1000 mem address
    int* ptr = &value; // ptr stroes address 0x1000
    int& refValue = value; // alias for value (same address)

    std::cout << *ptr; // dereference pointer to get 42
    std::cout << refValue; // direct access to get 42
}


int main(){
    int number1 = 20;
    int number2 = 20;
    modifyValue(number1);
    modifyValueNoRef(number2);
    // number = 25 now. If I didn't do the reference, number would stay at 20
    std::cout << "Reference function value: " << number1 << '\n';
    std::cout << "No reference function value: " << number2 << '\n';

    // Pointers:
    // They store the address of another variable, giving vast capabilities for
    // direct data manipulation.

    int number = 100;
    int* ptr = &number;

    std::cout << *ptr; // Outputs: 100
    *ptr += 50;
    std::cout << number; // Outputs: 150
    // We modify the value at the address that is given from number

    int arr[3] = {1,2,3};
    int* ptr1 = arr;
    std::cout << *ptr1; //Outputs: 1
    ptr1++;
    std::cout << *ptr1; // Outputs: 2
}