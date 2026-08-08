#include<iostream>

int main(){
    int value = 42;
    int* pointer = &value;
    int** pointerToPointer = &pointer; // pointer -> pointer -> value
    int& reference = value; // *reference does not work, since it's immutable once created
    int* const permanentPointer = &value;
    const int& permanentReference = value; // can't change value of reference

    std::cout << value << std::endl; // outputs the value
    std::cout << pointer << std::endl; // outputs the memory location where it's pointing at
    std::cout << *pointer << std::endl; // *pointer dereferences the pointer/gets the value at the address
    std::cout << &value << std::endl; // Gives the address of the value
    std::cout << pointerToPointer << std::endl; // this pointer's memory address
    std::cout << *pointerToPointer << std::endl; // memory address of the pointer I'm pointing at
    std::cout << **pointerToPointer << std::endl; // value of the pointer that the pointer is pointing at

    // All 3 do the same thing
    value++;
    reference++;
    (*pointer)++;

    // permanentPointer++; // can't modify the pointer if it's int* const pointer
    (*permanentPointer)++; // can't dereference the pointer, if it's const int* pointer

    std::cout << value << std::endl;
    std::cout << reference << std::endl;

    std::cout << ++pointer << std::endl; // increments memory address by 1


    // We use nullptr when we don't have a value we want to point at
    // Like initializing an int with 0
    int* null_pointer = nullptr;
    float* null_float = nullptr;
    // int& null_ref = nullptr; // not possible

    
    // check the pointer is not empty before dereferencing
    if (null_pointer != nullptr){
        std::cout << *null_pointer << std::endl;
    }

    return 0;
}