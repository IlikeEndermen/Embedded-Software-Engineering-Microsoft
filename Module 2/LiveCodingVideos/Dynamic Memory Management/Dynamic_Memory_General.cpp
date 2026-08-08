#include<iostream>

int& doNotDoThis(){
    int local_variable = 5;
    return local_variable; // Don't do this, undefined behavior

    // When we finish the code in the function, the local_variable is cleaned up
    // Meaning that if the function is called, it means that we use a local_variable
    // that does not exist at all.
}

int main(){
    int* allocated = new int{42}; // This is dynamic allocation in C++
    int* allocatedArr = new int[5]; // Dynamic alloc for arrays in C++
    
    delete allocated;
    delete allocated; // Double deletion => undefined behavior. Can crash the program bad
    delete[] allocatedArr;
    allocated = nullptr;
    allocatedArr = nullptr;

    // Memory leak:
    int* alloc = new int{15};

    // No deletion of the alloc pointer => memory leak.
    // When finished, this pointer never deallocates the memory it has

    // Use after free

    int* alloc1 = new int{60};

    delete alloc1;

    // Trying to access the already freed memory leads to undefined behavior.

    std::cout << *alloc1 << std::endl; 

    // Fix:

    int* alloc1 = new int{60};

    delete alloc1;
    alloc1 = nullptr;

    if(alloc1 != nullptr){ // Only access the pointer if you it's not empty, otherwise, ignore
        std::cout << *alloc1 << std::endl; 
    }

    return 0;
}